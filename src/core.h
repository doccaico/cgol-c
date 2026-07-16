#ifndef CORE_H
#define CORE_H

#include "types.h"
#include "defines.h"

#include "ui.h"

#include "raylib.h"

enum StateType {
	STATE_DEAD  = 0,
	STATE_ALIVE = 1,
};

struct Game {
	u8 grid[GRID_Y][GRID_X];
	u8 temp_grid[GRID_Y][GRID_X];
	bool is_pause;
	bool is_btn_pressed_and_should_refresh;
	f32 delay;
	f32 timer;
	RenderTexture2D render_target;
	struct Button btn_randomize;
	struct Button btn_pause_and_unpause;
	struct Button btn_speed_up;
	struct Button btn_speed_down;
	struct Button btn_rand_alive_color;
	struct Button btn_rand_dead_color;
	Color alive_color;
	Color dead_color;
};

#endif // CORE_H
