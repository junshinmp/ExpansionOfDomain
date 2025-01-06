#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <stdio.h>

#include "ScreenFiles.h"

/**
* Initalizes SDL2, sets up the window
**/
bool init();

/**
* Cleans up any assets that were used in the program
**/
void cleanUp();

/**
* Preloads all the screens that are going to be used in the game
* 
**/
bool loadScreens();

/**
* Loads the pathway surface for future use
**/
SDL_Surface* loadSurface(const char* pathway);

/**
* returns what the current screen file is
**/
ScreenFiles getCurrScreenFile();

/**
* sets the current ScreenFile
**/
void setCurrScreenFile(ScreenFiles newScreenFiles);

/**
* blits and updates the window to the current correct screen
**/
void loadUpdatedWindow();

#endif RENDERER_H
