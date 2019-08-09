#ifndef __REGISTRY_H
#define __REGISTRY_H

#include "apply.h"
#include "learn.h"
#include "model.h"
#include "updater.h"
#include "maker.h"

//A pointer to the new object is stored in the maker::map, so something
//still points to the targets.
void registerModels() {
  new Maker<MachineModelIfc, NearestNeighborModel>("NearestNeighborModel");
}

void registerLearners() {
  new Maker<LearnerIfc, LearnNearestNeighbor>("LearnNearestNeighbor");
}

void registerApplys() {
  new Maker<ApplyModelIfc, ApplyNearestNeighbor>("ApplyNearestNeighbor");
}

void registerUpdaters() {
  new Maker<UpdaterIfc, UpdaterAdvectionEquation>("AdvectionUpdater");
  new Maker<UpdaterIfc, UpdaterNBody>("NBodyUpdater");
}

void registerObjects() {
  registerModels();
  registerLearners();
  registerApplys();
  registerUpdaters();
}

void unRegister() {
  clearMakerMap<MachineModelIfc>();
  clearMakerMap<LearnerIfc>();
  clearMakerMap<ApplyModelIfc>();
  clearMakerMap<UpdaterIfc>();
}

#endif