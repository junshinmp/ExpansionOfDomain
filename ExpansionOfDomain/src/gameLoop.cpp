#include <SDL.h>
#include <stdio.h>

#include "Controls.h"
#include "renderer.h"
#include "ScreenFiles.h"
#include "gameLoop.h"
#include "Player.h"

bool quit = false;

void gameloop() {
	SDL_Event event;
	ScreenFiles curr = getCurrScreenFile();

	Player playerOne;

	// processes all gameplay functionality, processing, and the "loop"
	while (!quit)
	{
		// Handle events on queue
		// will also split into three different functions dependent on what specific screen the user is on
		// i.e: in the main menu, training
		// only done on keyboard currently

		while (SDL_PollEvent(&event) != 0)
		{

			if (quit == true) {
				break;
			}

			switch (event.type) {
				// checking for quit from user closing window
			case SDL_QUIT:
				quit = true;
				break;
				// checking for if user pushes down a key
			case SDL_KEYUP:
				if (!event.key.repeat) {
					SDL_Keycode code = event.key.keysym.sym;

					const Uint8* state = SDL_GetKeyboardState(nullptr);
					SDL_Scancode scanCode = SDL_GetScancodeFromKey(code);

					if (state[scanCode] == 0) {
						playerOne.recheck(code);
					}
				}
				break;
			case SDL_KEYDOWN:
				SDL_Keycode code = event.key.keysym.sym;

				Controls action = playerOne.getAction(code);
				caseKeyDown(curr, action);

				curr = getCurrScreenFile();
				loadUpdatedWindow();
				break;
			}
		}
	}
}

void caseKeyDown(ScreenFiles curr, Controls action) {
	if (action == NONE) {
		printf("This is not initalized\n");
	}

	switch (curr) {
	case DEFAULT_LOAD:
		// manually writing out the different inputs here, TODO, find better implementation here
		setCurrScreenFile(TRAINING);
		break;
	case TRAINING:
		trainingSet(action);
		break;
	case BUTTONS:
		buttonSet(action);
		break;
	case LOCAL:
		localSet(action);
		break;
	case QUIT:
		quit = quitSet(action);
		break;
	case NEUTRAL_CONTROLLER:
		if (action == KEY_PRESS_BACK) {
			setCurrScreenFile(TRAINING);
		}
	default:
		printf("No output was resulted.\n");
	}
}

void trainingSet(Controls action) {
	if (action == KEY_PRESS_RIGHT) {
		setCurrScreenFile(BUTTONS);
	}
	else if (action == KEY_PRESS_LATK2) {
		printf("This selected nothing, replace afterwards at some point\n");
	}
}

void localSet(Controls action) {
	if (action == KEY_PRESS_LEFT) {
		setCurrScreenFile(BUTTONS);
	}
	else if (action == KEY_PRESS_RIGHT) {
		setCurrScreenFile(QUIT);
	}
	else if (action == KEY_PRESS_LATK2) {
		printf("This selected nothing, replace afterwards at some point\n");
	}
}

bool quitSet(Controls action) {
	if (action == KEY_PRESS_LEFT) {
		setCurrScreenFile(LOCAL);
	}
	else if (action == KEY_PRESS_LATK2) {
		return true;
	}
	return false;
}

void buttonSet(Controls action) {
	if (action == KEY_PRESS_LEFT) {
		setCurrScreenFile(TRAINING);
	} else if (action == KEY_PRESS_RIGHT) {
		setCurrScreenFile(LOCAL);
	}
	else if (action == KEY_PRESS_LATK2) {
		setCurrScreenFile(NEUTRAL_CONTROLLER);
	}
}