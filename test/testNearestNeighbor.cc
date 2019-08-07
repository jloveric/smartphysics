#define BOOST_TEST_MODULE testNearestNeighbor
#include <boost/test/unit_test.hpp>

#include "model.h"
#include "learn.h"
#include "apply.h"

BOOST_AUTO_TEST_CASE(TestChooseBinary) {
  std::vector<double> actualValues(4);
  
  auto learn = new LearnNearestNeighbor();


  
  
  /* double tMin = 0.0;
  double tMax = 0.5;

  actualValues[0] = 0.1;
  actualValues[1] = 0.1;
  actualValues[2] = 0.4;
  actualValues[3] = -0.4;*/

  

  BOOST_CHECK_EQUAL(2, 2);
}