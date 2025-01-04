#include <SDL.h>
#include <stdio.h>
#include <map>

#include "renderer.h"
#include "ScreenFiles.h"

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 480;

/**
* Processes all game loop functions, handling events and key presses
**/
void gameloop();

void gameloop() {
	bool quit = false;
	SDL_Event event;
	
	// processes all gameplay functionality, processing, and the "loop"
	while (!quit)
	{
		// Handle events on queue
		// will also split into three different functions dependent on what specific screen the user is on
		// i.e: in the main menu, training
		// only done on keyboard currently
		ScreenFiles curr = getCurrScreenFile();

		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type) {
				// checking for quit
			case SDL_QUIT:
				quit = true;
				break;
				// checking for if user pushes down a key
			case SDL_KEYDOWN:

				switch (curr) {
				case DEFAULT_LOAD:
					// manually writing out the different inputs here, TODO, find better implementation here
					break;
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
