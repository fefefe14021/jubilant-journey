#ifndef POINT_H_
#define POINT_H_

#include <string>

class Point {
 public:
  Point(double x_coord, double y_coord);
  std::string ToString() const;
  double DistanceTo(const Point& other) const;
  void Shift(double delta_x, double delta_y);

 private:
  double x_;
  double y_;
};

#endif  // POINT_H_
