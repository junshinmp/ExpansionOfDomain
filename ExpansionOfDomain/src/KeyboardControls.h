#pragma once

#ifndef KEYBOARDCONTROLS_H
#define KEYBOARDCONTROLS_H

#include <SDL.h>
#include <stdio.h>
#include <map>

#include "Controls.h"

/**
* The Keyboard Controls class handles all the bindings for the keyboard
**/
class KeyboardControls {
private:
	/**
	* Mapping of all the bindings for the Keyboard
	**/
	std::map<SDL_Keycode, Controls> keyMappings;

public:
	/**
	* Default Constructor for the KeyboardControls, sets the default bindings
	**/
	KeyboardControls();

	/**
	* Rebinds the current key mapping, removes if already existing elsewhere
	**/
	void rebind(SDL_Keycode rebindKey, Controls action);

	/**
	* Returns the correlating Controls enum with the key push
	**/
	Controls action(SDL_Keycode key);
};

#endif KEYBOARDCONTROLS_H