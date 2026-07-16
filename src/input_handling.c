#include "defines.h"

#include "core.h"

#include "raylib.h"

bool is_btn_pressed(Game *game, ButtonType btn) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Rectangle bounds;
        switch (btn) {
            case BUTTON_RANDOMIZE:
                bounds = game->btn_randomize.bounds;
                break;
            case BUTTON_PAUSE_AND_UNPAUSE:
                bounds = game->btn_pause_and_unpause.bounds;
                break;
            case BUTTON_SPEED_UP:
                bounds = game->btn_speed_up.bounds;
                break;
            case BUTTON_SPEED_DOWN:
                bounds = game->btn_speed_down.bounds;
                break;
            case BUTTON_RAND_ALIVE_COLOR:
                bounds = game->btn_rand_alive_color.bounds;
                break;
            case BUTTON_RAND_DEAD_COLOR:
                bounds = game->btn_rand_dead_color.bounds;
                break;
            default:
                return false;
        }
        Vector2 mouse_pos = GetMousePosition();
        if (CheckCollisionPointRec(mouse_pos, bounds)) {
            return true;
        }
    }
    return false;
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void input_handling(Game *game) {
	if (IsKeyPressed(KEY_R) || is_btn_pressed(game, BUTTON_RANDOMIZE)) {
		game->is_btn_pressed_and_should_refresh = true;
		randomize_grid(game);
	}
	if (IsKeyPressed(KEY_P) || is_btn_pressed(game, BUTTON_PAUSE_AND_UNPAUSE)) {
		game->is_pause = !game->is_pause;
	}
	if (IsKeyPressed(KEY_W) || is_btn_pressed(game, BUTTON_SPEED_UP)) {
		game->delay = (f32)MAX(MIN_DELAY, game->delay - DELAY_VALUE);
	}
	if (IsKeyPressed(KEY_S) || is_btn_pressed(game, BUTTON_SPEED_DOWN)) {
		game->delay = (f32)MIN(MAX_DELAY, game->delay + DELAY_VALUE);
	}
	if (IsKeyPressed(KEY_A) || is_btn_pressed(game, BUTTON_RAND_ALIVE_COLOR)) {
		game->is_btn_pressed_and_should_refresh = true;
        Color color = {(u8)GetRandomValue(0, 255), (u8)GetRandomValue(0, 255), (u8)GetRandomValue(0, 255), 255};
		game->alive_color = color;
	}
	if (IsKeyPressed(KEY_D) || is_btn_pressed(game, BUTTON_RAND_DEAD_COLOR)) {
		game->is_btn_pressed_and_should_refresh = true;
        Color color = {(u8)GetRandomValue(0, 255), (u8)GetRandomValue(0, 255), (u8)GetRandomValue(0, 255), 255};
		game->dead_color = color;
	}
}

#undef MAX
#undef MIN
