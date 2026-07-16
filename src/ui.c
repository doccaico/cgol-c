#include "types.h"
#include "defines.h"

#include "core.h"

#include "raylib.h"

#define SPACE 4
void ui_init(struct Game *game) {
    {
        const char *str = "(R)Randomize";
        game->btn_randomize = (struct Button){
            .bounds = {
                (f32)BTN_AREA_X + SPACE,
                (f32)BTN_AREA_Y + SPACE,
                (f32)BTN_WIDTH - SPACE * 2,
                (f32)(WINDOW_HEIGHT - BTN_AREA_Y) / 2 - SPACE * 2,
            },
            .text_str = str,
            .text_width = MeasureText(str, BTN_FONT_SIZE),
        };
    }
    {
        const char *str = "(P)Pause/Unpause";
        game->btn_pause_and_unpause = (struct Button){
            .bounds = {
                (f32)BTN_AREA_X + SPACE,
                (f32)BTN_AREA_Y + BTN_HEIGHT + SPACE,
                (f32)BTN_WIDTH - SPACE * 2,
                (f32)(WINDOW_HEIGHT - BTN_AREA_Y) / 2 - SPACE * 2,
            },
            .text_str = str,
            .text_width = MeasureText(str, BTN_FONT_SIZE),
        };
    }
    {
        const char *str = "(W)Speed Up";
        game->btn_speed_up = (struct Button){
            .bounds = {
                (f32)BTN_AREA_X + BTN_WIDTH * 1 + SPACE,
                (f32)BTN_AREA_Y + SPACE,
                (f32)BTN_WIDTH - SPACE * 2,
                (f32)(WINDOW_HEIGHT - BTN_AREA_Y) / 2 - SPACE * 2,
            },
            .text_str = str,
            .text_width = MeasureText(str, BTN_FONT_SIZE),
        };
    }
    {
        const char *str = "(S)Speed Down";
        game->btn_speed_down = (struct Button){
            .bounds = {
                (f32)BTN_AREA_X + BTN_WIDTH * 1 + SPACE,
                (f32)BTN_AREA_Y + BTN_HEIGHT + SPACE,
                (f32)BTN_WIDTH - SPACE * 2,
                (f32)(WINDOW_HEIGHT - BTN_AREA_Y) / 2 - SPACE * 2,
            },
            .text_str = str,
            .text_width = MeasureText(str, BTN_FONT_SIZE),
        };
    }
    {
        const char *str = "(A)Rand ALIVE Color";
        game->btn_rand_alive_color = (struct Button){
            .bounds = {
                (f32)BTN_AREA_X + BTN_WIDTH * 2 + SPACE,
                (f32)BTN_AREA_Y + SPACE,
                (f32)BTN_WIDTH - SPACE * 2,
                (f32)(WINDOW_HEIGHT - BTN_AREA_Y) / 2 - SPACE * 2,
            },
            .text_str   = str,
            .text_width = MeasureText(str, BTN_FONT_SIZE),
        };
    }
    {
        const char *str = "(D)Rand DEAD Color";
        game->btn_rand_dead_color = (struct Button){
            .bounds = {
                (f32)BTN_AREA_X + BTN_WIDTH * 2 + SPACE,
                (f32)BTN_AREA_Y + BTN_HEIGHT + SPACE,
                (f32)BTN_WIDTH - SPACE * 2,
                (f32)(WINDOW_HEIGHT - BTN_AREA_Y) / 2 - SPACE * 2,
            },
            .text_str = str,
            .text_width = MeasureText(str, BTN_FONT_SIZE),
        };
    }
}
#undef SPACE

// draw_ui :: proc(game: ^Game) {
// 	SPACE: i32 : 26
// 	// Randomize
// 	{
// 		x, y := i32(game.btn_randomize.bounds.x), i32(game.btn_randomize.bounds.y)
// 		width, height :=
// 			i32(game.btn_randomize.bounds.width), i32(game.btn_randomize.bounds.height)
// 		text_width := game.btn_randomize.text_width
// 		rl.DrawRectangleLinesEx(game.btn_randomize.bounds, 2, BTN_LINE_COLOR)
// 		rl.DrawText(
// 			game.btn_randomize.text_str,
// 			(width - text_width) / 2,
// 			y + SPACE,
// 			BTN_FONT_SIZE,
// 			BTN_TEXT_COLOR,
// 		)
// 	}
// 	// Pause/Unpause
// 	{
// 		x, y := i32(game.btn_pause_and_unpause.bounds.x), i32(game.btn_pause_and_unpause.bounds.y)
// 		width, height :=
// 			i32(game.btn_pause_and_unpause.bounds.width),
// 			i32(game.btn_pause_and_unpause.bounds.height)
// 		text_width := game.btn_pause_and_unpause.text_width
// 		rl.DrawRectangleLinesEx(game.btn_pause_and_unpause.bounds, 2, BTN_LINE_COLOR)
// 		rl.DrawText(
// 			game.btn_pause_and_unpause.text_str,
// 			(width - text_width) / 2,
// 			y + SPACE,
// 			BTN_FONT_SIZE,
// 			BTN_TEXT_COLOR,
// 		)
// 	}
// 	// Speed Up
// 	{
// 		x, y := i32(game.btn_speed_up.bounds.x), i32(game.btn_speed_up.bounds.y)
// 		width, height := i32(game.btn_speed_up.bounds.width), i32(game.btn_speed_up.bounds.height)
// 		text_width := game.btn_speed_up.text_width
// 		rl.DrawRectangleLinesEx(game.btn_speed_up.bounds, 2, BTN_LINE_COLOR)
// 		rl.DrawText(
// 			game.btn_speed_up.text_str,
// 			(BTN_WIDTH * 1) + (width - text_width) / 2,
// 			y + SPACE,
// 			BTN_FONT_SIZE,
// 			BTN_TEXT_COLOR,
// 		)
// 	}
// 	// Speed Down
// 	{
// 		x, y := i32(game.btn_speed_down.bounds.x), i32(game.btn_speed_down.bounds.y)
// 		width, height :=
// 			i32(game.btn_speed_down.bounds.width), i32(game.btn_speed_down.bounds.height)
// 		text_width := game.btn_speed_down.text_width
// 		rl.DrawRectangleLinesEx(game.btn_speed_down.bounds, 2, BTN_LINE_COLOR)
// 		rl.DrawText(
// 			game.btn_speed_down.text_str,
// 			(BTN_WIDTH * 1) + (width - text_width) / 2,
// 			y + SPACE,
// 			BTN_FONT_SIZE,
// 			BTN_TEXT_COLOR,
// 		)
// 	}
// 	// Rand ALIVE Color
// 	{
// 		x, y := i32(game.btn_rand_alive_color.bounds.x), i32(game.btn_rand_alive_color.bounds.y)
// 		width, height :=
// 			i32(game.btn_rand_alive_color.bounds.width),
// 			i32(game.btn_rand_alive_color.bounds.height)
// 		text_width := game.btn_rand_alive_color.text_width
// 		rl.DrawRectangleLinesEx(game.btn_rand_alive_color.bounds, 2, BTN_LINE_COLOR)
// 		rl.DrawText(
// 			game.btn_rand_alive_color.text_str,
// 			(BTN_WIDTH * 2) + (width - text_width) / 2,
// 			y + SPACE,
// 			BTN_FONT_SIZE,
// 			BTN_TEXT_COLOR,
// 		)
// 	}
// 	// Rand DEAD Color
// 	{
// 		x, y := i32(game.btn_rand_dead_color.bounds.x), i32(game.btn_rand_dead_color.bounds.y)
// 		width, height :=
// 			i32(game.btn_rand_dead_color.bounds.width), i32(game.btn_rand_dead_color.bounds.height)
// 		text_width := game.btn_rand_dead_color.text_width
// 		rl.DrawRectangleLinesEx(game.btn_rand_dead_color.bounds, 2, BTN_LINE_COLOR)
// 		rl.DrawText(
// 			game.btn_rand_dead_color.text_str,
// 			(BTN_WIDTH * 2) + (width - text_width) / 2,
// 			y + SPACE,
// 			BTN_FONT_SIZE,
// 			BTN_TEXT_COLOR,
// 		)
// 	}
// }
