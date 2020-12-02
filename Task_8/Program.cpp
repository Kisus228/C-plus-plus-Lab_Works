#include "Maze.h"
#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	auto* maze = new Maze(n, m);
	for (auto index = 0; index < min(n, m - 1); index++)
	{
		maze->makeConnection(index, index + 1, index + 1, index + 1);
		if (index + 2 < m)
			maze->makeConnection(index + 1, index + 1, index + 1, index + 2);
	}
	maze->printMaze();
	cout.flush();
	return 0;
}