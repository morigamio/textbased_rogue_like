#include <iostream>
#include "ConsoleUtils.h"
#include "Game.h"
#include "Screen.h"

int main() {
	ConsoleUtils::ScreenGuard guard; // RAII: automatically enter alternate screen buffer and hide cursor, and restore on exit
    ConsoleUtils::setSize(120,40); // define console dimensions
	ConsoleUtils::setEncoding(); // set UTF-8 encoding for proper character display
	Game game(240,80);
	game.run();
}


