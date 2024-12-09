#include <thread>

#include <ncursesw/ncurses.h>

#include "App.h"

static App* s_Instance = nullptr;

void App::Init(const AppOptions& options) {
    initscr();

    if (options.flags.cbreak)
        cbreak();
    else
        nocbreak();
    
    if (options.flags.echo)
        echo();
    else
        noecho();
    
    if (options.flags.nl)
        nl();
    else
        nonl();
    
    if (options.flags.raw)
        raw();
    else
        noraw();
}

void App::Destroy() {
    endwin();
}

App& App::GetInstance() {
    if (s_Instance == nullptr)
        s_Instance = new App();

    return *s_Instance;
}

void App::run() {
    std::thread inputThread(handleInput, this);
}

void App::handleInput() {

}

void App::onInput() {

}