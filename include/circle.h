#define INCLUDE_CIRCLE_H_
#include <cstdint>

constexpr auto PI = 3.14159265358979323846;

class Circle {
 private:
  double radius;
  double ference;
  double area;

  void recalcFromRadius(double r);

 public:
  explicit Circle(double _rad);

  void setRadius(double _rad);
  void setFerence(double _fer);
  void setArea(double _area);

  double getRadius();
  double getFerence();
  double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
