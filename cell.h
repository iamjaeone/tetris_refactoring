#ifndef __CELL_H__
#define __CELL_H__

#include <stdint.h>		//uint32_t

#include "point.h"		// point_t
#include "color.h"		//
#include "console.h"	//windows_console_t

typedef enum _cell_attributes_t {
	E, // 비었음 empty
	W, // 벽, 없앨수 없음
	N, // 없앨수 있는 일반적인 셀
} cell_attributes_t;

typedef struct _cell_t {
    point_t point; // cell의 위치
    color_t color; // cell의 색상
    cell_attributes_t att; // cell의 속성
} cell_t;

void cell_init(cell_t* cell, int x, int y, cell_attributes_t att, color_t color);

void cell_draw(cell_t* cell, uint32_t x, uint32_t y);

void cell_draw_test(windows_console_t* console);


#endif