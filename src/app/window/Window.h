#ifndef FEXP_WINDOW_H
#define FEXP_WINDOW_H

#include <ncursesw/ncurses.h>

class Window
{
	public:
		Window(int nlines = 0, int ncols = 0, int begin_y = 0, int begin_x = 0);
		~Window();
		
	private:
		WINDOW *wnd;
};

#endif