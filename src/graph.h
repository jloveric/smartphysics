#ifndef __GRAPH_H
#define __GRAPH_H

#include<vector>
#include "definitions.h"

/**
 * This is the graph that the data sets on.  In the case of physics
 * this is often a grid, but could also be a time series or any other
 * type of data.
 */
class GraphIfc {
  public :
  GraphIfc() {

  }
};

class Graph1D : public GraphIfc {
  public :
  void setSize(int elements) {
    graph.resize(elements);
  }

  private :

  std::vector<double> graph;
};

#endif