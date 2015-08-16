#ifndef _GAME_H_
#define _GAME_H_

/* Standard libraries */
#include <stdio.h>
#include <string.h>

/* External libraries */
#include "cab202_graphics.h"
#include "player.h"

/* Definitions */
#define String char*

void draw_level( int level, int lives, int score );

#endif