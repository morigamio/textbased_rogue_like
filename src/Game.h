#pragma once
#include <string>
#include "Screen.h"
#include "Entity.h"
#include "Map.h"

class Game {

public:
	Game(int rows, int cols) :
		player(1, 1),
		screen(rows, cols) {
	};
	~Game() = default;
	void run();

private:
	enum InputKey {
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd', ESC = 27, ENTER = 13
	};
	bool m_running = true;

	Map map;
	Screen screen;
	Entity player;
	std::vector<Entity> entities; // e.g. monsters, items, etc.

	void input();
	void update();
	void render();
};

