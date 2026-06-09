#include "Game.h"
#include "AnsiCommands.h"
#include <iostream>
#include <thread>
#include <conio.h>


void Game::run() {
	while (m_running) {
		input();
		update();
		render();

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
	
}

void Game::render() {
	screen.clear();
	screen.put(player.m_x, player.m_y, "@", 123, 22, 0); // draw player character
	screen.present();
}
