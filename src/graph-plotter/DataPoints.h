#ifndef DATAPOINTS
#define DATAPOINTS

#include "Points.h"
#include <utility>	// required for pair (see http://www.cplusplus.com/reference/std/utility/pair/)
#include <vector>

using std::pair;
using std::make_pair;
using std::vector;
// Logic Layer: Handles data point transformations and grouping for plotting.
class DataPoints
{
public:
	DataPoints(vector<Point> datapoints):
	  datapoints_(datapoints),
	  transformed_(false)
	  {}
	  vector<Point> getAsPoints() const { return datapoints_; }
	  vector<PointPair> getAsPointPairs() const;	// groups adjacent points into pairs
	  // transforms data points to display points - required before points can be plotted
	  void transformToDisplayCoordinateSystem(int display_width, int display_height);

private:
	pair<float,float> calculateScaleFactors(int display_width, int display_height) const; // required for scaling the points to fit the display
	pair<float,float> calculateOffsets(int display_width, int display_height) const;	// required for shifting the points so that they are all positive

	vector<float> extractYValues() const;
	float getMaxY() const;
	float getMinY() const;
	float getMaxX() const;
	float getMinX() const;

	vector<Point> datapoints_;
	bool transformed_;
};

#endif
