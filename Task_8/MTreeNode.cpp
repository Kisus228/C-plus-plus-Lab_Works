#include "MTreeNode.h"

int MTreeNode::i() const
{
	return m_i;
}

int MTreeNode::j() const
{
	return m_j;
}

const MTreeNode* MTreeNode::parent() const
{
	return m_parent;
}

const MTreeNode* MTreeNode::child(int i) const
{
	return &m_children[i];
}

int MTreeNode::distance() const
{
	return m_distance;
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
	for (auto index = 0; index < 4; index++)
	{
		auto* child = &m_children[index];
		if (child->i() == i && child->j() == j)
			return child;
	}
	return nullptr;
}

int MTreeNode::childCount() const
{
	return m_childCount;
}

bool MTreeNode::addChild(int i, int j)
{
	if (childCount() == 4)
		return false;
	auto* child = new MTreeNode(this);
	child->m_i = i;
	child->m_j = j;
	m_children[childCount()] = *child;
	m_childCount++;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	auto* beginner = new MTreeNode(nullptr);
	beginner->m_i = i;
	beginner->m_j = j;
	return beginner;
}

MTreeNode::MTreeNode(MTreeNode* parent)
{
	m_parent = parent;
	if (parent != nullptr)
	{
		m_distance = parent->distance() + 1;
	}
	else
	{
		m_distance = 0;
	}
	m_children = new MTreeNode[4];
	m_childCount = 0;
}
