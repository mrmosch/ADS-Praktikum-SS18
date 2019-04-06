#pragma once
#ifndef _NODE_H
#define _NODE_H
template <class T>
class Node {
public:
	T key;
	Node<T> * next, *prev;

	Node<T>();
	Node<T>(T key, Node<T> * next = 0, Node<T> * prev = 0);
	~Node<T>();

};
template <class T>
Node<T>::Node()
{
	next = 0;
	prev = 0;
}
template <class T>
Node<T>::Node(T key, Node<T> * next, Node<T> * prev)
{
	this->key = key;
	this->next = next;
	this->prev = prev;
}
template <class T>
Node<T>::~Node<T>()
{
}

#endif