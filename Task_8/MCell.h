#pragma once
class Maze;

class MCell
{
	friend Maze;
public:
	bool right() const;
	bool down() const;
private:
	bool m_down = false;
	bool m_right = false;
	MCell();
};
