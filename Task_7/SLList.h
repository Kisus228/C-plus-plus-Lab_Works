#pragma once
#ifndef SLLIST_H
#define SLLIST_H

class SLList
{
public:
	int getData() const;
	void setData(int data);
	SLList* next() const;
	bool hasNext() const;
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();
private:
	SLList* m_nextElem;
	int m_data;
	explicit SLList(int data);
	~SLList();
};

#endif
