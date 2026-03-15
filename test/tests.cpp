#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

constexpr auto EPS = 1e-9;


TEST(st2, CircleConstructWithNegativeRadius) {
  EXPECT_THROW({
    Circle c(-1.0);
  }, std::invalid_argument);
}

TEST(st2, CircleSetNegativeRadius) {
  Circle c(1.0);
  EXPECT_THROW({
    c.setRadius(-1.0);
  }, std::invalid_argument);
}

TEST(st2, CircleSetNegativeFerence) {
  Circle c(1.0);
  EXPECT_THROW({
    c.setFerence(-1.0);
  }, std::invalid_argument);
}

TEST(st2, CircleSetNegativeArea) {
  Circle c(1.0);
  EXPECT_THROW({
    c.setArea(-1.0);
  }, std::invalid_argument);
}

TEST(st2, CircleConstructWithZeroRadius) {
  Circle c(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, EPS);
}

TEST(st2, CircleConstructWithZeroFerence) {
  Circle c(0.0);
  EXPECT_NEAR(c.getFerence(), 0.0, EPS);
}

TEST(st2, CircleConstructWithZeroArea) {
  Circle c(0.0);
  EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(st2, CircleConstructSetCorrectRadius) {
  Circle c(2.0);
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
}

TEST(st2, CircleConstructCalcCorrectFerence) {
  Circle c(2.0);
  EXPECT_NEAR(c.getFerence(), 4 * PI, EPS);
}

TEST(st2, CircleConstructCalcCorrectArea) {
  Circle c(2.0);
  EXPECT_NEAR(c.getArea(), 4 * PI, EPS);
}

TEST(st2, CircleSetterRadiusSetCorrectRadius) {
  Circle c(1.0);
  c.setRadius(2.0);
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
}

TEST(st2, CircleSetterRadiusCalcCorrectFerence) {
  Circle c(1.0);
  c.setRadius(2.0);
  EXPECT_NEAR(c.getFerence(), 4 * PI, EPS);
}

TEST(st2, CircleSetterRadiusCalcCorrectArea) {
  Circle c(1.0);
  c.setRadius(2.0);
  EXPECT_NEAR(c.getArea(), 4 * PI, EPS);
}

TEST(st2, CircleSetterFerenceSetCorrectFerence) {
  Circle c(1.0);
  c.setFerence(PI);
  EXPECT_NEAR(c.getFerence(), PI, EPS);
}

TEST(st2, CircleSetterFerenceCalcCorrectRadius) {
  Circle c(1.0);
  c.setFerence(PI);
  EXPECT_NEAR(c.getRadius(), 0.5, EPS);
}

TEST(st2, CircleSetterFerenceCalcCorrectArea) {
  Circle c(1.0);
  c.setFerence(PI);
  EXPECT_NEAR(c.getArea(), 0.25 * PI, EPS);
}

TEST(st2, CircleSetterAreaSetCorrectArea) {
  Circle c(1.0);
  c.setArea(PI);
  EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(st2, CircleSetterAreaCalcCorrectRadius) {
  Circle c(1.0);
  c.setArea(PI);
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
}

TEST(st2, CircleSetterAreaCalcCorrectFerence) {
  Circle c(1.0);
  c.setArea(PI);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
}

TEST(st2, EarthRopeTaskResultPositive) {
  EXPECT_GT(earthRopeTask(), 0.0);
}

TEST(st2, EarthRopeTaskResult) {
  double gap = earthRopeTask();
  EXPECT_NEAR(gap, 1.0 / (2.0 * PI), EPS);
}

TEST(st2, PoolWalkwayCostPositive) {
  EXPECT_GT(poolWalkwayCostTask(), 0.0);
}

TEST(st2, PoolFenceCostPositive) {
  EXPECT_GT(poolFenceCostTask(), 0.0);
}

TEST(st2, PoolWalkwayCostResult) {
  EXPECT_NEAR(poolWalkwayCostTask(), 21991.15, EPS);
}

TEST(st2, PoolFenceCostResult) {
  EXPECT_NEAR(poolFenceCostTask(), 50265.48, EPS);
}

TEST(st2, PoolWalkwayAndFenceCostResult) {
  auto [walkwayCost, fenceCost] = poolWalkwayAndFenceCostTask();
  EXPECT_NEAR(poolWalkwayCostTask(), 21991.15, EPS);
  EXPECT_NEAR(poolFenceCostTask(), 50265.48, EPS);
}