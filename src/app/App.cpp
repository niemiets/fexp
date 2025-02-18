#include <thread>
#include <filesystem>
#include <iostream>
#include <string>

#include <ncursesw/ncurses.h>

#include "App.h"
#include "../term/TermOpts.h"
#include "panel/directory/DirectoryPanel.h"

namespace fs = std::filesystem;

static App* s_Instance = nullptr;

void App::Init(const union AppOptions &appOpts, const union TermOptions &termOpts)
{
    initscr();
	
	processTermOpts(termOpts);
	ProcessAppOpts(appOpts);
	
	DirectoryPanel dirPan;
	
	// std::string path = "/";
	//
	// auto dir_iter = fs::directory_iterator(path);
	//
	// std::advance(dir_iter, 1);
	//
	// std::cout << dir_iter->path();
}

void App::Destroy()
{
    endwin();
	
	s_Instance = nullptr;
}

void App::ProcessAppOpts(const union AppOptions &opts)
{
	intrflush(stdscr, opts.flags.intrflush);
	keypad(stdscr, opts.flags.keypad);
	meta(stdscr, opts.flags.meta);
	nodelay(stdscr, opts.flags.nodelay);
	notimeout(stdscr, opts.flags.notimeout);
}

App& App::GetInstance()
{
    if (s_Instance == nullptr)
        s_Instance = new App();

    return *s_Instance;
}

void App::run()
{
	this->running = true;
	
    // std::thread inputThread(&App::handleInput, this);
	
	while (this->running)
	{
		handleInput();
	}
}

void App::handleInput()
{

}

void App::onInput()
{

}

bool App::isRunning()
{
	return s_Instance->running;
}