#ifndef __UPDATER_IFC
#define __UPDATER_IFC

#include <algorithm>
#include "graph.h"


template <class GRAPH>
class UpdaterIfc {
  public :
  UpdaterIfc() {
  }

  virtual void update(const GRAPH* Graph, const DataSet* data) {
  }
};

class UpdaterNBody : public UpdaterIfc<Graph1D> {
  public:

  UpdaterNBody() { 
  }

  void update(const Graph1D* Graph, const DataSet* data) override {

  }
};


class UpdaterAdvectionEquation : public UpdaterIfc<Graph1D> {
  public :
  UpdaterAdvectionEquation() {

  }

  void update(const Graph1D* Graph, const DataSet* data) override {
    //OK, I'm gonna cheat for demo purposes and just shift the data
    auto head = data[0];

    
  }

};

#endif