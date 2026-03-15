
// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include <utility>

#include "include/circle.h"
#include "include/tasks.h"

double earthRopeTask() {
  double earthRadius = 6378.1 * 1000;
  double extra = 1.0;
  Circle circle(earthRadius);

  double radius = circle.getRadius();
  circle.setFerence(circle.getFerence() + extra);

  double newRadius = circle.getRadius();
  return newRadius - radius;
}

double poolWalkwayCostTask() {
  Circle pool(3.0);
  Circle poolWithFence(4.0);
  double result = 1000.0 * (poolWithFence.getArea() - pool.getArea());
  return std::round(result * 100.0) / 100.0;
}

double poolFenceCostTask() {
  Circle poolWithFence(4.0);
  double result = poolWithFence.getFerence() * 2000.0;
  return std::round(result * 100.0) / 100.0;
}

std::pair<double, double> poolWalkwayAndFenceCostTask() {
  return std::make_pair(poolWalkwayCostTask(), poolFenceCostTask());
}
