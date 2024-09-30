#ifndef LINESTYLE
#define LINESTYLE

#include "Display.h"
#include <memory>

using std::shared_ptr;
// Presentation Layer: Abstract class defining how lines are drawn.
class LineStyle
{
public:
	LineStyle(Colour colour, shared_ptr<Display> display_ptr);
	virtual void plotLine(PointPair end_points) = 0;

	virtual ~LineStyle() {};

protected:
	shared_ptr<Display> getDisplay() { return display_ptr_; }
	Colour getColour() { return colour_; }

private:
	Colour colour_;
	shared_ptr<Display> display_ptr_;
};

#endif
