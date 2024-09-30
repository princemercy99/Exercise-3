#ifndef SOLIDLINESTYLE_H
#define SOLIDLINESTYLE_H

#include "LineStyle.h"
// Presentation Layer: Implements solid line drawing.
class SolidLineStyle: public LineStyle
{
public:
	SolidLineStyle(Colour colour, shared_ptr<Display> display_ptr):
	  LineStyle(colour,display_ptr)
	  {}
	virtual void plotLine(PointPair end_points) override;
};

#endif
