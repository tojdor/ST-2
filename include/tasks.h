
// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_
#include <utility>
#include "include/circle.h"

double earthRopeTask();
double poolWalkwayCostTask();
double poolFenceCostTask();
std::pair<double, double> poolWalkwayAndFenceCostTask();

#endif  // INCLUDE_TASKS_H_
