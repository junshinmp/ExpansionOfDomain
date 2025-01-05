#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "KeyboardControls.h"
#include "Controls.h"

class Player {
public: 
	/**
	* Default Constructor for Player Object
	**/
	Player();

	/**
	* Rebinds the current Player's keyboard bindings to the new key
	**/
	void rebind(SDL_Keycode key, Controls action);

	/**
	* Returns the action that the player is attempting to perform with the key
	**/
	Controls getAction(SDL_Keycode key);

	/**
	* Sets the side of the player (true = left, false = right)
	**/
	void setSide(bool side);

private:
	// Players respective keyboard bindings
	KeyboardControls bindings;

	// TODO add joystick Controls at some point

	// Checks if user has a controller plugged in, then behaves differently on rebindings
	bool controllerPlugged;

	// Checks what side the user wants to start on the screen (left = true, right = false)
	bool startLeft;
};

#endif PLAYER_H