// Copyright 2022 UNN-CS

#include <cstdint>
#include <cmath>
#include <stdexcept>

#include "circle.h"

void Circle::ensureNonNegative(double value, const char* what) {
  if (value < 0.0) {
    throw std::invalid_argument(what);
  }
}

void Circle::syncFromRadius(double radius) {
  radius_ = radius;
  ference_ = 2.0 * kPi * radius_;
  area_ = kPi * radius_ * radius_;
}

Circle::Circle(double radius) : radius_(0.0), ference_(0.0), area_(0.0) {
  ensureNonNegative(radius, "radius must be non-negative");
  syncFromRadius(radius);
}

void Circle::setRadius(double radius) {
  ensureNonNegative(radius, "radius must be non-negative");
  syncFromRadius(radius);
}

void Circle::setFerence(double ference) {
  ensureNonNegative(ference, "ference must be non-negative");
  syncFromRadius(ference / (2.0 * kPi));
}

void Circle::setArea(double area) {
  ensureNonNegative(area, "area must be non-negative");
  syncFromRadius(std::sqrt(area / kPi));
}

double Circle::getRadius() const { return radius_; }
double Circle::getFerence() const { return ference_; }
double Circle::getArea() const { return area_; }
