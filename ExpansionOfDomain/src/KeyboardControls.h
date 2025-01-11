#pragma once

#ifndef KEYBOARDCONTROLS_H
#define KEYBOARDCONTROLS_H

#include <SDL.h>
#include <stdio.h>
#include <map>
#include <set>

#include "Controls.h"

/**
* The Keyboard Controls class handles all the bindings for the keyboard
**/
class KeyboardControls {
private:
	// Mapping of all the bindings for the Keyboard
	std::map<SDL_Keycode, Controls> keyMappings;

	// Set of all the inputs that are currently pushed down
	std::set<SDL_Keycode> keysDown;

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

	/**
	* After button is released does a recheck on the current state
	**/
	Controls recheck(SDL_Keycode input);

	/**
	* Returns the combination of both inputs if there is an existing combo, otherwise, returns the first Control ENUM
	**/
	Controls simutanousInput(Controls first, Controls second);

	/**
	* Adds the current pushed down input into the set of pushed down buttons
	**/
	void buttonPressed(SDL_Keycode input);

	/**
	* Removes the input that was released
	**/
	void buttonReleased(SDL_Keycode input);
};

#endif KEYBOARDCONTROLS_H