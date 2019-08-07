#include "model.h"
#include "apply.h"
#include "learn.h"

#include <iostream>

#include "registry.h"

int main(void) {

  registerModels();
  registerLearners();
  registerApplys();
  
  std::cout << "this works.";
}