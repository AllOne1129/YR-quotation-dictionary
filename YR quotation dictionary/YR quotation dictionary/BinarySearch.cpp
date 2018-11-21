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

NODE *Search(NODE *root, unsigned int data)
{
	NODE *currentNode = root;
	while (currentNode != nullptr)
	{
		if (currentNode->data.id == data)
			return currentNode;

		if (data < currentNode->data.id)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}

	throw "찾고 있는 ID의 어록이 없습니다.";
}

enum class INSERT_STATE : short { ROOT, LEFT, RIGHT };

void ChangeTree(NODE *parentNode, NODE *childNode, INSERT_STATE state)
{
	switch (state)
	{
	case INSERT_STATE::ROOT:
	{
		if (parentNode->left == childNode)
			parentNode->left = nullptr;
		else
			parentNode->right = nullptr;
		break;
	}

	case INSERT_STATE::LEFT:
	{
		parentNode->left = childNode;
		break;
	}

	case INSERT_STATE::RIGHT:
	{
		parentNode->right = childNode;
		break;
	}

	default:
		cout << "error";
	}
}

NODE *RemoveNode(NODE *node, NODE **root)
{
	enum class DEL_STATE : short { NO_CHILD, LEFT_CHILD, RIGHT_CHILD, TWO_CHILDS };

	DEL_STATE state = DEL_STATE::NO_CHILD;
	if (node->left != nullptr)
		state = static_cast<DEL_STATE>((short)state + 1);

	if (node->right != nullptr)
		state = static_cast<DEL_STATE>((short)state + 2);

	INSERT_STATE insertState;
	NODE *parentNode = *root;
	if (parentNode == node)
		insertState = INSERT_STATE::ROOT;
	else
	{
		while (parentNode != nullptr)
		{
			if (parentNode->left == node)
			{
				insertState = INSERT_STATE::LEFT;
				break;
			}
			else if (parentNode->right == node)
			{
				insertState = INSERT_STATE::RIGHT;
				break;
			}

			if (node->data.id < parentNode->data.id)
				parentNode = parentNode->left;
			else
				parentNode = parentNode->right;
		}
	}

	NODE *changeNode;
	switch (state)
	{
	case DEL_STATE::NO_CHILD:
	{
		delete node;
		changeNode = nullptr;
		break;
	}

	case DEL_STATE::LEFT_CHILD:
	{
		changeNode = node->left;
		delete node;
		break;
	}

	case DEL_STATE::RIGHT_CHILD:
	{
		changeNode = node->right;
		delete node;
		break;
	}

	case DEL_STATE::TWO_CHILDS:
	{
		int leftCount = 0;
		int rightCount = 0;
		CountNode(node->left, leftCount);
		CountNode(node->right, rightCount);

		if (leftCount >= rightCount)
		{
			changeNode = node->left;
			for (changeNode; changeNode->right != nullptr; changeNode = changeNode->right);
			changeNode->left = node->left;
			changeNode->right = node->right;
		}
		else
		{
			changeNode = node->right;
			for (changeNode; changeNode->left != nullptr; changeNode = changeNode->left);
			changeNode->left = node->left;
			changeNode->right = node->right;
		}

		while (parentNode->left != node || parentNode->right != node)
		{
			if (node->data.id < parentNode->data.id)
				parentNode = parentNode->left;
			else
				parentNode = parentNode->right;
		}
		delete node;
		break;
	}
	default:
		throw "Remove Error";
	}
	ChangeTree(parentNode, changeNode, insertState);
}

