#pragma once

#ifndef KEYBOARDCONTROLS_H
#define KEYBOARDCONTROLS_H

#include <SDL.h>
#include <stdio.h>
#include <map>

#include "Controls.h"

class KeyboardControls {
private:
	std::map<SDL_Keycode, Controls> keyMappings;

public:
	KeyboardControls();

	void rebind(SDL_Keycode rebindKey, Controls action);

	Controls action(SDL_Keycode);
};

#endif KEYBOARDCONTROLS_H