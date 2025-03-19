import curses as curs
import curses.panel as cpan

import panel.wrapped_panel as wpan

class DirectoryPanel(wpan.Panel):
    def __init__(self, path: str, win: curs.window):
        super().__init__(win)

    def on_key(self, key: int):
        self.win.addstr("awd")
        self.win.refresh()
