#include <ncursesw/ncurses.h>

#include "Window.h"

Window::Window(int nlines, int ncols, int begin_y, int begin_x)
{
	this->wnd = newwin(nlines, ncols, begin_y, begin_x);
}

Window::~Window()
{
	delwin(this->wnd);
}