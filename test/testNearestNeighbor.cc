#define BOOST_TEST_MODULE testNearestNeighbor
#include <boost/test/unit_test.hpp>
#include <iostream>

#include "definitions.h"
#include "model.h"
#include "learn.h"
#include "apply.h"

BOOST_AUTO_TEST_CASE(TestNearestNeighbor) {
  
  auto model = new NearestNeighborModel();
  auto learn = new LearnNearestNeighbor();
  auto apply = new ApplyNearestNeighbor();

  learn->setModel(model);
  apply->setModel(model);

  DataSet key;
  key.push_back({1,2,3});
  key.push_back({1,1,1});

  DataSet value;
  value.push_back({3,4,5});
  value.push_back({6,7,8});

  learn->learn(key, value);

  Data test({1,1,1});
  
  //Just check that the correct keys are returned for the exact values
  auto ans = apply->apply(test);
  BOOST_CHECK_EQUAL(ans[0], 6);
  BOOST_CHECK_EQUAL(ans[1], 7);
  BOOST_CHECK_EQUAL(ans[2], 8);

  Data test2({1,2,3});
  ans = apply->apply(test2);
  BOOST_CHECK_EQUAL(ans[0], 3);
  BOOST_CHECK_EQUAL(ans[1], 4);
  BOOST_CHECK_EQUAL(ans[2], 5);

  //Check an intermediate value
  Data test3({1, 1.5, 2.0});
  ans = apply->apply(test3);
  BOOST_CHECK_EQUAL(ans[0], 6);
  BOOST_CHECK_EQUAL(ans[1], 7);
  BOOST_CHECK_EQUAL(ans[2], 8);
  std::cout << "ans " << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}