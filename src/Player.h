#pragma once

class Player {
public:
	Player(int x, int y): m_x(x), m_y(y){}
	~Player() = default;

	void move(int dx, int dy) { m_x += dx; m_y += dy; }

	int m_x, m_y;
private:
};
