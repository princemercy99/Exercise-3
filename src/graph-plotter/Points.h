#ifndef POINTS_H
#define POINTS_H
// Logic Layer: Represents a point in a 2D coordinate system.
struct Point
{
	float x;
	float y;
};

class PointPair
{
public:
	PointPair(Point p1, Point p2):
	  _p1(p1),
	  _p2(p2)
	  {}

	  Point first() const { return _p1; }	// return first point in pair
	  Point second() const { return _p2; }	// return second point in pair

private:
	Point _p1;
	Point _p2;
};
// Logic Layer: Represents a range of values (start and end) for x-coordinates or function evaluation.
class Range
{
public:
	Range(float start, float end):
	  start_(start),
	  end_(end)
	  { if (end <= start) throw "Not a range."; }

	  float getStart() const { return start_; }		// return start of range
	  float getEnd() const { return end_; }			// return end of range
	  float size() const { return end_ - start_; }	// return size of range

private:
	float start_;
	float end_;
};

#endif
