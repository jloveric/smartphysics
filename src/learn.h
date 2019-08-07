#ifndef __LEARN_H
#define __LEARN_H

#include "definitions.h"
#include "model.h"

class LearnerIfc {
  public:
  LearnerIfc() {
  }

  virtual void learn(const DataSet& testSet, const DataSet& trainSet) {
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
    LearnNearestNeighbor() {model=nullptr;}

    void learn(const DataSet& features, const DataSet& output) override {
      
      //Fortunately learning for this model is the simplest possible!
      if(model) {
        model->setExamples(features, output);
      } else {
        std::cout << "you need to set the model\n";
      }
    }

    void setModel(NearestNeighborModel* tModel) {
      model = tModel;
    }

  private:

  //Should not be deleted
  NearestNeighborModel* model;
};

#endif