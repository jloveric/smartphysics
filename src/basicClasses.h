#include "definitions.h"

class UpdaterIfc {
  public :
  UpdaterIfc() {
  }

  virtual void update(const GraphIfc* Graph, const DataSet* data) {
  }
};

class GraphIfc {
  public :
  GraphIfc() {

  }
};

class UpdaterNBody : public UpdaterIfc {
  public:

  UpdaterNBody() { 
  }

  void update(const GraphIfc* Graph, const DataSet* data) override {

  }
};

class UpdaterWaveEquation : public UpdaterIfc {
  public :
  UpdaterWaveEquation() {

  }

  void update(const GraphIfc* Graph, const DataSet* data) override {

  }

};