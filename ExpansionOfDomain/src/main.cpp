#include <SDL.h>
#include <stdio.h>
#include <map>

#include "renderer.h"
#include "gameLoop.h"

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 480;

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
			printf("Background could not be loaded.\n");
		}
	}

	// starts the game loop
	gameloop();

	//Free resources and close SDL
	cleanUp();

	return 0;
}
