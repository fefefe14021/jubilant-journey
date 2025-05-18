#include "point.h"
#include <cmath>
#include <sstream>

Point::Point(double x_coord, double y_coord) : x_(x_coord), y_(y_coord) {}

std::string Point::ToString() const {
  std::stringstream ss;
  ss << "{" << x_ << ";" << y_ << "}";
  return ss.str();
}

double Point::DistanceTo(const Point& other) const {
  return std::sqrt(std::pow(other.x_ - x_, 2) + std::pow(other.y_ - y_, 2));
}

void Point::Shift(double delta_x, double delta_y) {
  x_ += delta_x;
  y_ += delta_y;
}
