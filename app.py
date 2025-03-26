import curses
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

        dir_win = curs.newwin(curs.LINES, curs.COLS, 0, 0)

        dir_pan = DirectoryPanel(sys.argv[0], dir_win)

        self.panels.append(dir_pan)

        dir_win.refresh()

        self.running = True

        while self.running:
            self.handle_input()

        self.stop()

    def stop(self):
        curs.endwin()

    def setup(self):
        self.scr = curs.initscr()

        curs.noecho()
        curs.cbreak()
        self.scr.keypad(True)
        self.scr.nodelay(True)
        curs.mousemask(curs.ALL_MOUSE_EVENTS)

        self.scr.refresh()

        self.panels = []

    def get_focused(self):
        return self.panels[self.focused]

    def handle_input(self):
        try:
            character: int = self.scr.getch()
        except curses.error:
            return

        match character:
            case curs.KEY_MOUSE:
                self.handle_mouse()
            case _:
                self.handle_key(character)

    def handle_mouse(self):
        (id, x, y, z, bstate) = curs.getmouse()

        self.get_focused().on_mouse(id, x, y, z, bstate)

    def handle_key(self, key: int):
        self.get_focused().on_key(key)