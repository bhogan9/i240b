#ifndef LINE_HH_
#define LINE_HH_

#include <string>

struct Line {
  const Point p1, p2;

  Line(Point p1, Point p2) : p1(p1), p2(p2) { }

  double length() const;

  std::string toString() const;
};

#endif
