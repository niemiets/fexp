#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <filesystem>
 
#include <ncurses/ncurses.h>

#define uint unsigned int

namespace fs = std::filesystem;

const int SCROLL_UP		= BUTTON4_PRESSED;
const int SCROLL_DOWN	= BUTTON5_PRESSED;

static void finish(const int sig);
static void quit();
static bool init();

const std::vector<std::unique_ptr<fs::directory_entry>> read_dir(const std::string path);

enum class EXT_VALUES {
	OFF,
	ON,
	ALWAYS
};

enum class HIDDEN_VALUES {
	OFF,
	ON,
	ONLY
};

enum class COLOR_VALUES {
	OFF,
	ON,
	AUTO
};

typedef struct {
	uint 			col;
	uint 			row;
	uint 			gap;
	int 			gap_x;
	int 			gap_y;
	uint 			pad;
	int 			pad_x;
	int 			pad_y;
	EXT_VALUES 		ext;
	uint 			word_len;
	HIDDEN_VALUES 	hidden;
	COLOR_VALUES 	color;
	std::string 	trail;
	std::string 	ext_trail;
} CONFIG;

int main(
	int argc, 
	char *argv[]
)
{
	CONFIG conf = {
		.col 		= 0,
		.row 		= 0,
		.gap 		= 1,
		.gap_x 		= -1,
		.gap_y 		= -1,
		.pad 		= 0,
		.pad_x 		= -1,
		.pad_y 		= -1,
		.ext 		= EXT_VALUES::ON,
		.word_len 	= 0,
		.hidden 	= HIDDEN_VALUES::OFF,
		.color 		= COLOR_VALUES::AUTO,
		.trail 		= "...",
		.ext_trail 	= "(...)"
	};
	// default config
	// COL = 0 (as many as possible)
	// ROW = 0 (as many as possible)
	// GAP = 1 (0 - inf)
	// GAP_X = -1 (overwrites GAP if not negative)
	// GAP_Y = -1 (overwrites GAP if not negative)
	// PAD = 0
	// PAD_X = -1
	// PAD_Y = -1
	// EXT = 1 (FALSE/TRUE/ALWAYS (see WORD_LENGTH))
	// WORD_LEN = 0 (max word length in current column)
	// HIDDEN = 0 (FALSE/TRUE/ONLY)
	// COLOR = 2 (FALSE/TRUE/AUTO)
	// TRAIL = "..."
	// EXT_TRAIL= "(...)" (when EXT == 2[ALWAYS])

	// config

	// flags

	// arguments
	// DIR (required)
	// [...FILES] (optional)

	// display
	// get HEIGHT and WIDTH
	// type File struct {
	//     name string
	//     size uint64
	//     mode Permissions (permissions)
	//
	// }
	// type Permissions struct {
	//     user Permission
	//     group Permission
	//     other Permission
	// }
	// File[] -> show

	// keyhandling

	if (argc > 1)
		for (int i = 1; i < argc; ++i)
        	std::cout << argv[i];

	int key;
	MEVENT mouse_event;

	/* initialize your non-curses data structures here */
	if (!init()) 
	{
		return 1;
	}

	while (1)
	{
		key = getch();
		
		switch (key)
		{
			case 'q':
				quit();
			break;
 
			case 'a':
			case 'h':
			case KEY_LEFT:
				// left
				addch('l');
			break;
 
			case 's':
			case 'j':
			case KEY_DOWN:
				// down
				addch('d');
			break;
 
			case 'w':
			case 'k':
			case KEY_UP:
				// up
				addch('u');
			break;
 
			case 'd':
			case 'l':
			case KEY_RIGHT:
				// right
				addch('r');
			break;

			case '/':
				// search
			break;
 
			case KEY_MOUSE:				
				if (getmouse(&mouse_event) == ERR)
					break;

				if (mouse_event.bstate & SCROLL_UP) 
				{
					// scroll up
					addch('u');
				}
				else if (mouse_event.bstate & SCROLL_DOWN) 
				{
					// scroll down
					addch('d');
				}

				/*
 
				char strme[128];
 
				unsigned long ulme = (unsigned long)me.bstate;
 
				sprintf(strme, "%lu", ulme);
 
				for (int i = 0; i < strlen(strme); i++)
				{
					addch(strme[i]);
				}
 
				addch('\n');

				*/
			break;
 
			default:
				std::string str_key = std::to_string(key);

				addch('\n');
 
				for (int i = 0; i < str_key.length(); i++)
				{
					addch(str_key[i]);
				}
 
				addch('\n');
			break;
		}
	}
 
	quit();               /* we are done */
}

static bool init()
{
	signal(SIGINT, finish);	/* arrange interrupts to terminate */
 
	initscr();	/* initialize the curses library */
	keypad(stdscr, TRUE);	/* enable keyboard mapping */
	nonl();	/* tell curses not to do NL->CR/NL on output */
	cbreak();	/* take input chars one at a time, no wait for \n */
	noecho();
	scrollok(stdscr, TRUE);

	if (mousemask(SCROLL_UP|SCROLL_DOWN, NULL) == 0)
		printf("The terminal does not support mouse-events\n");

	return true;
}

static void quit()
{
	finish(0);
}

static void finish(int sig)
{
	endwin();
 
	/* do your non-curses wrapup here */

	if (sig)
	{
		exit(128 + sig);
	}

	exit(0);
}

const std::vector<std::unique_ptr<fs::directory_entry>> read_dir(const std::string path)
{
	std::vector<std::unique_ptr<fs::directory_entry>> files;

    for (const auto & entry : fs::directory_iterator(path))
        files.push_back(std::make_unique<fs::directory_entry>(entry));

	return files;
}