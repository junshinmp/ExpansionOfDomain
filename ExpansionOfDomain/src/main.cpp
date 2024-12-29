#include <SDL.h>
#include <stdio.h>
#include <map>
#include <string>

#include "renderer.h"
#include "ScreenFiles.h"

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 480;

void gameloop();
bool init();
void cleanUp();

ScreenFiles curr = DEFAULT_LOAD;  // simply maintains the current screen that the user is one (i.e. menu)
SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
SDL_Surface* background = NULL;
std::map<ScreenFiles, const char*> resources;

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

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) { return false; }
	window = SDL_CreateWindow("Expansion of Domain", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) { return false; }
	surface = SDL_GetWindowSurface(window);
	return true;
}

void cleanUp()
{
	SDL_FreeSurface(background);
	SDL_DestroyWindow(window);
	
	background = NULL;
	window = NULL;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	// map for all the files that are going to be used
	resources = {
		{DEFAULT_LOAD, "res/NeutralSelectr.bmp"},
		{TRAINING, "res/TrainingSelect.bmp" },
		{LOCAL, "res/LocalSelect.bmp"},
		{QUIT, "res/QuitSelect.bmp"}
	};

	printf(resources.at(DEFAULT_LOAD));
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		if (!loadScreens(background, resources.at(DEFAULT_LOAD))) {
			printf("Background could not be loaded.");
		}
		else {
			SDL_BlitSurface(background, NULL, surface, NULL);
			SDL_UpdateWindowSurface(window);
		}
	}

	SDL_Delay(500);

	if (!loadScreens(background, resources.at(TRAINING))) {
		printf("Training screen could not be loaded.");
	}
	else {
		SDL_BlitSurface(background, NULL, surface, NULL);
		SDL_UpdateWindowSurface(window);
	}
	curr = TRAINING;

	gameloop();

	//Free resources and close SDL
	cleanUp();

	return 0;
}
