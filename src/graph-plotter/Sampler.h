#ifndef SAMPLER_H
#define SAMPLER_H

#include "DataPoints.h"
#include <functional>
// Logic Layer: Generates samples of mathematical functions for plotting.
class Sampler
{
public:
	// performs uniform sampling
	DataPoints generateSamples(std::function<float(float)> func, const Range& range) const;

private:
	static const int TOTAL_POINTS = 200; // increase the number of data points generated, hence increase sample size by 4x inital size
};

// standalone function for generating data points, a default uniform sampler is provided
DataPoints generateDataPoints(std::function<float(float)> func, const Range& range, const Sampler& sampler = Sampler{});
#endif
