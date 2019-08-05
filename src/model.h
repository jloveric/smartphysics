#ifndef __MODEL_H
#define __MODEL_H

#include "definitions.h"

class LearnerIfc {
  public:
  LearnerIfc() {
  }

  virtual void Learn(const DataSet* testSet, const DataSet* trainSet) {
  }
  private:
  //Copy constructor is private so I don't have to deal with accidental copy!
  LearnerIfc( const LearnerIfc &obj){}
};

class LearnLinearLeastSquares : public LearnerIfc {
  public:
    
  private:
};

class ApplyModelIfc {
  public :
  ApplyModelIfc() {

  }

  virtual Data apply(Data* v) = 0;

  private :
  ApplyModelIfc( const ApplyModelIfc &obj){}
};

class ApplyLinearLeastSquares : public ApplyModelIfc {
  public :
  void setModel(LinearLeastSquaresModel* thisModel) {
    model=thisModel;
  }

  Data apply(Data* v) override {

  }
  private :
  ApplyLinearLeastSquares( const ApplyLinearLeastSquares &obj){}
  LinearLeastSquaresModel* model;
};

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

//Directly store the patterns it's seen for prediction to perform similarity, this one will be slow
class NearestNeighborModel : public MachineModelIfc {
  public :
  NearestNeighborModel( const NearestNeighborModel &obj) {
    this->examples = obj.getModelData();
  }

  DataSet getModelData() const {
    return examples;
  }

  private :

  //The examples that it got.  Output should be a weighted sum of
  //the examples for wave problems.
  DataSet examples;
};

//Neural Network - someday

#endif