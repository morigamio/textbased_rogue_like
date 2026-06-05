#pragma once
#include <string>
#include "Player.h"

class Game {

public:
	Game() = default;
	~Game() = default;
	void run();

private:
	enum InputKey {
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd', ESC = 27, ENTER = 13
	};
	bool m_running = true;
	std::string m_frameBuffer;

	Player player = Player(0,0);

	void input();
	void update();
	void render();
};

