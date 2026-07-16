#include <time.h>

#include "types.h"
#include "defines.h"

#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame(void);

void init_game(struct Game *game) {
	game->is_pause = true;
	game->is_btn_pressed_and_should_refresh = false;
	game->delay = (f32)INITIAL_DELAY;
	game->alive_color = GREEN;
	game->dead_color = BLACK;
	game->render_target = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);

	ui_init(game);
	randomize_grid(game);

    // TODO
	// rl.BeginTextureMode(game.render_target)
	// draw_grid(game)
	// draw_ui(game)
	// rl.EndTextureMode()
}


int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    srand((unsigned int)time(NULL));

    struct Game game = {0};
    init_game(&game);

#if defined(PLATFORM_WEB)
    // Hand over loop execution control to the browser.
    // 0 = Use browser's preferred FPS (requestAnimationFrame).
    // 1 = Simulate an infinite block loop.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    // Traditional desktop game loop capped at 60 FPS
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif

    CloseWindow();

    return 0;
}

void UpdateDrawFrame(void)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Welcome to raylib web structure!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}
