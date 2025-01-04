#include <SDL.h>
#include <stdio.h>
#include <map>

#include "KeyboardControls.h"
#include "Controls.h"

/**
* Sets the default bindings here with the proper Controls Enum
**/
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

void KeyboardControls::rebind(SDL_Keycode key, Controls action) {
	// removes binding if it already exists under other "action"
	for (auto curr = keyMappings.begin(); curr != keyMappings.end(); ++curr) {
		if (curr->second == action) {
			// deletes from the mapping here
			keyMappings.erase(curr);
			break;
		}
	}
	// now sets the new key to the action in the map
	keyMappings[key] = action;
}

Controls KeyboardControls::action(SDL_Keycode input) {
	// below, just checks that the input exists
	auto inputted = keyMappings.find(input);
	// if it does not, then returns the NONE value from the Controls Enums.
	if (inputted != keyMappings.end()) {
		return Controls::NONE;
	}
	// or if it does exist, then returns with the at() function since it confidently exists.
	return keyMappings.at(input);
	
}