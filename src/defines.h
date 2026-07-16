#ifndef DEFINES_H
#define DEFINES_H

#define WINDOW_TITLE "Simple CGOL"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 960

#define TILE_SIZE 2
// 生存セルの割合
#define ALIVE_RATIO 0.40
// 更新する間にはさむ時間(大きいほどゆっくり更新する)
#define INITIAL_DELAY 0.15
// DELAYの最大値
#define MAX_DELAY 0.25
// DELAYの最小値
#define MIN_DELAY 0.05
// 加減算する時の値(それぞれ最大で4段階ずつ)
#define DELAY_VALUE 0.025

#define GRID_X (WINDOW_WIDTH / TILE_SIZE)
#define GRID_Y (WINDOW_HEIGHT / TILE_SIZE - (BTN_HEIGHT / TILE_SIZE * 2))

#define BTN_WIDTH (WINDOW_WIDTH / 3)
#define BTN_HEIGHT 80
#define BTN_SPAN 4
#define BTN_FONT_SIZE 18
#define BTN_AREA_X 0
#define BTN_AREA_Y (WINDOW_HEIGHT - (BTN_HEIGHT * 2))
#define BTN_BG_COLOR Color{30, 30, 45, 255}
#define BTN_LINE_COLOR GRAY
#define BTN_TEXT_COLOR WHITE

#endif // DEFINES_H
