#include <SDL.h>
#include <stdio.h>

#include "Player.h"
#include "KeyboardControls.h"
#include "Controls.h"

void Player::rebind(SDL_Keycode key, Controls action) {
	// calls KeyboardControls rebinding function
	bindings.rebind(key, action);
}

Controls Player::getAction(SDL_Keycode key) {
	// calls KeyboardControls action function
	return bindings.action(key);
}