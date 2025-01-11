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
	keyMappings[SDLK_SPACE] = KEY_PRESS_UP;
	keyMappings[SDLK_s] = KEY_PRESS_DOWN;
	keyMappings[SDLK_a] = KEY_PRESS_LEFT;
	keyMappings[SDLK_d] = KEY_PRESS_RIGHT;
	keyMappings[SDLK_u] = KEY_PRESS_LATK1;
	keyMappings[SDLK_i] = KEY_PRESS_MATK1;
	keyMappings[SDLK_o] = KEY_PRESS_HATK1;
	keyMappings[SDLK_j] = KEY_PRESS_LATK2;
	keyMappings[SDLK_k] = KEY_PRESS_MATK2;
	keyMappings[SDLK_l] = KEY_PRESS_HATK2;
	keyMappings[SDLK_BACKSPACE] = KEY_PRESS_START;
	keyMappings[SDLK_ESCAPE] = KEY_PRESS_BACK;
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
	if (inputted == keyMappings.end()) {
		return Controls::NONE;
	}

	// or if it does exist, then collects it and adds it to set, keysDown 
	Controls curr = keyMappings.at(input);

	// check for the multiple inputs here, checks it upon other the other pressed down actions
	for (SDL_Keycode downKey : keysDown) {
		if (downKey != input) {
			curr = simutanousInput(curr, keyMappings.at(downKey));
		}
	}

	buttonPressed(input);
	return curr;
}
Controls KeyboardControls::recheck(SDL_Keycode input) {
	buttonReleased(input);
	return Controls::NONE;
}

Controls KeyboardControls::simutanousInput(Controls first, Controls second) {
	// Left and right cancel out, up and down cancel out
	if (first == KEY_PRESS_LEFT and second == KEY_PRESS_RIGHT || first == KEY_PRESS_RIGHT and second == KEY_PRESS_LEFT ||
		first == KEY_PRESS_UP and second == KEY_PRESS_DOWN || first == KEY_PRESS_DOWN and second == KEY_PRESS_UP) {
		printf("Input was canceled out\n");
		return Controls::NONE;
	}
	// left and down goes to down left
	else if (first == KEY_PRESS_LEFT and second == KEY_PRESS_DOWN || first == KEY_PRESS_DOWN and second == KEY_PRESS_LEFT) {
		printf("Down left was inputted\n");
		return KEY_PRESS_LDOWN;
	}
	// same thing above, but right
	else if (first == KEY_PRESS_RIGHT and second == KEY_PRESS_DOWN || first == KEY_PRESS_DOWN and second == KEY_PRESS_RIGHT) {
		printf("Down right was inputted\n");
		return KEY_PRESS_RDOWN;
	}
	// left and up goes up left
	else if (first == KEY_PRESS_LEFT and second == KEY_PRESS_UP || first == KEY_PRESS_UP and second == KEY_PRESS_RIGHT) {
		printf("Up left was inputted\n");
		return KEY_PRESS_LUP;
	}
	// right and up goes up right
	else if (first == KEY_PRESS_RIGHT and second == KEY_PRESS_UP || first == KEY_PRESS_UP and second == KEY_PRESS_RIGHT) {
		printf("Up right was inputted\n");
		return KEY_PRESS_RUP;
	}
	// since no combo, returns initial Control
	printf("returned initial control\n");
	return first;
}

void KeyboardControls::buttonPressed(SDL_Keycode input) {
	keysDown.insert(input);
}

void KeyboardControls::buttonReleased(SDL_Keycode input) {
	keysDown.erase(input);
}