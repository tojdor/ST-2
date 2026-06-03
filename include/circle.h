// Copyright 2022 UNN-CS

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 public:
  static constexpr double kPi = 3.14159265358979323846;

  explicit Circle(double radius);

  void setRadius(double radius);
  void setFerence(double ference);
  void setArea(double area);

  double getRadius() const;
  double getFerence() const;
  double getArea() const;

 private:
  double radius_;
  double ference_;
  double area_;

  static void ensureNonNegative(double value, const char* what);
  void syncFromRadius(double radius);
};

#endif  // INCLUDE_CIRCLE_H_
