#ifndef DISPLAY_CLASS_H
#define DISPLAY_CLASS_H

#include <raylib-cpp.hpp>
#include "Points.h"

enum class Colour
{
	Red,
	Green,
	Blue
};

// DO NOT MODIFY THE DISPLAY CLASS!
// Clients have no knowledge that raylib-cpp is in use
// Presentation Layer: Manages rendering of graphical elements on the screen.
class Display
{
public:
	Display(int display_width, int display_height);
	int getWidth() const { return display_width_; }
	int getHeight() const { return display_height_; }

	void drawLine(PointPair end_points, Colour colour);
	void drawDot(Point point, Colour colour);

	void clear();				 // clears the current display
	void startDrawing(); // setup canvas (framebuffer) to start drawing
	void endDrawing();	 // end canvas drawing and swap buffers (double buffering) so drawing is displayed
	void pause();				 // pauses execution of the program so that the display can be viewed
											 // pressing the Escape key will close the display
											 // pressing the spacebar will allow program execution to continue

private:
	raylib::Color convertToRaylib(Colour colour) const; // converts to raylib-cpp Colours

	int display_width_;
	int display_height_;

	raylib::Window window_; // raylib window

	static const int RADIUS = 3;
};

#endif
