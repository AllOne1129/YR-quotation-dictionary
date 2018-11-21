#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;

enum class LIMIT : short { ALL = 1, LIMIT_15, LIMIT_19 };		//검열도

// 어록의 등록 정보
class Data
{
public:
	unsigned int id;
	string quotation;
	LIMIT limit;
	
	void SetLimit(int wantLimit)
	{
		limit = static_cast<LIMIT>(wantLimit);
	}
};

typedef struct _NODE
{
	Data data;
	struct _NODE *left;
	struct _NODE *right;
} NODE;

NODE *MakeNode();
void SetData(NODE *, Data);
void MakeLeftSubTree(NODE *, NODE *);
void MakeRightSubTree(NODE *, NODE *);

void InorderTraverse(NODE *, LIMIT);
void CountNode(NODE *, int &);

#endif