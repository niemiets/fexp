#ifndef FEXP_APP_H
#define FEXP_APP_H

#include <cstdint>

#include "../term/TermOpts.h"

union AppOptions {
	uint8_t value;
	
	struct {
		bool intrflush : 1;
		bool keypad    : 1;
		bool meta      : 1;
		bool nodelay   : 1;
		bool notimeout : 1;
	} flags;
};

class App {
	public:
        App(const App&) = delete;
        App& operator=(const App&) = delete;

        static void Init(
			const union AppOptions &appOpts = {
				.flags = {
					.intrflush = false,
					.keypad = false,
					.meta = false,
					.nodelay = false,
					.notimeout = false
				}
			},
			const union TermOptions &termOpts = TermOptions{
				.flags = {
					.cbreak = false,
					.echo = false,
					.nl = false,
					.raw = false
				}
			}
		);
        static void Destroy();

        static App& GetInstance();
		
		static void ProcessAppOpts(const union AppOptions &opts);

        void run();
		
		bool isRunning();

        App& addOnKey(void (*func)(char key));
        App& addOnMouse(void (*func)(const MEVENT &mouse));
    
    private:
        App() = default;
        ~App() = default;
		
		bool running;

        void handleInput();

        void onInput();
};

#endif
