#include <ncursesw/ncurses.h>

#include "Window.h"

Window::Window(WindowOptions winOpt)
{
	this->wnd = newwin(winOpt.nlines, winOpt.ncols, winOpt.begin_y, winOpt.begin_x);
}

Window::~Window()
{
	delwin(this->wnd);
}

WINDOW* Window::getHandle()
{
	return this->wnd;
}