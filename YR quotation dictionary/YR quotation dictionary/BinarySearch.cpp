#include "BinarySearch.h"
#include "node.h"
#include <iostream>

void Initialize(NODE **root)
{
	*root = MakeNode();
}

void Insert(NODE **root, Data data)
{
	NODE *insertNode = MakeNode();
	SetData(insertNode, data);

	if ((*root)->data.id == 0)
	{
		(*root)->data = data;
		delete insertNode;
		return;
	}

	NODE *currentNode = *root;

	while (true)
	{
		if (currentNode->data.id == data.id)
			throw "동일한 ID가 존재합니다.";

		if (data.id < currentNode->data.id)
		{
			if (currentNode->left == nullptr)
			{
				MakeLeftSubTree(currentNode, insertNode);
				return;
			}
			currentNode = currentNode->left;
		}
		else
		{
			if (currentNode->right == nullptr)
			{
				MakeRightSubTree(currentNode, insertNode);
				return;
			}
			currentNode = currentNode->right;
		}
	}
}

NODE *Search(NODE *root, Data data)
{
	NODE *currentNode = root;
	while (currentNode != nullptr)
	{
		if (currentNode->data.id == data.id)
			return currentNode;

		if (data.id < currentNode->data.id)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}

	throw "찾고 있는 ID의 어록이 없습니다.";
}

NODE *RemoveNode(NODE *node)
{
	enum class DEL_STATE : short { NO_CHILD, LEFT_CHILD, RIGHT_CHILD, TWO_CHILDS };

	DEL_STATE state = DEL_STATE::NO_CHILD;
	if (node->left != nullptr)
		state = static_cast<DEL_STATE>((short)state + 1);

	if (node->right != nullptr)
		state = static_cast<DEL_STATE>((short)state + 2);

	switch (state)
	{
	case DEL_STATE::NO_CHILD:
	{
		delete node;
		return nullptr;
	}

	case DEL_STATE::LEFT_CHILD:
	{
		NODE *tmpNode = node->left;
		delete node;
		return tmpNode;
	}

	case DEL_STATE::RIGHT_CHILD:
	{
		NODE *tmpNode = node->right;
		delete node;
		return tmpNode;
	}

	case DEL_STATE::TWO_CHILDS:
		break;
	default:
		throw "Remove Error";
	}

}