#include <iostream>
#include <conio.h>
#include "Tetris.cpp"

int main() {
	Tetris tetris;

	tetris.game_init();
	tetris.game_start();

	while (true) {
		int ch = _getch();
		if (ch == 224) {    // 확장키 시작 코드 (0x00 또는 0xE0)
			ch = _getch();
		}
		tetris.key_input(ch);
	}

	tetris.game_over();

	return 0;
}