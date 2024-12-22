#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool loadBackground();
bool init();
void cleanUp();

SDL_Window* window = NULL;
SDL_Surface* surface = NULL;

bool loadBackground() {

}

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) { printf("Initalization of SDL failed. SDL_Error: %s\n", SDL_GetError()); return false; }
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) { printf("Creation of window failed. SDL_Error: %s\n", SDL_GetError()); return false; }
	surface = SDL_GetWindowSurface(window);
	return true;
}

void cleanUp()
{
	SDL_FreeSurface(surface);

	SDL_DestroyWindow(window);
	
	surface = NULL;
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

	//Free resources and close SDL
	cleanUp();

	return 0;
}
