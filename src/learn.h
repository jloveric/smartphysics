#ifndef __LEARN_H
#define __LEARN_H

#include<memory>

#include "definitions.h"
#include "model.h"

/**
 * Class which learns (creates) a model based on example data.
 */
class LearnerIfc {
  public:
  LearnerIfc() {
  }

  /*
    * To create a model we just store the features and values (outputs)
    * @param features are the features vectors of the data
    * @param output is the target values (set of vectors) given a specific set of features...
    * The desired output of the model in given the input "features".
    */
  virtual void learn(const DataSet& features, const DataSet& output) {
  }

  private:
  //Copy constructor is private so I don't have to deal with accidental copy!
  LearnerIfc( const LearnerIfc &obj){}
};

class LearnLinearLeastSquares : public LearnerIfc {
  public:
    
  private:
};

/**
 * Use the nearest neighbor approach to learning.  This approach is 1 shot, but is memory
 * intensive and computational expensive to evaluate.  It's also one of the simplest
 * approaches and that is why we use it.
 */
class LearnNearestNeighbor : public LearnerIfc {
  public:
    LearnNearestNeighbor() {model=nullptr;}

    /*
    * To create a nearest neighbor model we just store the features and values (outputs)
    */
    void learn(const DataSet& features, const DataSet& output) override {
      
      //Fortunately learning for this model is the simplest possible!
      if(model) {
        model->setExamples(features, output);
      } else {
        std::cout << "you need to set the model\n";
      }
    }

    void setModel(std::shared_ptr<NearestNeighborModel> tModel) {
      model = tModel;
    }

  private:

  std::shared_ptr<NearestNeighborModel> model;
};

#endif