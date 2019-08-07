#ifndef __UPDATER_H
#define __UPDATER_H

#include <algorithm>
#include "graph.h"

/**
 * The updater updates data that is attached to a graph.  The graph identifies
 * relationships between the provided data.  In the cases of physics, this
 * might be distance between graph nodes (or time between nodes), etc...
 */
template <class GRAPH>
class UpdaterIfc {
  public :
  UpdaterIfc() {
  }

  void setGraph(GRAPH* tGraph) {
    graph = tGraph;
  }

  virtual Data update(const DataSet& data)=0;

  private:

  GRAPH* graph;
};

/**
 * Brute force NBody solver
 */
class UpdaterNBody : public UpdaterIfc<Graph1D> {
  public:

  UpdaterNBody() { 
  }

  Data update(const DataSet& data) override {

  }
};

/**
 * Advection equation solver
 */
class UpdaterAdvectionEquation : public UpdaterIfc<Graph1D> {
  public :
  UpdaterAdvectionEquation() {
  }

  Data update(const DataSet& data) override {
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