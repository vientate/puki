#pragma once
#include "hp.h"

class Node
{
public:
	Doctor* data;
	Node* next;
	Node(Doctor* b) : data(b), next(nullptr) {}
	~Node();
};

