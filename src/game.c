#include <time.h>

#include "types.h"
#include "defines.h"
#include "input_handling.h"

#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

Game main_game;

void draw_grid(Game *game) {
	for (int y = 0; y < GRID_Y; y++) {
		for (int x = 0; x < GRID_X; x++) {
			Rectangle rec = {(f32)x * TILE_SIZE, (f32)y * TILE_SIZE, (f32)TILE_SIZE, (f32)TILE_SIZE};
			if (game->grid[y][x] == STATE_ALIVE) {
				DrawRectangleRec(rec, game->alive_color);
			} else {
				DrawRectangleRec(rec, game->dead_color);
			}
		}
	}
}

void init_game(Game *game) {
	game->is_pause = true;
	game->is_btn_pressed_and_should_refresh = false;
	game->delay = (f32)INITIAL_DELAY;
	game->alive_color = GREEN;
	game->dead_color = BLACK;
	game->render_target = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);

	ui_init(game);
	randomize_grid(game);

	BeginTextureMode(game->render_target);
	draw_grid(game);
	draw_ui(game);
	EndTextureMode();
}

void deinit_game(Game *game) {
    UnloadRenderTexture(game->render_target);
}

void update_game(void)
{
    input_handling(&main_game);

	f32 dt = GetFrameTime();
	bool should_refresh = false;

	if (!main_game.is_pause) {
		main_game.timer += dt;
		if (main_game.timer >= main_game.delay) {
			main_game.timer = 0.0;
			should_refresh = true;
		}
	}

	if (should_refresh || main_game.is_btn_pressed_and_should_refresh) {
		if (main_game.is_btn_pressed_and_should_refresh) main_game.is_btn_pressed_and_should_refresh = false;

		BeginTextureMode(main_game.render_target);

		// 時間経過による自動更新のときだけ、世代を進める
        // TODO
		// if (should_refresh) update_grid(&main_game);

		draw_grid(&main_game);
		draw_ui(&main_game);

		EndTextureMode();
	}

    BeginDrawing();
        Rectangle src_rec = {
            0, 0, (f32)main_game.render_target.texture.width, (f32)-main_game.render_target.texture.height};
        Rectangle dest_rec = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
        Vector2 origin = {0, 0};
        DrawTexturePro(main_game.render_target.texture, src_rec, dest_rec, origin, 0, WHITE);
    EndDrawing();
}

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    srand((unsigned int)time(NULL));

    init_game(&main_game);

#if defined(PLATFORM_WEB)
    // Hand over loop execution control to the browser.
    // 0 = Use browser's preferred FPS (requestAnimationFrame).
    // 1 = Simulate an infinite block loop.
    emscripten_set_main_loop(update_game, 0, 1);
#else
    // Traditional desktop game loop capped at 60 FPS
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        update_game();
    }
#endif

#if !defined(PLATFORM_WEB)
    deinit_game(&main_game);
#endif

    CloseWindow();

    return 0;
}
