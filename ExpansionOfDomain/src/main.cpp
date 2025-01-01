#include <SDL.h>
#include <stdio.h>
#include <map>
#include <string>

#include "renderer.h"
#include "ScreenFiles.h"

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 480;

void gameloop();

void gameloop() {
	bool quit = false;
	SDL_Event event;
	
	// processes all gameplay functionality, processing, and the "loop"
	while (!quit)
	{
		// Handle events on queue
		while (SDL_PollEvent(&event) != 0)
		{
			// User requests quit
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		if (!loadScreens(DEFAULT_LOAD)) {
			printf("Background could not be loaded.");
		}
	}

	SDL_Delay(500);

	if (!loadScreens(TRAINING)) {
		printf("Training screen could not be loaded.");
	}

	gameloop();

	//Free resources and close SDL
	cleanUp();

	return 0;
}
