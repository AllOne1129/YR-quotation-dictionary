#include "node.h"
#include <iostream>
#include <iomanip>
#include <string>

NODE *MakeNode()
{
	return new NODE{{ 0, "", LIMIT::ALL }, nullptr, nullptr };
}

void SetData(NODE *node, Data data)
{
	node->data = data;
}

void MakeLeftSubTree(NODE *node1, NODE *node2)
{
	node1->left = node2;
}

void MakeRightSubTree(NODE *node1, NODE *node2)
{
	node1->right = node2;
}
void InorderTraverse(NODE *node,LIMIT limit)
{
	if (node == nullptr)
		return;

	InorderTraverse(node->left, limit);
	if(limit>=node->data.limit)
		std::cout << std::setw(10) << node->data.id << std::setw(30) << node->data.quotation << std::endl;
	InorderTraverse(node->right, limit);
}

void CountNode(NODE *node, int &count)
{
	if (node == nullptr)
		return;

	CountNode(node->left, count);
	count++;
	CountNode(node->right, count);
}