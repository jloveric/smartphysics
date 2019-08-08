#include "model.h"
#include "apply.h"
#include "learn.h"

#include <iostream>
#include <algorithm>

#include "registry.h"

int main(void) {

  registerModels();
  registerLearners();
  registerApplys();
  registerUpdaters();

  //
  auto graph = new Graph1D();
  auto updater = getNew<UpdaterIfc>("AdvectionUpdater");

  graph->setSize(100);
  updater->setGraph(graph);

  Data initialCondition;
  initialCondition.resize(100);
  
  for(auto i=0; i<initialCondition.size(); i++) {
    //sawteeth
    initialCondition[i]=i%10;
  }

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
  auto model = new NearestNeighborModel();
  auto learn = new LearnNearestNeighbor();
  auto apply = new ApplyNearestNeighbor();

  learn->setModel(model);
  apply->setModel(model);

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
  auto ans = apply->apply(test);

  std::for_each(ans.begin(), ans.end(), [] (auto element) {
    std::cout << " " << element;
  });
  std::cout << "\n";
  
}