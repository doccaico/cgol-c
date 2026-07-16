#include <time.h>
#include <stdlib.h>

#include "types.h"
#include "defines.h"

#include "core.h"


void randomize_grid(Game *game) {
	for (int y = 0; y < GRID_Y; y++) {
		for (int x = 0; x < GRID_X; x++) {
			game->grid[y][x] = ((f64)rand() / RAND_MAX < ALIVE_RATIO) ? STATE_ALIVE : STATE_DEAD;
		}
	}
}

// count_neighbors :: #force_inline proc(grid: ^[GRID_Y][GRID_X]State, x: int, y: int) -> int {
// 	count := 0
// 	for dy := -1; dy <= 1; dy += 1 {
// 		for dx := -1; dx <= 1; dx += 1 {
// 			if dx == 0 && dy == 0 do continue
//
// 			nx := x + dx
// 			ny := y + dy
//
// 			if nx >= 0 && nx < GRID_X && ny >= 0 && ny < GRID_Y {
// 				if grid[ny][nx] == .Alive do count += 1
// 			}
// 		}
// 	}
// 	return count
// }
//
// update_grid :: proc(game: ^Game) {
// 	for y := 0; y < GRID_Y; y += 1 {
// 		for x := 0; x < GRID_X; x += 1 {
// 			neighbors := count_neighbors(&game.grid, x, y)
// 			current_state := game.grid[y][x]
//
// 			if current_state == .Alive {
// 				game.temp_grid[y][x] = (neighbors <= 1 || neighbors >= 4) ? .Dead : .Alive
// 			} else {
// 				game.temp_grid[y][x] = (neighbors == 3) ? .Alive : .Dead
// 			}
// 		}
// 	}
// 	// 次世代のデータを現在のデータにコピー
// 	for y := 0; y < GRID_Y; y += 1 {
// 		for x := 0; x < GRID_X; x += 1 {
// 			game.grid[y][x] = game.temp_grid[y][x]
// 		}
// 	}
// }
