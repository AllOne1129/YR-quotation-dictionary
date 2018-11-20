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
void InorderTraverse(NODE *node)
{
	if (node == nullptr)
		return;

	InorderTraverse(node->left);
	std::cout << node->data.quotation << " ";
	InorderTraverse(node->right);
}

void PreorderTraverse(NODE *node)
{
	if (node == nullptr)
		return;

	std::cout << node->data.quotation << " ";
	PreorderTraverse(node->left);
	PreorderTraverse(node->right);
}

void PostorderTraverse(NODE *node)
{
	if (node == nullptr)
		return;

	PostorderTraverse(node->left);
	PostorderTraverse(node->right);
	std::cout << node->data.quotation << " ";
}

void DeleteTree(NODE *node)
{
	if (node == nullptr)
		return;

	DeleteTree(node->left);
	DeleteTree(node->right);
	delete[] node;
	node = nullptr;
}