#ifndef __GRAPH_H
#define __GRAPH_H

#include<vector>
#include "definitions.h"

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
}

#endif