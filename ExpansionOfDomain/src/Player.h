#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "KeyboardControls.h"
#include "Controls.h"

class Player {
public: 
	/**
	* Rebinds the current Player's keyboard bindings to the new key
	**/
	void rebind(SDL_Keycode key, Controls action);

	/**
	* Returns the action that the player is attempting to perform with the key
	**/
	Controls getAction(SDL_Keycode key);

private:
	// Players respective keyboard bindings
	KeyboardControls bindings;

	// TODO add joystick Controls at some point

	// Checks if user has a controller plugged in, then behaves differently on rebindings
	bool controllerPlugged;

	// Checks what side the user wants to start on the screen
	bool sideStart;
};

#endif PLAYER_H