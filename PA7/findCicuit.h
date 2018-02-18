#pragma once
#include <string>

struct Node
{
	Node(Node* n1) : next(n1) {};
	int data;
	struct Node* next;
};


class findCicuit
{
public:
	findCicuit();
};

