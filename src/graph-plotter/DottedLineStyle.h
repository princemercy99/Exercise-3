#ifndef DOTTEDLINESTYLE_H
#define DOTTEDLINESTYLE_H

#include "LineStyle.h"
#include <memory>

// Presentation Layer: Implements dotted line drawing with configurable gaps.
class DottedLineStyle : public LineStyle {
public:
    // Constructor with colour, display pointer, and dot spacing
    DottedLineStyle(Colour colour, std::shared_ptr<Display> display_ptr, int dot_spacing = 15);

    // Override to plot dotted line
    virtual void plotLine(PointPair end_points) override;

private:
    int dot_spacing_;  // Space between dots in pixels
};

#endif
