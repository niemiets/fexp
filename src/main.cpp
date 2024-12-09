#include <ncurses/ncurses.h>

#include "App.h"

int main()
{
    App::Init();

    const App& app = App::GetInstance();

    return 0;
}