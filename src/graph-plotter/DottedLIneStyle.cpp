#include "DottedLineStyle.h"
#include <cmath>
#include <algorithm>

DottedLineStyle::DottedLineStyle(Colour colour, std::shared_ptr<Display> display_ptr, int dot_spacing)
    : LineStyle(colour, display_ptr), dot_spacing_(dot_spacing) {}

void DottedLineStyle::plotLine(PointPair end_points) {
    auto display = getDisplay();
    auto start = end_points.first();
    auto end = end_points.second();

    // Calculate the total distance between the start and end points
    float total_length = std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2));

    // Normalize the direction vector for each dot
    float direction_x = (end.x - start.x) / total_length;
    float direction_y = (end.y - start.y) / total_length;

    // Initialize the current position to the start point
    float current_x = start.x;
    float current_y = start.y;

    // Draw dots along the full line with spacing between them
    while (std::sqrt(std::pow(current_x - start.x, 2) + std::pow(current_y - start.y, 2)) < total_length) {
        // Draw a dot at the current position
        display->drawDot(Point{ current_x, current_y }, getColour());

        // Move the current position forward by the dot spacing
        current_x += direction_x * dot_spacing_;
        current_y += direction_y * dot_spacing_;
    }
}
