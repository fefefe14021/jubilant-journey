#include "broken_line.h"
#include <sstream>

BrokenLine::BrokenLine(const std::vector<Point>& points) : points_(points) {}

void BrokenLine::AddPoints(const std::vector<Point>& new_points) {
  points_.insert(points_.end(), new_points.begin(), new_points.end());
}

double BrokenLine::Length() const {
  double length = 0;
  for (size_t i = 0; i + 1 < points_.size(); ++i) {
    length += points_[i].DistanceTo(points_[i + 1]);
  }
  return length;
}

std::string BrokenLine::ToString() const {
  std::stringstream ss;
  ss << "Линия [";
  for (size_t i = 0; i < points_.size(); ++i) {
    ss << points_[i].ToString();
    if (i + 1 < points_.size()) ss << ", ";
  }
  ss << "]";
  return ss.str();
}

void BrokenLine::Shift(double delta_x, double delta_y) {
  for (auto& point : points_) {
    point.Shift(delta_x, delta_y);
  }
}

const Point& BrokenLine::FirstPoint() const { return points_.front(); }

const Point& BrokenLine::LastPoint() const { return points_.back(); }
