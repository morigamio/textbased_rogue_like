#include "Game.h"
#include "AnsiCommands.h"
#include <iostream>
#include <thread>
#include <conio.h>


void Game::run() {
	while (m_running) {
		input();
		update();
		// render();
		std::cout << ansi::MOVE_TO(player.m_x, player.m_y);
		std::cout << ansi::BG(0, 140, 255); // blue background
		std::cout << ansi::FG(255, 255, 255); // white text
		std::cout << "@"; // draw player character

		std::this_thread::sleep_for(std::chrono::milliseconds(33)); // simple approach to get 30ish fps
	}
}

void Game::input() {
	// input
	if (_kbhit()) {           // returns true if a keyinput is waiting to be processed
		int key = _getch();   // read one keypress, no Enter needed
		switch (key) {
			case ESC: m_running = false; break;
			case UP: player.move(0, -1); break;
			case DOWN: player.move(0, 1); break;
			case LEFT: player.move(-1, 0); break;
			case RIGHT: player.move(1, 0); break;
		}
	}
}

void Game::update() {
	// check player collision with boundaries

}

void Game::render() {

}
