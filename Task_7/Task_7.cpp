#include <iostream>
#include "SLList.h"

using namespace std;

void printSLList(const SLList* list)
{
	printf("%1d\t", list->getData());
	do
	{
		list = list->next();
		printf("%1d\t", list->getData());
	} while (list->hasNext());
	printf("\n");
}

void fillList(SLList* beginList)
{
	auto* currentElem = beginList;
	for (auto i = 0; i < 9; i++)
	{
		currentElem = currentElem->addElement(rand() % 6);
	}
}

void removeDoubles(SLList* beginList)
{
	auto* currentElem = beginList;
	auto currentData = currentElem->getData();
	do
	{
		if (!currentElem->hasNext())
			return;
		auto* loopElem = currentElem;
		do
		{
			if (loopElem->next()->getData() == currentData)
			{
				loopElem->removeNext();
			}
			else
			{
				loopElem = loopElem->next();
			}
		} while (loopElem->hasNext());
		currentElem = currentElem->next();
		currentData = currentElem->getData();
	} while (currentElem->hasNext());
}

void findByEndIndex(SLList* beginList, int k)
{
	printf("Serial number from end: %1d\n", k);
	auto* currentElem = beginList;
	auto count = 1;
	do
	{
		currentElem = currentElem->next();
		count++;
	} while (currentElem->hasNext());
	currentElem = beginList;
	for (auto index = 0; index < count - k; index++)
	{
		currentElem = currentElem->next();
	}
	printf("Element data: %1d", currentElem->getData());
}

int main()
{
	auto* beginList = SLList::beginList(rand() % 6);
	fillList(beginList);
	printSLList(beginList);
	removeDoubles(beginList);
	printSLList(beginList);
	findByEndIndex(beginList, 2);
	cout << endl;
}

