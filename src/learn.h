#ifndef __LEARN_H
#define __LEARN_H

#include "definitions.h"
#include "model.h"

class LearnerIfc {
  public:
  LearnerIfc() {
  }

  virtual void Learn(const DataSet& testSet, const DataSet& trainSet) {
  }
  private:
  //Copy constructor is private so I don't have to deal with accidental copy!
  LearnerIfc( const LearnerIfc &obj){}
};

class LearnLinearLeastSquares : public LearnerIfc {
  public:
    
  private:
};

class LearnNearestNeighbor : public LearnerIfc {
  public:
    void Learn(const DataSet& features, const DataSet& output) override {
      //Fortunately learning for this model is the simplest possible!
      model.setExamples(features, output);
    }

  private:

  NearestNeighborModel model;
};

#endif