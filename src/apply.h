#ifndef __APPLY_H
#define __APPLY_H

#include <boost/geometry/arithmetic/dot_product.hpp>
#include <iostream>
#include <cmath>

#include "model.h"
#include "definitions.h"
#include "util.h"

class ApplyModelIfc {
  public :
  ApplyModelIfc() {

  }

  virtual Data apply(Data& v) = 0;

  private :
  ApplyModelIfc( const ApplyModelIfc &obj){}
};

//Not finished
class ApplyLinearLeastSquares : public ApplyModelIfc {
  public :
  void setModel(LinearLeastSquaresModel* thisModel) {
    model=thisModel;
  }

  Data apply(Data& v) override {
    Data dummy;
    return dummy;
  }
  private :
  ApplyLinearLeastSquares( const ApplyLinearLeastSquares &obj){}
  LinearLeastSquaresModel* model;
};

class ApplyNearestNeighbor : public ApplyModelIfc {
  public :
  void setModel(NearestNeighborModel* thisModel) {
    model=thisModel;
  }

  Data apply(Data& v) override {
    //Run through the examples in the model and figure out which one
    //is closest.  Compute the cosine similarity, rescale the coefficients
    //and return the sum as the result.

    //check that the model is not null;
    if(!model) { 
      std::cout << "model has not been defined in ApplyNearestNeighbor or is null";
      throw;
    }

    auto features = model->getExampleFeatures();
    auto output = model->getExampleOutput();

    Data similarity;
    similarity.resize(features.size());
    
    //Not totally sure this is what I want.
    double absSum = 0;

    double vv = dotProduct(v,v);

    for(auto i=0; i<features.size(); i++) {
      similarity[i] = dotProduct(features[i], v)/vv;
      absSum += std::abs(similarity[i]); 
    }

    for(auto i=0; i<similarity.size(); i++) {
      similarity[i]=similarity[i]/absSum;
    }

    //The output is then a sum of the inputs
    //just return something to stop complaining
    return similarity;
  }

  private :
  ApplyNearestNeighbor( const ApplyNearestNeighbor &obj){}
  NearestNeighborModel* model;
};

#endif