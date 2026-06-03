// Copyright 2022 UNN-CS

#include <gtest/gtest.h>

#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kEps = 1e-9;
constexpr double kPi = Circle::kPi;
}  // namespace

TEST(CircleCtor, KeepsRadius) {
  Circle c(2.0);
  EXPECT_NEAR(c.getRadius(), 2.0, kEps);
}

TEST(CircleCtor, ComputesFerence) {
  Circle c(2.0);
  EXPECT_NEAR(c.getFerence(), 4.0 * kPi, kEps);
}

TEST(CircleCtor, ComputesArea) {
  Circle c(2.0);
  EXPECT_NEAR(c.getArea(), 4.0 * kPi, kEps);
}

TEST(CircleCtor, ZeroRadiusGivesZeros) {
  Circle c(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleCtor, RejectsNegative) {
  EXPECT_THROW(Circle(-2.0), std::invalid_argument);
}

TEST(SetRadius, UpdatesRadius) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_NEAR(c.getRadius(), 3.0, kEps);
}

TEST(SetRadius, UpdatesFerence) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_NEAR(c.getFerence(), 6.0 * kPi, kEps);
}

TEST(SetRadius, UpdatesArea) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_NEAR(c.getArea(), 9.0 * kPi, kEps);
}

TEST(SetRadius, RejectsNegative) {
  Circle c(1.0);
  EXPECT_THROW(c.setRadius(-0.5), std::invalid_argument);
}

// ---- setFerence ----
TEST(SetFerence, UpdatesFerence) {
  Circle c(1.0);
  c.setFerence(10.0);
  EXPECT_NEAR(c.getFerence(), 10.0, kEps);
}

TEST(SetFerence, RecoversRadius) {
  Circle c(1.0);
  c.setFerence(2.0 * kPi);
  EXPECT_NEAR(c.getRadius(), 1.0, kEps);
}

TEST(SetFerence, RecomputesArea) {
  Circle c(1.0);
  c.setFerence(2.0 * kPi * 5.0);
  EXPECT_NEAR(c.getArea(), 25.0 * kPi, kEps);
}

TEST(SetFerence, RejectsNegative) {
  Circle c(1.0);
  EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(SetArea, UpdatesArea) {
  Circle c(1.0);
  c.setArea(50.0);
  EXPECT_NEAR(c.getArea(), 50.0, kEps);
}

TEST(SetArea, RecoversRadius) {
  Circle c(1.0);
  c.setArea(kPi * 16.0);
  EXPECT_NEAR(c.getRadius(), 4.0, kEps);
}

TEST(SetArea, RecomputesFerence) {
  Circle c(1.0);
  c.setArea(kPi * 16.0);
  EXPECT_NEAR(c.getFerence(), 8.0 * kPi, kEps);
}

TEST(SetArea, RejectsNegative) {
  Circle c(1.0);
  EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
}

TEST(CircleInvariant, FerenceRoundTrip) {
  Circle c(7.25);
  Circle other(1.0);
  other.setFerence(c.getFerence());
  EXPECT_NEAR(other.getRadius(), 7.25, kEps);
}

TEST(CircleInvariant, AreaRoundTrip) {
  Circle c(7.25);
  Circle other(1.0);
  other.setArea(c.getArea());
  EXPECT_NEAR(other.getRadius(), 7.25, kEps);
}

TEST(RopeTask, GapForOneMeter) {
  EXPECT_NEAR(ropeGap(6378.1 * 1000.0, 1.0), 1.0 / (2.0 * kPi), kEps);
}

TEST(RopeTask, GapIndependentOfRadius) {
  double big = ropeGap(6378.1 * 1000.0, 1.0);
  double small = ropeGap(5.0, 1.0);
  EXPECT_NEAR(big, small, kEps);
}

TEST(PoolTask, PavementCost) {
  PoolEstimate e = estimatePool(3.0, 1.0, 1000.0, 2000.0);
  EXPECT_NEAR(e.pavementCost, 21991.148575, 1e-4);
}

TEST(PoolTask, RailingCost) {
  PoolEstimate e = estimatePool(3.0, 1.0, 1000.0, 2000.0);
  EXPECT_NEAR(e.railingCost, 50265.482457, 1e-4);
}

TEST(PoolTask, TotalCost) {
  PoolEstimate e = estimatePool(3.0, 1.0, 1000.0, 2000.0);
  EXPECT_NEAR(e.total(), 72256.631032, 1e-4);
}
