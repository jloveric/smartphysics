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
  ApplyNearestNeighbor(){}

  void setModel(NearestNeighborModel* thisModel) {
    model=thisModel;
  }

  Data apply(Data& v) override {
    //Eventually we'll use inverse distance weighting, though in this case we'll use
    //genuine nearest neighbor based on cosine distance

    if(!model) { 
      std::cout << "model has not been defined in ApplyNearestNeighbor or is null";
      throw;
    }

    auto features = model->getExampleFeatures();
    auto output = model->getExampleOutput();

    if(!features.size()) {
      std::cout << "There are no features!\n";
      throw;
    }

    Data similarity;
    similarity.resize(features.size());

    double vv = dotProduct(v,v);

    double closestValue = 1.0-dotProduct(features[0], v)/vv;
    int closestIndex = 0;

    for(auto i=1; i<features.size(); i++) {
      auto val = 1.0-dotProduct(features[i], v)/vv;
      if( std::abs(val)<std::abs(closestValue) ) {
        closestValue = val;
        closestIndex = i;
      }
    }

    //The output is then a sum of the inputs
    //just return something to stop complaining
    //TODO: This should actually be multiplied by the sign of closestValue!
    return output[closestIndex];
  }

  private :
  ApplyNearestNeighbor( const ApplyNearestNeighbor &obj){}
  NearestNeighborModel* model;
};

#endif