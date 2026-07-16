#ifndef UI_H
#define UI_H

#include "types.h"

struct Game;

#include "raylib.h"

enum Button_Kind {
	Randomize,
	Pause_And_Unpause,
	Rand_Alive_Color,
	Rand_Dead_Color,
	Speed_Up,
	Speed_Down,
};

struct Button {
	Rectangle bounds;
	const char *text_str;
	i32 text_width;
};

void ui_init(struct Game *game);

#endif // UI_H
