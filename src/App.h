#ifndef APP_H
#define APP_H

union AppOptions {
    uint8_t value;

    struct {
        bool cbreak : 1;
        bool echo   : 1;
        bool nl     : 1;
        bool row    : 1;
    } flags;
};

class App {
    public:
        App(const App&) = delete;
        App& operator=(const App&) = delete;

        static void Init(AppOptions options = AppOptions{});
        static void Destroy();

        static App& GetInstance();

        void run();
    
    private:
        App();
        ~App();
};

#endif