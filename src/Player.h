#pragma once

class Player {
public:
	Player(int x, int y): m_x(x), m_y(y){}
	~Player() = default;

	int m_x, m_y;
private:
};
