#ifndef FEXP_TERM_OPTS_H
#define FEXP_TERM_OPTS_H

#include <cstdint>

union TermOptions
{
	uint8_t value;
	
	struct
	{
		bool cbreak : 1;
		bool echo   : 1;
		bool nl     : 1;
		bool raw    : 1;
	} flags;
};

void processTermOpts(const union TermOptions &opts);

#endif
