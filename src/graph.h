#ifndef __GRAPH_H
#define __GRAPH_H

#include<memory>
#include<vector>
#include "definitions.h"
#include "Mesh.hh"
#include "MeshFactory.hh"

/**
 * This is the graph that the data sets on.  In the case of physics
 * this is often a grid, but could also be a time series or any other
 * type of data.
 */
class GraphIfc {
  public :
  GraphIfc() {

  }
  virtual ~GraphIfc() = default;
};

/**
 * Create a 1d grid with evenly spaced
 * elements.
 */
class Graph1D : public GraphIfc {
  public :

  /**
   * Set the size of the grid
   * @param elements is the number of elements in the grid
   */
  void setSize(int elements) {
    graph.resize(elements);
  }

  private :

  //The actual storage for the grid.
  std::vector<double> graph;
};

#endif