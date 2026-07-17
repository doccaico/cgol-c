#ifndef UI_H
#define UI_H

#include "types.h"

#include "raylib.h"

typedef struct Game Game;

typedef enum {
	BUTTON_RANDOMIZE,
	BUTTON_PAUSE_AND_UNPAUSE,
	BUTTON_RAND_ALIVE_COLOR,
	BUTTON_RAND_DEAD_COLOR,
	BUTTON_SPEED_UP,
	BUTTON_SPEED_DOWN,
    BUTTON_FALSE,
} ButtonType;

typedef struct {
	Rectangle bounds;
	const char *text_str;
	i32 text_width;
} Button;

void init_ui(Game *game);
void draw_ui(Game *game);

#endif // UI_H
