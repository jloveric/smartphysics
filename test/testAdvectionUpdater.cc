#define BOOST_TEST_MODULE testAdvectionUpdater
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <cmath>

#include "definitions.h"
#include "updater.h"
#include "graph.h"

BOOST_AUTO_TEST_CASE(TestAdvectionUpdater) {
  
  auto graph = new Graph1D();
  auto updater = new UpdaterAdvectionEquation();
  
  graph->setSize(100);
  updater->setGraph(graph);

  Data d, f;
  d.resize(10);
  f.resize(10);

  for(auto i=0; i<d.size(); i++) {
    //make some periodic bumps
    d[i]=i%2;
    f[i]=std::abs((i-1)%2);
  }

  DataSet ds;
  ds.push_back(d);

  //Update for a few steps.
  auto final  = updater->update(ds);

  for(int i=0; i<10; i++) {
    BOOST_CHECK_EQUAL(final[i], f[i]);
    std::cout << "final " << d[i] << " " << f[i] << " " << f[i] << "\n";
  }
}