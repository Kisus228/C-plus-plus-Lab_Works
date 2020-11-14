#include "SLList.h"

int SLList::getData() const
{
	return m_data;
}

void SLList::setData(int data)
{
	m_data = data;
}

SLList* SLList::next() const
{
	return m_nextElem;
}

bool SLList::hasNext() const
{
	return m_nextElem != nullptr;
}

SLList* SLList::beginList(int data)
{
	return new SLList(data);
}

SLList* SLList::addElement(int data)
{
	if (hasNext())
	{
		return nullptr;
	}
	auto* const elem = new SLList(data);
	m_nextElem = elem;
	return elem;
}

void SLList::removeNext()
{
	if (!hasNext())
		return;
	auto* elemToRemove = m_nextElem;
	if (m_nextElem->hasNext())
	{
		m_nextElem = m_nextElem->next();
	}
	else
	{
		m_nextElem = nullptr;
	}
	elemToRemove->m_nextElem = nullptr;
	delete elemToRemove;
}

SLList::SLList(int data)
{
	m_data = data;
	m_nextElem = nullptr;
}

SLList::~SLList()
{
	if (hasNext())
		delete m_nextElem;
}
