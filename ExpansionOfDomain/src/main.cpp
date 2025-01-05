#include <SDL.h>
#include <stdio.h>
#include <map>

#include "renderer.h"
#include "ScreenFiles.h"
#include "Controls.h"
#include "Player.h"

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 480;

/**
* Processes all game loop functions, handling events and key presses
**/
void gameloop();

void gameloop() {

	bool quit = false;
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
			case SDL_KEYDOWN:
				Controls action = playerOne.getAction(event.key.keysym.sym);
				switch (curr) {
				case DEFAULT_LOAD:
					// manually writing out the different inputs here, TODO, find better implementation here
					setCurrScreenFile(TRAINING);
					break;
				case TRAINING:
					if (action == KEY_PRESS_RIGHT) {
						setCurrScreenFile(LOCAL);
					}
					else if (action == KEY_PRESS_LATK2) {
						setCurrScreenFile(NEUTRAL_CONTROLLER);
					}
					break;
				case LOCAL:
					if (action == KEY_PRESS_LEFT) {
						setCurrScreenFile(TRAINING);
					}
					else if (action == KEY_PRESS_RIGHT) {
						setCurrScreenFile(QUIT);
					}
					else if(action == KEY_PRESS_LATK2) {
						printf("This selected nothing, replace afterwards at some point");
					}
				case QUIT:
					if (action == KEY_PRESS_LEFT) {
						setCurrScreenFile(LOCAL);
					}
					else if (action == KEY_PRESS_LATK2) {
						quit = true;
					}
				}

				break;
			}
		}
	}
}

/**
* Initalizes SDL and runs all necessary functions.
**/
int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		if (!loadScreens()) {
			printf("Background could not be loaded.");
		}
	}

	// starts the game loop
	gameloop();

	//Free resources and close SDL
	cleanUp();

	return 0;
}
