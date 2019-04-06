#pragma once
#ifndef _LIST_H
#define _LIST_H
#include "Aufgabe1c_Node.h"
#include <string>
#include <iostream>

template <class T>
class List
{
private:
	struct form { std::string start = "<<"; std::string zwischen = ", "; std::string ende = ">>\n"; } _form;
	T element;
	Node<T> *head;
	Node<T> *tail;
	int _size;
	bool temp = false;
public:
	List<T>();
	~List<T>();
	void InsertFront(T item);
	void InsertBack(T item);
	bool getFront(T & item);
	bool getBack(T & item);
	bool search(T item);
	bool del(T item);
	bool test(void);
	bool swap(T item1, T item2);
	int size(void);

	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
	List<T> & operator = (const List<T> & _List);						// Zuweisungsoperator definieren
	List<T> & operator = (const List<T> * _List);						// Zuweisungsoperator definieren
	List<T> & operator + (const List<T> & List_Append);					// Listen zusammenführen zu einer Liste
	List<T> & operator + (const List<T> * List_Append);					// Listen zusammenführen zu einer Liste
	template <typename Tf>
	friend std::ostream & operator << (std::ostream & stream, const List<Tf> & Liste);		// Ausgabeoperator überladen
	template <typename Tf>
	friend std::ostream & operator << (std::ostream & stream, const List<Tf> * Liste);		// Ausgabeoperator überladen
};

template <class T>
List<T>::List()
{
	head = new Node<T>;
	tail = new Node<T>;
	_size = 0;
	temp = false;
	head->next = tail;
	tail->prev = head;
}
template <class T>
List<T>::~List()
{
	while (head != tail)
	{
		head = head->next;
		delete head->prev;
	}
	delete tail;
}
template <class T>
void List<T>::InsertFront(T item)
{
	Node<T> *neu = new Node<T>;
	neu->key = item;
	_size++;

	neu->prev = head;
	neu->next = head->next;
	neu->next->prev = neu;
	head->next = neu;
}
template <class T>
void List<T>::InsertBack(T item)
{
	Node<T> *neu = new Node<T>;
	neu->key = item;
	_size++;

	neu->next = tail;
	neu->prev = tail->prev;
	neu->prev->next = neu;
	tail->prev = neu;
}
template <class T>
bool List<T>::getFront(T & key)
{
	if (_size == 0)
	{
		return false;
	}
	else
	{
		key = head->next->key;
		Node<T> *ptr = head->next;  //Zwischenspeicher damit der zu löschende Node nicht verloren geht
		head->next = head->next->next; //head mit Nachfolger des zu löschenden Elemtenes verbinden
		ptr->next->prev = head;
		delete ptr;
		_size--;
		return true;
	}
}
template <class T>
bool List<T>::getBack(T & key)
{
	Node<T> *ptr = tail;  //Zwischenspeicher damit der zu löschende Node nicht verloren geht
	if (ptr->prev != head)
	{
		key = tail->prev->key;
		ptr = ptr->prev;
		tail->prev = tail->prev->prev; //tail mit vorgaenger des zu löschenden Elementes verbinden
		tail->prev->next = tail;
		delete ptr;
		_size--;
		return true;
	}
	return false;
}
template <class T>
bool List<T>::del(T key)
{
	Node<T> *ptr = head;
	while (ptr != tail)
	{
		if (ptr->key == key)
		{
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			delete ptr;
			return true;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return false;
}
template <class T>
bool List<T>::search(T key)
{
	Node<T> *ptr = head;
	while (ptr != tail)
	{
		if (ptr->key == key)
		{
			return true;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return false;
}
template <class T>
bool List<T>::swap(T key1, T key2)
{	//Ersten Key finden
	Node<T> *ptr = head;
	Node<T> *key1ptr = nullptr;
	Node<T> *key2ptr = nullptr;

	for (T i = 0; ptr->next != tail; i++)
	{
		if (ptr->key == key1)
			key1ptr = ptr;
		if (ptr->key == key2)
			key2ptr = ptr;
		if (key1ptr != 0 && key2ptr != 0)
			break;
		ptr = ptr->next;
	}

	if (key1ptr == nullptr || key2ptr == nullptr)
		return false;
	if (key1ptr == key2ptr)
		return true;

	if (key1ptr->next == key2ptr)
	{
		Node<T> *ptr3 = key1ptr;

		key1ptr->prev->next = key2ptr;
		key1ptr->next = key2ptr->next;
		key1ptr->prev = key2ptr;
		

		key2ptr->next->prev = ptr3;
		key2ptr->next = ptr3;
		key2ptr->prev = ptr3->prev;
		return true;
	}

	if (key2ptr->next == key1ptr)
	{
		Node<T> *ptr3 = key2ptr;
		key2ptr = key1ptr;
		key1ptr = ptr3;

		key1ptr->prev->next = key2ptr;
		key1ptr->next = key2ptr->next;
		key1ptr->prev = key2ptr;
		key1ptr->key = key2ptr->key;

		key2ptr->next->prev = ptr3;
		key2ptr->next = ptr3;
		key2ptr->key = ptr3->key;
		key2ptr->prev = ptr3->prev;
		return true;
	}
	//Swap von Key1- und Key2-Knoten:

	Node<T> *ptr2_prev = key2ptr->prev;
	Node<T> *ptr2_next = key2ptr->next; //Hilfspointer

	key1ptr->prev->next = key2ptr;
	key1ptr->next->prev = key2ptr;

	key2ptr->prev->next = key1ptr;
	key2ptr->next->prev = key1ptr;

	key2ptr->prev = key1ptr->prev;
	key2ptr->next = key1ptr->next;

	key1ptr->prev = ptr2_prev;
	key1ptr->next = ptr2_next;
	return true;
}
template <class T>
int List<T>::size(void)
{
	return _size;
}
template <class T>
bool List<T>::test(void)
{
	Node<T> *ptr = head;
	while (ptr != tail)
	{
		ptr = ptr->next;
	}
	while (ptr != head)
	{
		ptr = ptr->prev;
	}
	return true;
}

template <class T>
void List<T>::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

template <class T>
List<T> & List<T>::operator = (const List<T> & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List.head->next;
	while (tmp_node != _List.tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template <class T>
List<T> & List<T>::operator = (const List<T> * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List->head->next;
	while (tmp_node != _List->tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template <class T>
List<T> & List<T>::operator + (List<T> const & List_Append)
{
	Node<T> * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List<T>;					// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append._size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append.head->next;
		while (tmp_node != List_Append.tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}
template <class Tf>
std::ostream & operator << (std::ostream  & stream, const List<Tf> & Liste)
{
	stream << Liste._form.start;
	for (Node<Tf> * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

template <class Tf>
std::ostream & operator << (std::ostream  & stream, const List<Tf> * Liste)
{
	stream << Liste->_form.start;
	for (Node<Tf> * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

template <class T>
List<T> & List<T>::operator + (const List<T> * List_Append)
{
	Node<T> * tmp_node;
	List<T> * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List;						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->_size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append->head->next;
		while (tmp_node != List_Append->tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}
#endif