#include <thread>

#include <ncurses/ncurses.h>

#include "App.h"

static App* s_Instance = nullptr;

void App::Init(const AppOptions& options) {
    initscr();
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