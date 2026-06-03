// Copyright 2022 UNN-CS

#include <cstdint>
#include "tasks.h"
#include "circle.h"

double ropeGap(double sphereRadius, double extraLength) {
  Circle loop(sphereRadius);
  loop.setFerence(loop.getFerence() + extraLength);
  return loop.getRadius() - sphereRadius;
}

PoolEstimate estimatePool(double poolRadius, double pathWidth,
                          double pavementPricePerM2,
                          double railingPricePerM) {
  Circle water(poolRadius);
  Circle border(poolRadius + pathWidth);

  double pavementArea = border.getArea() - water.getArea();

  PoolEstimate estimate;
  estimate.pavementCost = pavementArea * pavementPricePerM2;
  estimate.railingCost = border.getFerence() * railingPricePerM;
  return estimate;
}
