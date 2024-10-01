#include "DashedLineStyle.h"
#include <cmath>
#include <algorithm>

DashedLineStyle::DashedLineStyle(Colour colour, std::shared_ptr<Display> display_ptr, int dash_length, int gap_length)
    : LineStyle(colour, display_ptr), dash_length_(dash_length), gap_length_(gap_length) {}

void DashedLineStyle::plotLine(PointPair end_points) {
    auto display = getDisplay();
    auto start = end_points.first();
    auto end = end_points.second();

    // Calculate the total distance between the start and end points
    float total_length = std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2));
    
    // Normalize the direction vector (step sizes) for each dash
    float direction_x = (end.x - start.x) / total_length;
    float direction_y = (end.y - start.y) / total_length;

    // Initialize the current position to the start point
    float current_x = start.x;
    float current_y = start.y;

    // Calculate the full cycle length of a dash and a gap
    float cycle_length = dash_length_ + gap_length_;
    
    // Draw dashes along the full line
    while (std::sqrt(std::pow(current_x - start.x, 2) + std::pow(current_y - start.y, 2)) < total_length) {
        // Calculate the end of the current dash
        float dash_end_x = current_x + direction_x * dash_length_;
        float dash_end_y = current_y + direction_y * dash_length_;

        // Ensure that the dash does not exceed the total line length
        if (std::sqrt(std::pow(dash_end_x - start.x, 2) + std::pow(dash_end_y - start.y, 2)) > total_length) {
            dash_end_x = end.x;
            dash_end_y = end.y;
        }

        // Draw the dash
        display->drawLine(PointPair(Point{current_x, current_y}, Point{dash_end_x, dash_end_y}), getColour());

        // Move the current position forward by the dash and gap length
        current_x = dash_end_x + direction_x * gap_length_;
        current_y = dash_end_y + direction_y * gap_length_;
    }
}
