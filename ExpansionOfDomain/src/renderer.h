#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <stdio.h>
#include "ScreenFiles.h"

bool init();

void cleanUp();

bool loadScreens();

SDL_Surface* loadSurface(const char* pathway);

ScreenFiles getCurrScreenFile();

#endif RENDERER_H
