import curses
import curses as curs
import curses.panel as cpan

import panel.wrapped_panel as wpan

class DirectoryPanel(wpan.Panel):
    def __init__(self, path: str, win: curs.window):
        super().__init__(win)

    def on_mouse(self, id, x, y, z, bstate):
        match id:
            case curs.BUTTON1_CLICKED:
                # self.win.addstr(f"press 1\n")
                # self.win.refresh()
                pass
            case _:
                pass

    def on_key(self, key: int):
        match key:
            case _:
                # self.win.addstr(f"{key}\n")
                # self.win.refresh()
                print(key)
                pass