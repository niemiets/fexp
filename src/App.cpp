#include <ncurses/ncurses.h>

#include "App.h"

static App* s_Instance = nullptr;

void App::Init(AppOptions options = AppOptions{}) {
    initscr();
}

void App::Destroy() {

}

App& App::GetInstance() {
    if (s_Instance == nullptr)
        s_Instance = new App();

    return *s_Instance;
}