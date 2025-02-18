#ifndef FEXP_DIRECTORY_PANEL_H
#define FEXP_DIRECTORY_PANEL_H

#include <string>

#include <ncursesw/ncurses.h>

#include "../Panel.h"

class DirectoryPanel : public Panel
{
	public:
		DirectoryPanel(const std::string &path = "", struct WindowOptions winOpts = {});
	
	private:
		std::string path;
};

#endif
