#include <SDL.h>
#include <stdio.h>
#include <map>

#include "KeyboardControls.h"
#include "Controls.h"

KeyboardControls::KeyboardControls() {
	// sets the default buttons for keyboard
	keyMappings[SDLK_w] = KEY_PRESS_UP;
	keyMappings[SDLK_s] = KEY_PRESS_DOWN;
	keyMappings[SDLK_a] = KEY_PRESS_LEFT;
	keyMappings[SDLK_d] = KEY_PRESS_RIGHT;
	keyMappings[SDLK_u] = KEY_PRESS_LATK1;
	keyMappings[SDLK_i] = KEY_PRESS_MATK1;
	keyMappings[SDLK_o] = KEY_PRESS_HATK1;
	keyMappings[SDLK_j] = KEY_PRESS_LATK2;
	keyMappings[SDLK_k] = KEY_PRESS_MATK2;
	keyMappings[SDLK_l] = KEY_PRESS_HATK2;
}

bool KeyboardControls::rebind(SDL_Keycode, Controls action) {
	// checks if button is already set.
	return true;
}

Controls KeyboardControls::action(SDL_Keycode input) {
	return keyMappings.at(input);
}