#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "types.h"
#include "defines.h"

#include "core.h"

static i32 count_neighbors(u8 grid[GRID_Y][GRID_X], i32 x, i32 y) {
	i32 count = 0;
	for (i32 dy = -1; dy <= 1; dy++) {
		for (i32 dx = -1; dx <= 1; dx++) {
			if (dx == 0 && dy == 0) continue;

			i32 nx = x + dx;
			i32 ny = y + dy;

			if (nx >= 0 && nx < GRID_X && ny >= 0 && ny < GRID_Y) {
				if (grid[ny][nx] == STATE_ALIVE) count += 1;
			}
		}
	}
	return count;
}

void randomize_grid(Game *game) {
	for (i32 y = 0; y < GRID_Y; y++) {
		for (i32 x = 0; x < GRID_X; x++) {
			game->grid[y][x] = ((f64)rand() / RAND_MAX < ALIVE_RATIO) ? STATE_ALIVE : STATE_DEAD;
		}
	}
}

void update_grid(Game *game) {
	for (i32 y = 0; y < GRID_Y; y++) {
		for (i32 x = 0; x < GRID_X; x++) {
			i32 neighbors = count_neighbors(game->grid, x, y);
			u8 current_state = game->grid[y][x];

			if (current_state == STATE_ALIVE) {
				game->temp_grid[y][x] = (neighbors <= 1 || neighbors >= 4) ? STATE_DEAD : STATE_ALIVE;
			} else {
				game->temp_grid[y][x] = (neighbors == 3) ? STATE_ALIVE : STATE_DEAD;
			}
		}
	}
    memcpy(game->grid, game->temp_grid, sizeof(game->grid));
}
