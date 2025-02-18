#include <ncursesw/ncurses.h>
#include <ncursesw/panel.h>

#include "Panel.h"

Panel::Panel(WindowOptions winOpts)
{
	Window win(winOpts);
	new_panel(win.getHandle());
}

Panel::Panel(Window win)
{
	new_panel(win.getHandle());
}