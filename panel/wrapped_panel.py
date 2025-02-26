import curses as curs
import curses.panel as cpan

class Panel:
    win: curs.window
    panel: cpan

    def __init__(self, win: curs.window):
        self.win = win
        self.panel = cpan.new_panel(self.win)

    def on_key(self, key: int):
        pass