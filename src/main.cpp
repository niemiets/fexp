#include <ncursesw/ncurses.h>

#include "app/App.h"

int main()
{
    App::Init(
		{
			.flags = {
				.keypad = true,
				
			}
		},
		{
		
		}
	);

    App& app = App::GetInstance();
	
	app.run();
	
	App::Destroy();

    return 0;
}