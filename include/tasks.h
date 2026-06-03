// Copyright 2022 UNN-CS

#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolEstimate {
  double pavementCost;
  double railingCost;
  double total() const { return pavementCost + railingCost; }
};

double ropeGap(double sphereRadius, double extraLength);

PoolEstimate estimatePool(double poolRadius, double pathWidth,
                          double pavementPricePerM2,
                          double railingPricePerM);

#endif  // INCLUDE_TASKS_H_
