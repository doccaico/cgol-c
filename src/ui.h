#ifndef UI_H
#define UI_H

#include "types.h"

typedef struct Game Game;
// #include "core.h"


#include "raylib.h"

typedef enum {
	BUTTON_RANDOMIZE,
	BUTTON_PAUSE_AND_UNPAUSE,
	BUTTON_RAND_ALIVE_COLOR,
	BUTTON_RAND_DEAD_COLOR,
	BUTTON_SPEED_UP,
	BUTTON_SPEED_DOWN,
} ButtonType;

typedef struct {
	Rectangle bounds;
	const char *text_str;
	i32 text_width;
} Button;

void ui_init(Game *game);

#endif // UI_H
