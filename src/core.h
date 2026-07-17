#ifndef CORE_H
#define CORE_H

#include "types.h"
#include "defines.h"

#include "ui.h"

// typedef struct Game Game;
// typedef struct Button Button;

#include "raylib.h"

typedef enum {
	STATE_DEAD  = 0,
	STATE_ALIVE = 1,
} StateType;

typedef struct Game {
	u8 grid[GRID_Y][GRID_X];
	u8 temp_grid[GRID_Y][GRID_X];
	bool is_pause;
	bool is_btn_pressed_and_should_refresh;
	f32 delay;
	f32 timer;
	RenderTexture2D render_target;
	Button btn_randomize;
	Button btn_pause_and_unpause;
	Button btn_speed_up;
	Button btn_speed_down;
	Button btn_rand_alive_color;
	Button btn_rand_dead_color;
	Color alive_color;
	Color dead_color;
} Game;

void randomize_grid(Game *game);
void update_grid(Game *game);

#endif // CORE_H
