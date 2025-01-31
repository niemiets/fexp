#include <ncursesw/ncurses.h>

#include "TermOpts.h"

void processTermOpts(const union TermOptions &opts)
{
	if (opts.flags.cbreak)
		cbreak();
	else
		nocbreak();
	
	if (opts.flags.echo)
		echo();
	else
		noecho();
	
	if (opts.flags.nl)
		nl();
	else
		nonl();
	
	if (opts.flags.raw)
		raw();
	else
		noraw();
}