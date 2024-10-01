#include "Graph.h"
#include "Sinusoid.h"
#include "Sampler.h"
#include "Display.h"
#include "SolidLineStyle.h"
#include "DashedLineStyle.h"
#include "DottedLineStyle.h"
#include "Points.h"
#include <memory>
#include <cmath>

using std::make_shared;
using std::shared_ptr;

int main()
{
    // setup Graph with Display
    const auto WIDTH = 800;
    const auto HEIGHT = 600;
    auto display = make_shared<Display>(WIDTH, HEIGHT);
    auto graph = Graph{ display };

    // Create a range for the x-values
    auto range = Range{ -3.0f, 1.5f };

    // Polynomial function: y = x^2 + 2x + 1
    auto polynomial = [](float x) {
        return x * x + 2 * x + 1;
        };

    // Exponential function: y = e^(1.5x)
    auto exponential = [](float x) {
        return std::exp(1.5f * x);
        };

    // Plot polynomial with solid red line style
    auto solid_red = SolidLineStyle{ Colour::Red, display };
    graph.plot(generateDataPoints(polynomial, range), solid_red);

    // Plot exponential with solid blue line style
    auto solid_blue = SolidLineStyle{ Colour::Blue, display };
    graph.plot(generateDataPoints(exponential, range), solid_blue);

    return 0;
}