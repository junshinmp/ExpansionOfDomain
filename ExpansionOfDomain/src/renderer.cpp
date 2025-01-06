#include <SDL.h>
#include <stdio.h>
#include <map>

#include "renderer.h"
#include "ScreenFiles.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

ScreenFiles curr = DEFAULT_LOAD;  // simply maintains the current screen that the user is one (i.e. menu)
SDL_Window* window = nullptr;
SDL_Surface* surface = nullptr;
SDL_Surface* background = nullptr;

std::map<ScreenFiles, SDL_Surface*> SurfaceImages; // holds the loaded Surface images in a map, using Enums as the key

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) { return false; }
	window = SDL_CreateWindow("Expansion of Domain", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) { return false; }
	surface = SDL_GetWindowSurface(window);
	return true;
}

void cleanUp() {
	// goes through each of the Screen files and frees it from memory
	for (int i = 0; i < TOTAL_SCREEN_FILES; i++) {
		SDL_FreeSurface(SurfaceImages[static_cast<ScreenFiles>(i)]);
		SurfaceImages[static_cast<ScreenFiles>(i)] = nullptr;
	}

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}

bool loadScreens() {
	bool success = true;

	// doing all the preloading prior to anything else since the game does not have much to preload.
	// loads the main menu elements first
	SurfaceImages[DEFAULT_LOAD] = loadSurface("res/NeutralSelectr.bmp");
	SurfaceImages[TRAINING] = loadSurface("res/TrainingSelect.bmp");
	SurfaceImages[LOCAL] = loadSurface("res/LocalSelect.bmp");
	SurfaceImages[QUIT] = loadSurface("res/QuitSelect.bmp");
	
	// loads the menu for checking controls
	SurfaceImages[NEUTRAL_CONTROLLER] = loadSurface("res/NeutralControlPanel.bmp");
	SurfaceImages[BACKWARDS] = loadSurface("res/Back.bmp");
	SurfaceImages[FORWARDS] = loadSurface("res/Right.bmp");
	SurfaceImages[UP] = loadSurface("res/Up.bmp");
	SurfaceImages[DOWN] = loadSurface("res/Down.bmp");
	SurfaceImages[UP_FORWARDS]= loadSurface("res/ForwardRight.bmp");
	SurfaceImages[UP_BACKWARDS] = loadSurface("res/ForwardLeft.bmp");
	SurfaceImages[DOWN_BACKWARDS] = loadSurface("res/DownLeft.bmp");
	SurfaceImages[DOWN_FORWARDS] = loadSurface("res/DownRight.bmp");
	SurfaceImages[LATTACK1] = loadSurface("res/Move1.bmp");
	SurfaceImages[MATTACK1] = loadSurface("res/Move2.bmp");
	SurfaceImages[HATTACK1] = loadSurface("res/Move3.bmp");
	SurfaceImages[LATTACK2] = loadSurface("res/Move4.bmp");
	SurfaceImages[MATTACK2] = loadSurface("res/Move5.bmp");
	SurfaceImages[HATTACK2] = loadSurface("res/Move6.bmp");
	
	// does a check to if the process failed for any of the screens.
	for (int i = 0; i < TOTAL_SCREEN_FILES; i++) {
		if (SurfaceImages[static_cast<ScreenFiles>(i)] == NULL) {
			success = false;
		}
	}

	// simply puts the current image now onto the window prior to any more rendering
	if (success) {
		loadUpdatedWindow();
		// small delay just for cool transition
		SDL_Delay(500);
		curr = TRAINING;
		loadUpdatedWindow();
	}

	return success;
}

SDL_Surface* loadSurface(const char* pathway) {
	SDL_Surface* currLoad = SDL_LoadBMP(pathway);
	if (currLoad == NULL) {
		printf("Current surface could not be loaded at the specified pathway.");
	}
	return currLoad;
}

ScreenFiles getCurrScreenFile() {
	return curr;
}

void setCurrScreenFile(ScreenFiles newScreenFiles) {
	curr = newScreenFiles;
}

void loadUpdatedWindow() {
	background = SurfaceImages.at(curr);
	SDL_BlitSurface(background, NULL, surface, NULL);
	SDL_UpdateWindowSurface(window);
}
