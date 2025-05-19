#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "core/inc/blocks.h"
#include "driver/inc/key_driver.h"
#include "driver/inc/cell.h"
#include "core/inc/board.h"

#include "model.h"

#include <mmsystem.h>


#pragma comment(lib, "winmm.lib") // winmm 라이브러리 링크


bool running = true;
// 전체 보드 전역 변수
cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH] = { 0, };

// 블럭의 초기 정보를 갖고 있는 데이터
cell_attributes_t board_data_attributes[BOARD_HEIGHT][BOARD_WIDTH] = {
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (0,0),(0,1),(0,2),(0,3),(0,4),(0,5),(0,6),(0,7),(0,8),(0,9),(0,10),(0,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (1,0),(1,1),(1,2),(1,3),(1,4),(1,5),(1,6),(1,7),(1,8),(1,9),(1,10),(1,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (2,0),(2,1),(2,2),(2,3),(2,4),(2,5),(2,6),(2,7),(2,8),(2,9),(2,10),(2,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (3,0),(3,1),(3,2),(3,3),(3,4),(3,5),(3,6),(3,7),(3,8),(3,9),(3,10),(3,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (4,0),(4,1),(4,2),(4,3),(4,4),(4,5),(4,6),(4,7),(4,8),(4,9),(4,10),(4,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (5,0),(5,1),(5,2),(5,3),(5,4),(5,5),(5,6),(5,7),(5,8),(5,9),(5,10),(5,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (6,0),(6,1),(6,2),(6,3),(6,4),(6,5),(6,6),(6,7),(6,8),(6,9),(6,10),(6,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (7,0),(7,1),(7,2),(7,3),(7,4),(7,5),(7,6),(7,7),(7,8),(7,9),(7,10),(7,11)
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (18,0),(18,1),(18,2),(18,3),(18,4),(18,5),(18,6),(18,7),(18,8),(18,9),(18,10),(18,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (19,0),(19,1),(19,2),(19,3),(19,4),(19,5),(19,6),(19,7),(19,8),(19,9),(19,10),(19,11)
    { W, W, W, W, W, W, W, W, W, W, W, W }, // (20,0),(20,1),(20,2),(20,3),(20,4),(20,5),(20,6),(20,7),(20,8),(20,9),(20,10),(20,11)
};


#define BOARD_START_X (4)
#define BOARD_START_Y (4)


int main(void) {
    //const char* file_path = "sample1.wav";
    //sound_play(file_path);

    // 콘솔 초기화
    // 콘솔 정보를 console 구조체에 담자
    // 콘솔 초기값으로 세팅된다.
    windows_console_t console;
    console_init(&console);
    set_cursor_visible(&console, false);
    //console_display_info(&console);

    //console_set_pos(&console, 32, 32); // 이게 되나? 윈도 바탕화면에서 콘솔의 위치를 결정함
    console_set_fore_color(&console, GREEN); // back_color 신경쓰기 귀찮을때, 
    //console_set_back_color(&console, RED);
    //console_set_color(&console, RED, YELLOW);
    //console_set_default_color(&console); // 콘솔 초기 칼라로 설정 white, black
    //console_set_xy(&console, 32, 32); // 커서의 x,y위치를 설정함
    //cnosole_hide_cursor(true); // 커서 감추기

    /*
        console_display_info(&console);
    ;   // 기본 윈도우 콘솔값 (Default)
        //This Console information.
        //[1] Size(cols, rows) = (120, 30)
        //[2] Colors(fore, back) = (white, black)
        //[3] Cursor(x, y, hide) = 0, 0, 1)
        printf("Press Enter...");
        getchar();

        // 내가원하는 사이즈, 색상으로 변경하자.
        // 윈도우 콘솔 사이즈 변경
        console_set_size(&console, 100, 50);
        console_set_color(&console, RED, BLUE);
        console_set_cursor(&console, 11, 22, false);
        console_clear(&console);
        console_display_info(&console);
        printf("Press Enter...");
        getchar();


        console_set_size(&console, 160, 40);
        console_set_color(&console, BLACK, PURPLE);
        console_clear(&console);
        console_display_info(&console);
        printf("Press Enter...");
        getchar();


        console_set_size(&console, DEFAULT_COLS, DEFAULT_ROWS);
        console_set_color(&console, WHITE, BLACK);
        console_set_fill_color(BLACK);
        console_set_default_color(&console);
        console_display_info(&console);

        printf("Press Enter...");
        getchar();
    */

    console_set_cursor(&console, 0, 0, false);
    console_set_fill_color(BLACK);

    cell_draw_test(&console); // 테스트용, 지워도 무방하지만 종종 테스트 및 좌표 계산때문에 필요하다.
    // 최종 릴리즈에서 지워도 된다. 보기 불편하다면 주석처리
    //getchar();

    board_init(gboard, board_data_attributes); // 보드 데이터로 보드를 초기화 한다.

    block_t my_block; // 테스트용 블럭 하나 만들고
    block_init(&my_block, BLOCK_S); // 초기화
    //block_set_xy(&my_block, 0, 0);

    //cell_t my_cell;
    //cell_init(&my_cell, 0, 0, N, RED); // 좌표계 점검용 테스트 코드
    //board_insert_cell(gboard, &my_cell, 10, 19);
    //board_insert_cell(gboard, &my_cell, 1, 0);
    //board_insert_cell(gboard, &my_cell, 1, 19);
    //board_insert_cell(gboard, &my_cell, 10, 0);
    //cell_draw(&my_cell, 0, 0); // 좌상단

    //block_rotate(&my_block);
    board_clear_data(gboard); // 보드를 지운다. (정확히 말하자면, 보드 데이터 내의 내용을 지운다. 화면을 지우는게 아니라.)
    board_insert_block(gboard, &my_block, 2, 2);
    board_draw(&console, gboard);

    //getchar();

    /*
        block_t block_I; // 테스트용으로 블럭을 7개 만들어 봤다.
        block_t block_J;
        block_t block_L;
        block_t block_O;
        block_t block_S;
        block_t block_T;
        block_t my_block;

        block_init(&block_I, BLOCK_I);
        block_init(&my_block, BLOCK_J);
        //block_init(&my_block, BLOCK_L);
        block_init(&block_O, BLOCK_O);
        block_init(&block_S, BLOCK_S);
        block_init(&block_T, BLOCK_T);
        //block_init(&my_block, BLOCK_Z);

        //block_display_info(&block_I, true);
        //block_display_info(&block_J, true);
        //block_display_info(&block_L, true);
        //block_display_info(&block_O, true);
        //block_display_info(&block_S, true);
        //block_display_info(&block_T, true);
        //block_display_info(&block_Z, true);

        block_set_xy(&my_block, 4, 4);
        block_draw(&my_block);
*/
    key_init();
    uint16_t key_code = 0;

    while (running) {
        key_code = key_get_code();

        switch (key_code) {
        case KEY_UP: // // 블럭을 위(UP)로 이동, 최종적으로는 블럭을 회전(rotate)
            board_move_block(&console, gboard, &my_block, DIR_UP);
            //move_block_on_board(&gboard, &my_block, DIR_UP);
            //board_block_rotate(&my_block); // 반시계방향으로 이동하므로, 인자를 더 줄 필요는 없다.
            break;

        case KEY_LEFT: // 블럭을 왼쪽(LEFT)로 이동
            // old 기존 코드
            // 비교 차원에서 남겨놓는다.

            // 방법(1) 전체를 모두 지우고, 다시 그리는 경우, 플리커링이 심해서 방법 (2)를 쓰자.
            //console_clear(&console);
            //block_set_xy(&my_block, my_block.x - 1, my_block.y); // 좌표 이동및
            //block_draw(&my_block); // 블럭 다시 그리기

            // 방법(2) 전체를 지우지는 않고, 해당 블럭 영역만 지움는 방법, 플리커링이 덜해진다.
            //console_clear_region(my_block.x, my_block.y, my_block.x + (BLOCK_WIDTH * 2), my_block.y + BLOCK_HEIGHT); // 일정 지역만 지우면 플리커링이 덜해진다.
            //block_set_xy(&my_block, my_block.x - 1, my_block.y); // 좌표 이동및
            //block_draw(&my_block); // 블럭 다시 그리기

            // 방법 (3) 하지만, 이방법 모두 좋지 않은데, 그리기 및 충돌 체크가 용이하지 않다.
            // 보드 데이터 내에서 데이터를 insert, clear한 후 이 정보만으로 그리는게 여러 면에서 좋다.
            //board_clear_data(&gboard);
            //my_block.x -= 1; // move 함수로 만드는게 좋다. 충돌 체크등 때문에..
            //board_insert_block(gboard, &my_block, my_block.x, my_block.y);
            //board_draw(&console, gboard);

            // 방법 (4) 아래와 같이 보드 내 데이터를 갱신하는게 좋다.
            // 함수로 만들면 보기가 더 깔끔하다.
            board_move_block(&console, gboard, &my_block, DIR_LEFT);
            break;

        case KEY_RIGHT: // 블럭을 오른쪽으로 이동
            board_move_block(&console, gboard, &my_block, DIR_RIGHT);
            break;

        case KEY_DOWN: // 블럭을 아래로 이동
            board_move_block(&console, gboard, &my_block, DIR_DOWN);
            break;


        case KEY_SPACE: // 블럭을 떨어뜨리기 block drop

            break;
        }
    }

    return 0;
}

