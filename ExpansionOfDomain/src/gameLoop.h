#pragma once

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SDL.h>
#include <stdio.h>

#include "Controls.h"
#include "renderer.h"
#include "ScreenFiles.h"
#include "Player.h"

/**
* Processes all game loop functions, handling events and key presses
**/
void gameloop();

/**
* Function to induce clarity within the multiple switch statements following a key press
**/
void caseKeyDown(ScreenFiles curr, Controls action);

/**
* Processes the inputs that occur within the training button in the main menu
**/
void trainingSet(Controls action);

/**
* Process the inputs that occur within the local button in the main menu
**/
void localSet(Controls action);

/**
* Process the inputs that occur within the quit button in the main menu
**/
bool quitSet(Controls action);

/**
* Process the inputs that occur within the button button in the main menu
**/
void buttonSet(Controls action);

#endif GAMELOOP_H