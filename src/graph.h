#ifndef __GRAPH_H
#define __GRAPH_H

#include<memory>
#include<vector>
#include "definitions.h"
#include "mpi.h"
#include "Mesh.hh"
#include "MeshFactory.hh"

using namespace Jali;

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

class GraphBase : public GraphIfc {
  public :
  GraphBase(MPI_Comm& a) : GraphIfc() {
    comm = &a;
  }

  MPI_Comm& getMpiComm() {
    return *comm;
  }

  private :

  MPI_Comm* comm; 
};

/**
 * Create a 1d grid with evenly spaced
 * elements.
 */
class Graph1D : public GraphBase {
  public :

  //for backwards compatibility
  Graph1D(MPI_Comm& a) : GraphBase(a) {

  }

  /**
   * Set the size of the grid
   * @param elements is the number of elements in the grid
   */
  void setSize(int elements) {
    graph.resize(elements);
  }

  //This will replace the above method
  void initMesh(double start, double end, int cells) {
    MeshFactory meshFactory(getMpiComm());
    meshFactory.framework(MSTK);

    // Create a 3D mesh from (0.0,0.0,0.0) to (1.0,1.0,1.0)
    // with 3, 3 and 3 elements in the X, Y and Z directions. 
    // Request faces, edges but not wedges or corners
    meshFactory.included_entities({Entity_kind::EDGE, Entity_kind::FACE, Entity_kind::CELL});

    mesh = meshFactory(0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 3, 3, 3);
    //mesh = meshFactory(start, end, cells);
  }

  private :

  //The actual storage for the grid.
  std::vector<double> graph;
  std::shared_ptr<Mesh> mesh;  // Pointer to a mesh object
};

#endif