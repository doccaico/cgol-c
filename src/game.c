#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

const int screenWidth = 800;
const int screenHeight = 450;

void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "raylib [core] example - web window");

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
