#define BOOST_TEST_MODULE testNearestNeighbor
#include <boost/test/unit_test.hpp>

#include "model.h"
#include "learn.h"
#include "apply.h"

BOOST_AUTO_TEST_CASE(TestChooseBinary) {
  std::vector<double> actualValues(4);
  
  auto learn = new LearnNearestNeighbor();

  

  BOOST_CHECK_EQUAL(2, 2);
}