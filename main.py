from app import App

if __name__ == "__main__":
    app = App()

    try:
        app.start()
    except KeyboardInterrupt:
        pass