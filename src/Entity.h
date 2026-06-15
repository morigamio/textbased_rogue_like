#pragma once

class Entity {
public:
	Entity(int x, int y): m_x(x), m_y(y){}
	~Entity() = default;

	void move(int dx, int dy) { m_x += dx; m_y += dy; }

	int m_x, m_y;
private:
};
