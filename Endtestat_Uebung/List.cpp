#include "List.h"
#include <iostream>
List::List()
{
	head = new Node;
	tail = new Node;
	_size = 0;
	head->next = tail;
}

void List::insertBack(int key)
{
	Node* insert = new Node(key);
	Node* tmp = head; 
	if (_size == 0)
	{
		head->next = insert;
	}
	else
	{
		while (tmp->next != tail)
		{
			tmp = tmp->next;
		}
		tmp->next = insert;
		insert->next = tail;
		_size++;
	}
}

void List::toDel(Node* del)
{
	Node* delPrev = head;
	while (delPrev->next != del)
	{
		delPrev = delPrev->next;
	}
	delPrev->next = del->next;
	std::cout << "Es wird der Knoten mit dem Wert: " << del->key << " geloescht." << std::endl;
	delete del;
	_size--;
}

void List::duplikateDel()
{
	Node* tmp = head; 
	for (tmp = head; tmp != tail; tmp = tmp->next)
	{
		Node* tmp2 = head; 
		while (tmp2 != tail)
		{
			if (tmp->key == tmp2->key)
			{
				Node* _del = tmp2;
				tmp2 = tmp2->next;
				toDel(_del);
			}
			tmp2 = tmp2->next;
		}
	}
}

void List::print()
{
	Node* tmp = head->next;
	for (int i=0; i< _size; i++)
	{
		std::cout << tmp->key << "; ";
		tmp = tmp->next;
	}
}