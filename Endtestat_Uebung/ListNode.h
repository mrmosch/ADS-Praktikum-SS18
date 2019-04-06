#pragma once

class Node
{
public:
	int key;
	//item object;
	Node* next; 

	Node() { key = 0;  this->next = 0; }
	Node(int key1) { key = key1; }
	~Node() {};

};