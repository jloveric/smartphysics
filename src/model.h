#ifndef __MODEL_H
#define __MODEL_H

#include "definitions.h"

class MachineModelIfc {
  public :
  MachineModelIfc() {

  }
};

//Try and fit a line to the data - very bad for this problem so may need a kernel method
class LinearLeastSquaresModel : public MachineModelIfc {
  public :
  
  LinearLeastSquaresModel( const LinearLeastSquaresModel &obj) {
    this->coefficients = obj.getModelData();
  }
  
  Data getModelData() const {
    return coefficients;
  }

  private:

  //All we need is a specified set of coefficients
  Data coefficients;
};

/**
 * Nearest neighbor model is about the simplest to implement but expensive to evaluate and store (in this case).
 */
class NearestNeighborModel : public MachineModelIfc {
  public :

  NearestNeighborModel() {
  }

  NearestNeighborModel(const NearestNeighborModel &obj) {
    this->features = obj.getExampleFeatures();
    this->output = obj.getExampleOutput();
  }

  DataSet getExampleFeatures() const {
    return features;
  }

  DataSet getExampleOutput() const {
    return output;
  }

  void setExamples(const DataSet& feat, const DataSet& out) {
    this->features = feat;
    this->output = out;
  }

  private :

  //X is the input or the features
  DataSet features;

  //Y is the expected result in the future (the output of the model)
  DataSet output;
};

#endif