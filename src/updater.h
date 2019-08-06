#ifndef __UPDATER_IFC
#define __UPDATER_IFC

#include <algorithm>
#include "graph.h"


template <class GRAPH>
class UpdaterIfc {
  public :
  UpdaterIfc() {
  }

  virtual Data update(const GRAPH& Graph, const DataSet& data) {
  }
};

class UpdaterNBody : public UpdaterIfc<Graph1D> {
  public:

  UpdaterNBody() { 
  }

  Data update(const Graph1D& Graph, const DataSet& data) override {

  }
};

class UpdaterAdvectionEquation : public UpdaterIfc<Graph1D> {
  public :
  UpdaterAdvectionEquation() {
  }

  Data update(const Graph1D& Graph, const DataSet& data) override {
    //OK, I'm gonna cheat for demo purposes and just shift the data
    Data head;
    head.resize(data[0].size());
    auto tSize = head.size();

    //rotate the array - yes, periodic boundary conditions shift by one unit
    for(auto i=0; i < tSize; i++) {
      head[(i+1)%tSize]=data[0][i];
    }

    return head;
  }

};

#endif