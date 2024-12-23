#include <SDL.h>
#include <stdio.h>

#include "renderer.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;
const int SCREEN_MS_PER_FRAME = 1000 / SCREEN_FPS;

void gameloop();
bool newBackground();
bool init();
void cleanUp();

SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
SDL_Surface* background = NULL;

void gameloop() {
	bool quit = false;
	SDL_Event event;
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

bool newBackground() 
{
	background = SDL_LoadBMP("res/mountains-7728691_640.bmp");
	if (background == NULL) {
		return false;
	}
	return true;
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
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		if (!newBackground()) {
			printf("Background could not be loaded.");
		}
		else {
			SDL_BlitSurface(background, NULL, surface, NULL);
			SDL_UpdateWindowSurface(window);
		}
	}

	gameloop();

	//Free resources and close SDL
	cleanUp();

	return 0;
}
