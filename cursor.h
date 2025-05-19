#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <Windows.h>

#include "console.h"
#include "point.h"

typedef struct _cursor_info_t {
    uint32_t x;
    uint32_t y;
    bool is_hide;
} cursor_info_t;

// 커서의 숨김,표시 정보를 가져오는 함수
bool get_cursor_visibility(void);

void set_cursor_visible(windows_console_t* console, bool hide);

void SetCurrentCursorPos(int x, int y);

point_t GetCurrentCursorPos(void);