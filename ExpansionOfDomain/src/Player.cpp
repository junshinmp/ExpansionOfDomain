#include <SDL.h>
#include <stdio.h>

#include "Player.h"
#include "KeyboardControls.h"
#include "Controls.h"

Player::Player(): bindings(), controllerPlugged(false), startLeft(true){ 
	controllerPlugged = SDL_NumJoysticks() > 0;
}

void Player::rebind(SDL_Keycode key, Controls action) {
	// calls KeyboardControls rebinding function
	bindings.rebind(key, action);
}

Controls Player::getAction(SDL_Keycode key) {
	// calls KeyboardControls action function
	return bindings.action(key);
}

void Player::setSide(bool side) {
	startLeft = side;
}