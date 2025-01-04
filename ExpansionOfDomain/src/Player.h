#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "KeyboardControls.h"
#include "Controls.h"

class Player {
public: 
	void rebind(SDL_Keycode key, Controls action);

	Controls getAction(SDL_Keycode key);
private:
	KeyboardControls bindings;
	// add joystick Controls at some point
	bool controllerPlugged;
	bool sideStart;
};

#endif PLAYER_H