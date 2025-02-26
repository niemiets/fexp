import sys

import curses as curs
import curses.panel as cpan

import panel.wrapped_panel
from panel.directory_panel import DirectoryPanel

class App:
    scr: curs.window

    panels: list[cpan]

    focused: int

    running: bool

    def __init__(self):
        self.scr = None
        self.panels = []
        self.focused = 0
        self.running = False

    def start(self):
        self.setup()

        self.running = True

        while self.running:
            self.handle_input()

    def stop(self):
        curs.endwin()

    def setup(self):
        self.scr = curs.initscr()

        curs.noecho()
        curs.cbreak()
        self.scr.keypad(True)

        dir_win = curs.newwin(curs.LINES, curs.COLS, 0, 0)
        self.panels = [DirectoryPanel(sys.argv[0], dir_win)]

    def get_focused(self):
        return self.panels[self.focused]

    def handle_input(self):
        character: int = self.scr.getch()

        match(character):
            case curs.KEY_MOUSE:
                self.handle_mouse()
            case _:
                self.handle_key(character)

    def handle_mouse(self):
        (id, x, y, z, bstate) = curs.getmouse()

        self.get_focused().on_mouse(id, x, y, z, bstate)

    def handle_key(self, key):
        self.get_focused().on_key(key)