#ifndef DASHEDLINESTYLE_H
#define DASHEDLINESTYLE_H

#include "LineStyle.h"
#include <memory>

// Presentation Layer: Implements dashed line drawing with better interpolation.
class DashedLineStyle : public LineStyle {
public:
    // Constructor with colour, display pointer, dash length, and gap length
    DashedLineStyle(Colour colour, std::shared_ptr<Display> display_ptr, int dash_length = 5, int gap_length = 10);

    // Override to plot dashed line
    virtual void plotLine(PointPair end_points) override;

private:
    int dash_length_;  // Length of dashes in pixels
    int gap_length_;   // Length of gaps between dashes
};

#endif
