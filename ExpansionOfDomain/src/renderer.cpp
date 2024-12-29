#include <SDL.h>
#include <stdio.h>

#include "renderer.h"

bool loadScreens(SDL_Surface*& background, const char* pathway) {
	background = SDL_LoadBMP(pathway);
	if (background == NULL) {
		return false;
	}
	return true;
}

SDL_Surface* loadSurface(const char* pathway) {
	SDL_Surface* currLoad = SDL_LoadBMP(pathway);
	if (currLoad == NULL) {
		printf("Current surface could not be loaded at the specified pathway.");
	}
	return currLoad;
}



			