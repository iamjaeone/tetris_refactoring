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