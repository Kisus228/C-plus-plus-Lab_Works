#include "Maze.h"
#include <iostream>
#include <string>



#include "MCell.h"
#include "MTreeNode.h"
void convertToTree(MTreeNode* parent, Maze* maze)
{
	auto cell = maze->cell(parent->i(), parent->j());
	if (cell.down())
	{
		parent->addChild(parent->i() + 1, parent->j());
		convertToTree(parent->hasChild(parent->i() + 1, parent->j()), maze);
	}
	if (cell.right())
	{
		parent->addChild(parent->i(), parent->j() + 1);
		convertToTree(parent->hasChild(parent->i(), parent->j() + 1), maze);
	}
}

void printTree(MTreeNode* parent, char* result, int size)
{
	result[parent->i() * (size + 1) + parent->j()] = parent->distance() + '0';
	auto* rightChild = parent->hasChild(parent->i(), parent->j() + 1);
	auto* downChild = parent->hasChild(parent->i() + 1, parent->j());
	if (rightChild != nullptr)
	{
		printTree(rightChild, result, size);
	}
	if (downChild != nullptr)
	{
		printTree(downChild, result, size);
	}
}

int main()
{
	int size;
	std::cout << "Enter the size of the square maze:" << std::flush;
	std::cin >> size;
	auto* maze = new Maze(size, size);
	for (auto index = 0; index < size - 2; index++)
	{
		for (auto i = index + 1; i < size - 1; i++)
		{
			maze->makeConnection(index, i - 1, index, i);
			maze->makeConnection(i - 1, index, i, index);
		}
		maze->makeConnection(index, index + 1, index + 1, index + 1);
	}
	maze->printMaze();
	std::cout << std::endl;
	auto* tree = MTreeNode::beginTree(0, 0);
	convertToTree(tree, maze);
	char* treeInStr = new char[(size + 1) * size];
	for (auto index = 0; index < (size + 1) * size; index++)
	{
		if ((index + 1) % (size + 1) == 0)
			treeInStr[index] = '\n';
		else
		{
			treeInStr[index] = ' ';
		}
	}
	printTree(tree, treeInStr, size);
	for (auto index = 0; index < (size + 1) * size; index++)
	{
		auto sym = treeInStr[index];
		std::cout << sym;
	}
	std::cout.flush();
	return 0;
}
