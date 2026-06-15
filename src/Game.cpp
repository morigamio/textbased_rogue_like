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
	if (_kbhit()) { // returns true if a keyinput is waiting to be processed
		int key = _getch(); // read one keypress, no Enter needed

		int tmpPosX = 0; // temporary variables to hold the potential new position of the player
		int tmpPosY = 0; // these will be used to check if the new position is valid before actually moving the player
		
		switch (key) {
		case ESC: m_running = false; break;
		case UP: tmpPosY = -1; break;
		case DOWN: tmpPosY = 1; break;
		case LEFT: tmpPosX = -1; break;
		case RIGHT: tmpPosX = 1; break;
		}

		if (map.isWalkable(player.m_x + tmpPosX, player.m_y + tmpPosY)) {
			player.move(tmpPosX, tmpPosY);
		}
	}
}


void Game::update() {

}

void Game::render() {
	screen.clear();
	for (size_t i = 0; i < map.rows(); i++)
	{

	}
	screen.put(player.m_x, player.m_y, "@", 0, 2, 0); // draw player character
	screen.present();
}
