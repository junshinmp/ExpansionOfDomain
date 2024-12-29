#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <stdio.h>

bool loadScreens(SDL_Surface *& background, const char* pathway);

SDL_Surface* loadSurface(const char* pathway);

#endif RENDERER_H
