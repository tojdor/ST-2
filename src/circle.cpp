// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

void Circle::recalcFromRadius(double r) {
  radius = r;
  ference = 2.0 * PI * radius;  // 2πr
  area = PI * radius * radius;  // πr^2
}

Circle::Circle(double _rad) {
  if (_rad < 0.0) {
    throw std::invalid_argument("radius cannot be negative");
  }
  recalcFromRadius(_rad);
}

void Circle::setRadius(double _rad) {
  if (_rad < 0.0) {
    throw std::invalid_argument("radius cannot be negative");
  }
  recalcFromRadius(_rad);
}

void Circle::setFerence(double _fer) {
  if (_fer < 0.0) {
    throw std::invalid_argument("ference cannot be negative");
  }
  double r = _fer / (2.0 * PI);  // C:(2π)
  recalcFromRadius(r);
}

void Circle::setArea(double _area) {
  if (_area < 0.0) {
    throw std::invalid_argument("area cannot be negative");
  }
  double r = std::sqrt(_area / PI);  // √(S:π)
  recalcFromRadius(r);
}

double Circle::getRadius() {
  return radius;
}

double Circle::getFerence() {
  return ference;
}

double Circle::getArea() {
  return area;
}
