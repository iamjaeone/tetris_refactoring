#pragma once

#include <iostream>
#include <cstdint>
#include <ctime>
//#include <mmsystem.h>

extern "C" {
#include "core/inc/blocks.h"
#include "driver/inc/key_driver.h"
#include "driver/inc/cell.h"
#include "core/inc/board.h"
#include "model.h"
}

#include "IGame.h"

#pragma comment(lib, "winmm.lib") // winmm 라이브러리 링크

#define BOARD_START_X (4)
#define BOARD_START_Y (4)