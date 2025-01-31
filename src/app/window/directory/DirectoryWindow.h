#ifndef FEXP_DIRECTORY_WINDOW_H
#define FEXP_DIRECTORY_WINDOW_H

#include <string>

#include <ncursesw/ncurses.h>

#include "../Window.h"

class DirectoryWindow : public Window
{
	public:
		DirectoryWindow(const std::string &path = "");
		
	private:
		std::string path;
};

#endif
