#include "Graph.h"
#include "Points.h"

void Graph::plot(DataPoints data_points, LineStyle &line_plotter)
{
	data_points.transformToDisplayCoordinateSystem(display_->getWidth(), display_->getHeight());
	auto point_pairs = data_points.getAsPointPairs();

	// Here the same graph is drawn on both the front and back buffers to prevent flickering when display_->pause()
	// is called. This is because Display::pause() continually cycles through the buffers alternating between each one,
	// and rendering it.
	drawToBuffer(point_pairs, line_plotter);
	drawToBuffer(point_pairs, line_plotter);
	drawToBuffer(point_pairs, line_plotter);// another Draw to Buffer stops flickering
	
	display_->pause();
}

void Graph::drawToBuffer(const vector<PointPair> &points, LineStyle &line_plotter)
{
	// All drawing is done on the back buffer when StartDrawing() is called. The back and front buffers are swapped
	// when call EndDrawing() is called, and the new front buffer is rendered. This is called double buffering.
	display_->startDrawing();
	display_->clear();

	for (const auto &point_pair : points)
	{
		line_plotter.plotLine(point_pair);
	}

	display_->endDrawing();
}