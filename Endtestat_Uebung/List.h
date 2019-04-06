#pragma once
#include "ListNode.h"

class List {
public:
	Node *head;
	Node *tail;
	int _size;

	List::List();
	void insertBack(int key);
	void toDel(Node* del);
	void duplikateDel();
	void print();
};