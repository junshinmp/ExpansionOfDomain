#include <SDL.h>
#include <stdio.h>

#include "Player.h"
#include "KeyboardControls.h"
#include "Controls.h"

void Player::rebind(SDL_Keycode key, Controls action) {
	bindings.rebind(key, action);
}

Controls Player::getAction(SDL_Keycode key) {
	return bindings.action(key);
}