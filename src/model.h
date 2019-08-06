#ifndef __MODEL_H
#define __MODEL_H

#include "definitions.h"

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

//Directly store the patterns it's seen for prediction to perform similarity, this one will be slow, but it should
//work.
class NearestNeighborModel : public MachineModelIfc {
  public :
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