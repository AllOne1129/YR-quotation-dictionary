#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_
#include "node.h"

void Initialize(NODE **);
void Insert(NODE **, Data);
NODE *Search(NODE *, Data);
NODE *RemoveNode(NODE *);

#endif