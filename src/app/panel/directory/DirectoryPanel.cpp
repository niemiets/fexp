#include "DirectoryPanel.h"

DirectoryPanel::DirectoryPanel(const std::string &path, WindowOptions winOpt) : Panel(winOpt)
{
	this->path = path;
}