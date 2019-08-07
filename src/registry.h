#ifndef __REGISTRY_H
#define __REGISTRY_H

#include "apply.h"
#include "learn.h"
#include "model.h"
#include "maker.h"

void registerModels() {
  new Maker<MachineModelIfc, NearestNeighborModel>("NearestNeighborModel");
}

void registerLearners() {
  new Maker<LearnerIfc, LearnNearestNeighbor>("LearnNearestNeighbor");
}

void registerApplys() {
  new Maker<ApplyModelIfc, ApplyNearestNeighbor>("ApplyNearestNeighbor");
}

#endif