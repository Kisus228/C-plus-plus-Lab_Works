#pragma once
class MCell;

class Maze
{
public:
	explicit Maze(int n, int m);
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
private:
	MCell* m_field;
	int rowsAmount;
	int columnsAmount;
	~Maze();
};

