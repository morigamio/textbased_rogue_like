#pragma once
#include <string>
#include "Player.h"
#include "Screen.h"

class Game {

public:
	Game(int rows, int cols) :
		player(0, 0),
		screen(rows, cols) {
	};
	~Game() = default;
	void run();

private:
	enum InputKey {
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd', ESC = 27, ENTER = 13
	};
	bool m_running = true;
	std::string m_frameBuffer;

	Screen screen;
	Player player;

	void input();
	void update();
	void render();
};

