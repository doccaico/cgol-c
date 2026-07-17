#include <time.h>

#include "types.h"
#include "defines.h"
#include "input_handling.h"

#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

Game main_game;

static void update_cell_texture(Game *game) {
    // CPU上のイメージ(画素バッファ)のメモリポインタを直接取得
    Color *pixels = (Color *)game->cell_image.data;

    // 2重ループでピクセル配列に直接色を書き込む(超高速)
    for (i32 y = 0; y < GRID_Y; y++) {
        for (i32 x = 0; x < GRID_X; x++) {
            Color color = (game->grid[y][x] == STATE_ALIVE) ? game->alive_color : game->dead_color;
            pixels[y * GRID_X + x] = color;
        }
    }

    // 変更したピクセルデータを一括でGPUテクスチャに転送
    UpdateTexture(game->cell_texture, game->cell_image.data);
}

static void init_game(Game *game) {
	game->is_pause = true;
	game->is_btn_pressed_and_should_refresh = false;
	game->delay = (f32)INITIAL_DELAY;
	game->alive_color = GREEN;
	game->dead_color = BLACK;
	game->render_target = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);
    // グリッドと同じ解像度のイメージをCPUメモリ上に作成
    game->cell_image = GenImageColor(GRID_X, GRID_Y, game->dead_color);
    // それを元にGPUテクスチャを生成（拡大時にぼやけないよう近傍補間を設定）
    game->cell_texture = LoadTextureFromImage(game->cell_image);
    SetTextureFilter(game->cell_texture, TEXTURE_FILTER_POINT);

	init_ui(game);
	randomize_grid(game);

	BeginTextureMode(game->render_target);
        update_cell_texture(game);

        // 大量の四角形ではなく、生成した1枚のテクスチャを画面サイズに引き伸ばして描画
        Rectangle src_rec = {0, 0, (f32)GRID_X, (f32)GRID_Y};
        Rectangle dest_rec = {0, 0, (f32)(GRID_X * TILE_SIZE), (f32)(GRID_Y * TILE_SIZE)};
        DrawTexturePro(game->cell_texture, src_rec, dest_rec, (Vector2){0, 0}, 0, WHITE);

        draw_ui(game);
	EndTextureMode();
}

static void deinit_game(Game *game) {
    UnloadImage(game->cell_image);
    UnloadTexture(game->cell_texture);
    UnloadRenderTexture(game->render_target);
}

static void update_game(void)
{
    input_handling(&main_game);

	f32 dt = GetFrameTime();
	bool should_refresh = false;

	if (!main_game.is_pause) {
		main_game.timer += dt;
		if (main_game.timer >= main_game.delay) {
			main_game.timer = 0;
			should_refresh = true;
		}
	}

	if (should_refresh || main_game.is_btn_pressed_and_should_refresh) {
		if (main_game.is_btn_pressed_and_should_refresh) main_game.is_btn_pressed_and_should_refresh = false;

		BeginTextureMode(main_game.render_target);
            // 時間経過による自動更新のときだけ、世代を進める
            if (should_refresh) update_grid(&main_game);

            update_cell_texture(&main_game);

            // セルテクスチャを拡大描画
            Rectangle src_rec = {0, 0, (f32)GRID_X, (f32)GRID_Y};
            Rectangle dest_rec = {0, 0, (f32)(GRID_X * TILE_SIZE), (f32)(GRID_Y * TILE_SIZE)};
            DrawTexturePro(main_game.cell_texture, src_rec, dest_rec, (Vector2){0, 0}, 0, WHITE);

            draw_ui(&main_game);
		EndTextureMode();
	}

    BeginDrawing();
        ClearBackground(BTN_BG_COLOR);

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
