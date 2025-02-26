import curses
import curses.panel

class App:
    scr: curses.window

    running: bool

    def __init__(self):
        self.running = False

    def start(self):
        self.setup()

        self.running = True

        while (self.running):
            pass

    def stop(self):
        curses.endwin()

    def setup(self):
        self.scr = curses.initscr()
        curses.noecho()
        curses.cbreak()
        self.scr.keypad(True)

if __name__ == "__main__":
    app = App()

    app.start()