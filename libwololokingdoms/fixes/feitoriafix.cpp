#include "feitoriafix.h"
#include "wololo/datPatch.h"

namespace wololo {

void feitoriaPatch(genie::DatFile* aocDat) {
  float const feitoriaCooldown = 1;
  float const woodAdded = 0.8;
  float const foodAdded = 0.8;
  float const goldAdded = 0.45;
  float const stoneAdded = 0.25;

  int16_t const feitoriaId = 1021;          // 960
  int16_t const woodAnnexId = 1391;         // 957
  int16_t const foodAnnexId = 1392;         // 956
  int16_t const goldAnnexId = 1393;         // 959
  int16_t const stoneAnnexId = 1394;        // 958
  int16_t const woodTrickleId = 1395;       // 952
  int16_t const foodTrickleId = 1396;       // 951
  int16_t const goldTrickleId = 1397;       // 954
  int16_t const stoneTrickleId = 1398;      // 954
  int16_t const feitoriaDeadStackId = 1399; // 955
  int16_t const feitoriaStackId = 1400;     // 949

  for (size_t civIndex = 0; civIndex < aocDat->Civs.size(); civIndex++) {
    aocDat->Civs[civIndex].Units[feitoriaStackId] =
        aocDat->Civs[civIndex].Units[feitoriaId];
    aocDat->Civs[civIndex].Units[woodAnnexId] =
        aocDat->Civs[civIndex].Units[feitoriaId];
    aocDat->Civs[civIndex].Units[foodAnnexId] =
        aocDat->Civs[civIndex].Units[feitoriaId];
    aocDat->Civs[civIndex].Units[goldAnnexId] =
        aocDat->Civs[civIndex].Units[feitoriaId];
    aocDat->Civs[civIndex].Units[stoneAnnexId] =
        aocDat->Civs[civIndex].Units[feitoriaId];
    aocDat->Civs[civIndex].Units[woodTrickleId] =
        aocDat->Civs[civIndex].Units[feitoriaId];
    aocDat->Civs[civIndex].Units[foodTrickleId] =
        aocDat->Civs[civIndex].Units[feitoriaId];
    aocDat->Civs[civIndex].Units[goldTrickleId] =
        aocDat->Civs[civIndex].Units[feitoriaId];
    aocDat->Civs[civIndex].Units[stoneTrickleId] =
        aocDat->Civs[civIndex].Units[feitoriaId];

    aocDat->Civs[civIndex].Units[feitoriaStackId].Name = "Feitoria";
    aocDat->Civs[civIndex].Units[woodAnnexId].Name = "AA-A Wood Annex";
    aocDat->Civs[civIndex].Units[foodAnnexId].Name = "AA-A Food Annex";
    aocDat->Civs[civIndex].Units[goldAnnexId].Name = "AA-A Stone Annex";
    aocDat->Civs[civIndex].Units[stoneAnnexId].Name = "AA-A gold Annex";
    aocDat->Civs[civIndex].Units[woodTrickleId].Name = "Wood Trickle";
    aocDat->Civs[civIndex].Units[foodTrickleId].Name = "Food Trickle";
    aocDat->Civs[civIndex].Units[goldTrickleId].Name = "Gold Trickle";
    aocDat->Civs[civIndex].Units[stoneTrickleId].Name = "Stone Trickle";

    aocDat->Civs[civIndex].Units[feitoriaId].Building.StackUnitID =
        feitoriaStackId;
    aocDat->Civs[civIndex].Units[feitoriaId].Building.DisappearsWhenBuilt = 1;
    aocDat->Civs[civIndex].Units[feitoriaId].HideInEditor = 1;

    aocDat->Civs[civIndex].Units[feitoriaStackId].DyingGraphic = -1;
    aocDat->Civs[civIndex].Units[feitoriaStackId].UndeadGraphic = -1;
    aocDat->Civs[civIndex].Units[feitoriaStackId].DeadUnitID =
        feitoriaDeadStackId;
    aocDat->Civs[civIndex].Units[feitoriaStackId].OcclusionMode = 6;
    aocDat->Civs[civIndex].Units[feitoriaStackId].Creatable.TrainLocationID = 0;
    aocDat->Civs[civIndex].Units[feitoriaStackId].ResourceStorages[2].Type = -1;
    aocDat->Civs[civIndex].Units[feitoriaStackId].ResourceStorages[2].Amount =
        0;
    aocDat->Civs[civIndex].Units[feitoriaStackId].ResourceStorages[2].Paid = 0;
    aocDat->Civs[civIndex].Units[feitoriaStackId].Building.HeadUnit =
        feitoriaId;
    aocDat->Civs[civIndex].Units[feitoriaStackId].Building.Annexes[0].UnitID =
        woodAnnexId;
    aocDat->Civs[civIndex].Units[feitoriaStackId].Building.Annexes[1].UnitID =
        foodAnnexId;
    aocDat->Civs[civIndex].Units[feitoriaStackId].Building.Annexes[2].UnitID =
        goldAnnexId;
    aocDat->Civs[civIndex].Units[feitoriaStackId].Building.Annexes[3].UnitID =
        stoneAnnexId;
    for (int i = 0; i < 4; i++) {
      aocDat->Civs[civIndex]
          .Units[feitoriaStackId]
          .Building.Annexes[i]
          .Misplacement = {0.5, 0.5};
    }

    // dead unit
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].Type = 80;
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].Class = 3;
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].DyingGraphic = 42;
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].UndeadGraphic = -1;
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].HitPoints = 0;
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].ResourceDecay = 1;
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].Enabled = 0;
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].HideInEditor = 1;
    aocDat->Civs[civIndex].Units[feitoriaDeadStackId].DeadUnitID =
        148; // Rubble 8 x 8

    // CRASH -> INVALID NAMES for new units ?

    // annex
    genie::Unit annex;
    annex.Type = 80;
    annex.Class = 3;
    annex.HitPoints = -1;
    annex.HideInEditor = 1;
    // wood
    annex.DeadUnitID = woodTrickleId;
    aocDat->Civs[civIndex].Units[woodAnnexId] = annex;
    // food
    annex.DeadUnitID = foodTrickleId;
    aocDat->Civs[civIndex].Units[foodAnnexId] = annex;
    // gold
    annex.DeadUnitID = goldTrickleId;
    aocDat->Civs[civIndex].Units[goldAnnexId] = annex;
    // stone
    annex.DeadUnitID = stoneTrickleId;
    aocDat->Civs[civIndex].Units[stoneAnnexId] = annex;

    // trickle
    genie::Unit trickle;
    trickle.Type = 30;
    trickle.Class = 11;
    trickle.HitPoints = 0;
    trickle.ResourceDecay = 1;
    trickle.CanBeBuiltOn = 1;
    trickle.HideInEditor = 1;
    trickle.ResourceStorages[0].Type = 12; // Corpse Decay Time
    trickle.ResourceStorages[0].Amount =
        feitoriaCooldown; // time it takes to generate ressources again
    trickle.ResourceStorages[0].Paid = 0; // Decayable ressource
    trickle.ResourceStorages[1].Paid = 1; // Stored after death also
    // wood
    trickle.ResourceStorages[1].Type = 0; // Wood storage
    trickle.ResourceStorages[1].Amount = woodAdded;
    trickle.DeadUnitID = woodTrickleId;
    aocDat->Civs[civIndex].Units[woodTrickleId] = trickle;
    // food
    trickle.ResourceStorages[1].Type = 1; // Food storage
    trickle.ResourceStorages[1].Amount = foodAdded;
    trickle.DeadUnitID = foodTrickleId;
    aocDat->Civs[civIndex].Units[foodTrickleId] = trickle;
    // gold
    trickle.ResourceStorages[1].Type = 3; // Gold storage
    trickle.ResourceStorages[1].Amount = goldAdded;
    trickle.DeadUnitID = goldTrickleId;
    aocDat->Civs[civIndex].Units[goldTrickleId] = trickle;
    // stone
    trickle.ResourceStorages[1].Type = 2; // Stone storage
    trickle.ResourceStorages[1].Amount = stoneAdded;
    trickle.DeadUnitID = stoneTrickleId;
    aocDat->Civs[civIndex].Units[stoneTrickleId] = trickle;

    // Fix IDs
    aocDat->Civs[civIndex].Units[feitoriaStackId].ID = feitoriaStackId;
    aocDat->Civs[civIndex].Units[woodAnnexId].ID = woodAnnexId;
    aocDat->Civs[civIndex].Units[foodAnnexId].ID = foodAnnexId;
    aocDat->Civs[civIndex].Units[goldAnnexId].ID = goldAnnexId;
    aocDat->Civs[civIndex].Units[stoneAnnexId].ID = stoneAnnexId;
    aocDat->Civs[civIndex].Units[woodTrickleId].ID = woodTrickleId;
    aocDat->Civs[civIndex].Units[foodTrickleId].ID = foodTrickleId;
    aocDat->Civs[civIndex].Units[goldTrickleId].ID = goldTrickleId;
    aocDat->Civs[civIndex].Units[stoneTrickleId].ID = stoneTrickleId;

    aocDat->Civs[civIndex].Units[feitoriaStackId].CopyID = feitoriaStackId;
    aocDat->Civs[civIndex].Units[woodAnnexId].CopyID = woodAnnexId;
    aocDat->Civs[civIndex].Units[foodAnnexId].CopyID = foodAnnexId;
    aocDat->Civs[civIndex].Units[goldAnnexId].CopyID = goldAnnexId;
    aocDat->Civs[civIndex].Units[stoneAnnexId].CopyID = stoneAnnexId;
    aocDat->Civs[civIndex].Units[woodTrickleId].CopyID = woodTrickleId;
    aocDat->Civs[civIndex].Units[foodTrickleId].CopyID = foodTrickleId;
    aocDat->Civs[civIndex].Units[goldTrickleId].CopyID = goldTrickleId;
    aocDat->Civs[civIndex].Units[stoneTrickleId].CopyID = stoneTrickleId;

    aocDat->Civs[civIndex].Units[feitoriaStackId].BaseID = feitoriaStackId;
    aocDat->Civs[civIndex].Units[woodAnnexId].BaseID = woodAnnexId;
    aocDat->Civs[civIndex].Units[foodAnnexId].BaseID = foodAnnexId;
    aocDat->Civs[civIndex].Units[goldAnnexId].BaseID = goldAnnexId;
    aocDat->Civs[civIndex].Units[stoneAnnexId].BaseID = stoneAnnexId;
    aocDat->Civs[civIndex].Units[woodTrickleId].BaseID = woodTrickleId;
    aocDat->Civs[civIndex].Units[foodTrickleId].BaseID = foodTrickleId;
    aocDat->Civs[civIndex].Units[goldTrickleId].BaseID = goldTrickleId;
    aocDat->Civs[civIndex].Units[stoneTrickleId].BaseID = stoneTrickleId;
  }
}

DatPatch feitoriaFix = {&feitoriaPatch, "Feitoria fix"};

} // namespace wololo
