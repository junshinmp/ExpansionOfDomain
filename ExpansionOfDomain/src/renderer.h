#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <stdio.h>
#include "ScreenFiles.h"

bool init();

void cleanUp();

bool loadScreens(ScreenFiles load);

SDL_Surface* loadSurface(const char* pathway);

#endif RENDERER_H
