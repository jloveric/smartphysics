#ifndef __UPDATER_H
#define __UPDATER_H

#include <algorithm>
#include "graph.h"

/**
 * The updater updates data that is attached to a graph.  The graph identifies
 * relationships between the provided data.  In the cases of physics, this
 * might be distance between graph nodes (or time between nodes), etc...
 */
class UpdaterIfc {
  public :
  UpdaterIfc() {
  }

  /**
   * Set the graph that will be used by the updater
   * @param tGraph is a pointer to the graph
   */
  virtual void setGraph(std::shared_ptr<GraphIfc> tGraph) = 0;

  /**
   * Update with a given data set - this will contain
   * at least the last state, but may also contain states before
   * that.  
   * @param data series of previous data sets
   * @return the next state
   */
  virtual Data update(const DataSet& data) = 0;

  private:

};

/**
 * Base class adds template and basic implementation
 */
template <class GRAPH>
class UpdaterBase : public UpdaterIfc {
  public :
  UpdaterBase() {
  }

  virtual void setGraph(std::shared_ptr<GraphIfc> tGraph) override {
    graph = std::dynamic_pointer_cast<GRAPH>(tGraph);
  }

  virtual Data update(const DataSet& data)=0;

  protected:

  std::shared_ptr<GRAPH> graph;
};

/**
 * Brute force NBody solver
 */
class UpdaterNBody : public UpdaterBase<Graph1D> {
  public:

  UpdaterNBody() { 
  }

  Data update(const DataSet& data) override {
    //some dummy data for now
    Data temp;
    return temp;
  }
};

/**
 * Advection equation solver
 */
class UpdaterAdvectionEquation : public UpdaterBase<Graph1D> {
  public :
  UpdaterAdvectionEquation() {
  }

  Data update(const DataSet& data) override {

    //lets print out the graph to make sure things are really working


    //OK, I'm gonna cheat for demo purposes and just shift the data
    Data last;
    last.resize(data.back().size());
    auto tSize = last.size();

    //rotate the array - yes, periodic boundary conditions shift by one unit
    //this is perfect advection.
    for(auto i=0; i < tSize; i++) {
      last[(i+1)%tSize]=data[0][i];
    }

    return last;
  }

};

#endif