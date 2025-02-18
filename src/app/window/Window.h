#ifndef FEXP_WINDOW_H
#define FEXP_WINDOW_H

#include <ncursesw/ncurses.h>

struct WindowOptions {
	int nlines  = 0;
	int ncols   = 0;
	int begin_y = 0;
	int begin_x = 0;
};

class Window
{
	public:
		Window(WindowOptions winOpt = {});
		~Window();
		
		WINDOW* getHandle();
		
	private:
		WINDOW *wnd;
};

#endif