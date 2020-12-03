#include "Maze.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>


#include "MCell.h"

Maze::Maze(int n, int m)
{
	rowsAmount = n;
	columnsAmount = m;
	m_field = new MCell[rowsAmount * columnsAmount];
}

const MCell& Maze::cell(int i, int j) const
{
	return this->m_field[i * rowsAmount + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (i1 != i2)
	{
		return cell(std::min(i1, i2), j1).down();
	}
	return cell(i1, std::min(j1, j2)).right();
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (i1 != i2 && j1 != j2 || abs(i1 - i2) > 1 || abs(j1 - j2) > 1)
	{
		return false;
	}
	if (i1 != i2)
	{
		m_field[std::min(i1, i2) * rowsAmount + j1].m_down = true;
	}
	else
	{
		m_field[i1 * rowsAmount + std::min(j1, j2)].m_right = true;
	}
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (i1 != i2 && j1 != j2 || abs(i1 - i2) > 1 || abs(j1 - j2) > 1)
	{
		return false;
	}
	if (i1 != i2)
	{
		m_field[std::min(i1, i2) * rowsAmount + j1].m_down = false;
	}
	else
	{
		m_field[i1 * rowsAmount + std::min(j1, j2)].m_right = false;
	}
	return true;
}

void Maze::printMaze()
{
	for (auto i = 0; i < rowsAmount; i++)
	{
		for (auto j = 0; j < columnsAmount; j++)
		{
			const auto up = i != 0 && cell(i - 1, j).down();
			const auto down = cell(i, j).down();
			const auto right = cell(i, j).right();
			const auto left = j != 0 && cell(i, j - 1).right();
			if (up + down + right + left == 0)
			{
				std::cout << '0';
				continue;
			}
			if (up)
			{
				if (down)
				{
					if (right)
					{
						if (left)
							std::cout << static_cast<char>(197);
						else
							std::cout << static_cast<char>(195);
					}
					else if (left)
						std::cout << static_cast<char>(180);
					else
						std::cout << static_cast<char>(179);
				}
				else if (right)
				{
					if (left)
						std::cout << static_cast<char>(193);
					else
						std::cout << static_cast<char>(192);
				}
				else if (left)
					std::cout << static_cast<char>(217);
				else
					std::cout << static_cast<char>(179);
			}
			else if (down)
			{
				if (right)
				{
					if (left)
						std::cout << static_cast<char>(194);
					else
						std::cout << static_cast<char>(218);
				}
				else if (left)
					std::cout << static_cast<char>(191);
				else
					std::cout << static_cast<char>(179);
			}
			else
				std::cout << static_cast<char>(196);
		}
		std::cout << std::endl;
	}
}

Maze::~Maze()
{
	const auto size = rowsAmount * columnsAmount;
	for (auto index = 0; index < size; index++)
	{
		delete &m_field[index];
	}
}
