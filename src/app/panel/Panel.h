#ifndef FEXP_PANEL_H
#define FEXP_PANEL_H

#include <ncursesw/ncurses.h>
#include <ncursesw/panel.h>

#include "../window/Window.h"

class Panel : public Window
{
	public:
		Panel(WindowOptions winOpts = {});
		Panel(Window win);
};

#endif