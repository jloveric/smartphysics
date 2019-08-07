#define BOOST_TEST_MODULE testRegistry

#include <iostream>
#include <boost/test/unit_test.hpp>

#include "registry.h"
#include "maker.h"

BOOST_AUTO_TEST_CASE(TestRegistry) {
  
  registerModels();
  registerLearners();
  registerApplys();
  
  LearnerIfc* learn1 = getNew<LearnerIfc>("LearnNearestNeighbor");
  BOOST_TEST(learn1!=nullptr);

  MachineModelIfc* machine1 = getNew<MachineModelIfc>("NearestNeighborModel");
  BOOST_TEST(machine1!=nullptr);

  ApplyModelIfc* apply1 = getNew<ApplyModelIfc>("ApplyNearestNeighbor");
  BOOST_TEST(apply1!=nullptr);  
}