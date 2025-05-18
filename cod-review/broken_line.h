#ifndef BROKEN_LINE_H_
#define BROKEN_LINE_H_

#include <string>
#include <vector>
#include "point.h"

class BrokenLine {
 public:
  BrokenLine() = default;
  explicit BrokenLine(const std::vector<Point>& points);

  void AddPoints(const std::vector<Point>& new_points);
  double Length() const;
  std::string ToString() const;
  void Shift(double delta_x, double delta_y);

  const Point& FirstPoint() const;
  const Point& LastPoint() const;

 private:
  std::vector<Point> points_;
};

#endif  // BROKEN_LINE_H_
