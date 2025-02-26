import curses as curs
import curses.panel as cpan

import panel.wrapped_panel as wpan

class DirectoryPanel(wpan.Panel):
    def __init__(self, path, win):
        super().__init__(win)
        print(path)