#include <SDL.h>
#include <stdio.h>
#include <map>

#include "renderer.h"
#include "ScreenFiles.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

ScreenFiles curr = DEFAULT_LOAD;  // simply maintains the current screen that the user is one (i.e. menu)
SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
SDL_Surface* background = NULL;

std::map<ScreenFiles, const char*> resources; // map holding the pathways to each bmp file, using Enums as the key

bool init()
{
	// map for all the files that are going to be used
	resources = {
		// Starting Menu Elements
		{DEFAULT_LOAD, "res/NeutralSelectr.bmp"},
		{TRAINING, "res/TrainingSelect.bmp" },
		{LOCAL, "res/LocalSelect.bmp"},
		{QUIT, "res/QuitSelect.bmp"},

		// Button Presses
		{BACKWARDS, "res/Back.bmp"},
		{FORWARDS, "res/Right.bmp"},
		{UP, "res/Up.bmp"},
		{DOWN, "res/Down.bmp"},
		{UP_FORWARDS, "res/ForwardRight.bmp"},
		{UP_BACKWARDS, "res/ForwardLeft.bmp"},
		{DOWN_BACKWARDS, "res/DownLeft.bmp"},
		{DOWN_FORWARDS, "res/DownRight.bmp"},
		{LATTACK1, "res/Move1.bmp"},
		{MATTACK1, "res/Move2.bmp"},
		{HATTACK1, "res/Move3.bmp"},
		{LATTACK2, "res/Move4.bmp"},
		{MATTACK2, "res/Move5.bmp"},
		{HATTACK2, "res/Move6.bmp"}
	};

	if (SDL_Init(SDL_INIT_VIDEO) < 0) { return false; }
	window = SDL_CreateWindow("Expansion of Domain", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) { return false; }
	surface = SDL_GetWindowSurface(window);
	return true;
}

void cleanUp() {
	SDL_FreeSurface(background);
	SDL_DestroyWindow(window);

	background = NULL;
	window = NULL;

	SDL_Quit();
}

bool loadScreens(ScreenFiles load) {
	background = SDL_LoadBMP(resources.at(load));
	if (background == NULL) {
		return false;
	}

	SDL_BlitSurface(background, NULL, surface, NULL);
	SDL_UpdateWindowSurface(window);

	return true;
}

SDL_Surface* loadSurface(const char* pathway) {
	SDL_Surface* currLoad = SDL_LoadBMP(pathway);
	if (currLoad == NULL) {
		printf("Current surface could not be loaded at the specified pathway.");
	}
	return currLoad;
}
