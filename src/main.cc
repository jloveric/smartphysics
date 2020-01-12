#include <memory>

#include "model.h"
#include "apply.h"
#include "learn.h"

#include <iostream>
#include <algorithm>

#include "registry.h"
#include "mpi.h"

/**
 * Steps for creating a model based on a physics simulation.  In this
 * case it's about as simple as can be.
 */
int main(int argc, char* argv[]) {

  MPI_Init(&argc, &argv);
  MPI_Comm comm = MPI_COMM_WORLD;

  registerObjects();

  //Create the grid
  auto graph = std::make_shared<Graph1D>(comm);

  //Create the updater for the advection equation
  auto updater = getNew<UpdaterIfc>("AdvectionUpdater");

  //Size the grid
  graph->setSize(100);

  //Assign the grid to the updater
  updater->setGraph(graph);

  //Create and set some initial conditions, create periodic
  //sawteeth with period 10 units
  Data initialCondition;
  initialCondition.resize(100);
  
  for(auto i=0; i<initialCondition.size(); i++) {
    //sawteeth
    initialCondition[i]=i%10;
  }

  //Create some training data by running the physics simulation
  //and recording all the timesteps.
  DataSet ds, target;
  ds.push_back(initialCondition);

  //Update for a few steps.
  for(auto i=0; i<100; i++) {
    auto final  = updater->update(ds);
    ds.push_back(final);
  }

  //Now that we've run the simulation and stored all the result, create the
  //training set.  The target set here is just one time step into the future.
  //So the input and output just differ by a shift of one step
  target = ds;
  target.erase(target.begin());
  ds.erase(ds.end());

  //Now train with a very simple approach
  auto model = std::make_shared<NearestNeighborModel>();
  auto learn = std::make_shared<LearnNearestNeighbor>();
  auto apply = std::make_shared<ApplyNearestNeighbor>();

  learn->setModel(model);
  learn->learn(ds, target);

  Data test;
  test.resize(100);
  //Create a test set - longer teeth
  for(auto i=0; i<test.size(); i++) {
    //sawteeth
    test[i]=i%20;
  }

  //This model won't be able to get the correct solution
  //for this problem, but it will try.  Next up, better models
  //and better physics.
  apply->setModel(model);
  auto ans = apply->apply(test);

  std::for_each(ans.begin(), ans.end(), [] (auto element) {
    std::cout << " " << element;
  });
  std::cout << "\n";

  MPI_Finalize();
}