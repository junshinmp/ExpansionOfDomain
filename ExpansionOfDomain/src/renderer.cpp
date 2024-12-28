#include <SDL.h>

#include "renderer.h"

bool loadScreen(SDL_Surface * background, const char* pathway) {
	background = SDL_LoadBMP(pathway);
	if (background == NULL) {
		return false;
	}
	return true;
}