#include "MCell.h"

bool MCell::right() const
{
	return this->m_right;
}

bool MCell::down() const
{
	return this->m_down;
}

MCell::MCell()
= default;
