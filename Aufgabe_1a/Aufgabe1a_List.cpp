#include "Aufgabe1a_List.h"
List::List()
{
	head = new Node;
	tail = new Node;
	_size = 0;
	temp = false;
	head->next = tail;
	tail->prev = head;
}
List::~List()
{
	while (head != tail)
	{
		head = head->next;
		delete head->prev;
	}
	delete tail;
}
void List::InsertFront(int key)
{
	Node *neu = new Node; 
	neu->key = key;
	_size++;
	
	neu->prev = head;
	neu->next = head->next;
	neu->next->prev = neu; 
	head->next = neu;
}
void List::InsertBack(int key)
{
	Node *neu = new Node;
	neu->key = key;
	_size++;

	neu->next = tail;
	neu->prev = tail->prev;
	neu->prev->next = neu;
	tail->prev = neu;
}
bool List::getFront(int & key)
{
	if (_size == 0)
	{
		return false;
	}
	else
	{
		key = head->next->key;
		Node *ptr = head->next;  //Zwischenspeicher damit der zu löschende Node nicht verloren geht
		head->next = head->next->next; //head mit Nachfolger des zu löschenden Elemtenes verbinden
		ptr->next->prev = head;
		delete ptr;
		_size--;
		return true;
		
	}
}
bool List::getBack(int & key)
{
	Node *ptr = tail;  //Zwischenspeicher damit der zu löschende Node nicht verloren geht
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
	else
	{
	return false;
	}
}
bool List::del(int key)
{
	Node *ptr = head;
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
bool List::search(int key)
{
	Node *ptr = head; 
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
bool List::swap(Node * k1, Node * k2)
{
	if (head->next == tail)
		return false;
	if (k1->next == k2)
	{
		Node * k2_next = k2->next, *k2_prev = k2->prev, *k1_next = k1->next, *k1_prev = k1->prev;
		k1->next = k2_next;
		k1->prev = k2;
		k2->next = k1;
		k2->prev = k1_prev;
		k1_prev->next = k2;
		k2_next->prev = k1;
		return true;
	}
	else if (k2->next == k1)
	{
		Node * k2_next = k2->next, *k2_prev = k2->prev, *k1_next = k1->next, *k1_prev = k1->prev;
		k1->next = k2;
		k2->prev = k1;
		k2->next = k1_next;
		k1->prev = k2_prev;
		k2_prev->next = k1;
		k1_next->prev = k2;
		return true;
	}
	else
	{
		Node * k2_next = k2->next, *k2_prev = k2->prev, *k1_next = k1->next, *k1_prev = k1->prev;
		k1->prev = k2_prev;
		k1->next = k2->next;
		k1_next->prev = k2;
		k1_prev->next = k2;
		k2->prev = k1_prev;
		k2->next = k1_next;
		k2_next->prev = k1;
		k2_prev->next = k1;
		return true;
	}
	return false;
}
bool List::swap_singlylinked(Node* k1, Node* k2)
{
	if (head->next == tail)
		return false;
	else if (k2->next == k1)
	{
		Node* k2prev = getPrev(k2), *k1prev = getPrev(k1), *k1next = k1->next;
		k2prev->next = k1;
		k1->next = k2;
		k2->next = k1next;
		return true;
	}
	else
	{
		Node* k2prev = getPrev(k2), *k1prev = getPrev(k1), *k2next = k2->next;
		k1prev->next = k2;
		k2prev->next = k1;
		k2->next = k1->next;
		k1->next = k2next;
		return true;
	}
}
bool List::swap_einfach(Node * ptr1, Node * ptr2)
{
	if (ptr1->next == ptr2)
	{
		Node * ptr1_next = ptr1->next, *ptr2_next = ptr2->next, *ptr1_prev = getPrev(ptr1);

		ptr1_prev->next = ptr2;

		ptr2->next = ptr1;

		ptr1->next = ptr2_next;
	}
	else if (ptr2->next == ptr1)
	{
		Node * ptr2_next = ptr2->next, *ptr1_next = ptr1->next, *ptr2_prev = getPrev(ptr2);

		ptr2_prev->next = ptr1;

		ptr1->next = ptr2;

		ptr2->next = ptr1_next;
	}
	else
	{
		Node * ptr2_next = ptr2->next, *ptr1_next = ptr1->next, *ptr2_prev = getPrev(ptr2), *ptr1_prev = getPrev(ptr1);

		ptr1_prev->next = ptr2;

		ptr2_prev->next = ptr1;

		ptr1->next = ptr2_next;

		ptr2->next = ptr1_next;
	}

	return true;
}
bool List::InsertionSort()
{
	if (_size == 0) return false;
	if (_size == 1) return true;

	Node *i, *j;
	for (i = head->next->next; i != tail; i = i->next)
	{
		j = i;
		while (j != head->next && getPrev(j)->key > j->key)
		{
			std::cout << "Tausch von j->prev(" << getPrev(j)->key 
					  << ") und j(" << j->key << ")." << std::endl;
			swap_singlylinked(getPrev(j), j);
			std::cout << this;
		}
	}
}
void List::invert()
{
	Node*prev = nullptr;
	Node *current = head;
	Node *next = head->next;

	while (current != nullptr)
	{

		current->next = prev;
		prev = current;
		current = next;
		if (current != nullptr)
		{
			next = current->next;
		}

	}
	head = prev;
}

bool List::invertieren()
{
	Node* tmphinten = getPrev(tail);
	Node* tmpvorne = head->next;
	for (; tmpvorne->next != tmphinten && tmpvorne != tmphinten; tmpvorne = tmpvorne->next, tmphinten = getPrev(tmphinten))
	{
		swap_singlylinked(tmpvorne, tmphinten);
		std::cout << "tausch: " << tmpvorne->key << "     und      " << tmphinten->key << std::endl;
		Node* tmp = tmpvorne;
		tmpvorne = tmphinten;
		tmphinten = tmp;
		std::cout << this << std::endl;
	}
	return true;
}


Node* List::getPrev(Node* suche)
{
	Node* tmp = head;
	while (tmp->next != suche)
	{
		tmp = tmp->next;
	}
	return tmp;
}
Node* List::getNodeByKey(int key)
{
	Node*tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->key == key)
			return tmp;
		tmp = tmp->next;
	}
}

bool List::SelectionSort()
{
	if (_size == 0) return false;
	if (_size == 1) return true;

	Node * min = head->next;
	Node * ErstesElementUnsortierteTeilfolge = head->next;

	Node * ptr = head->next;

	while (ErstesElementUnsortierteTeilfolge != tail)
	{
		while (ptr != tail)
		{
			if (ptr->key < min->key)
			{
				min = ptr;
			}

			ptr = ptr->next;
		}

		std::cout << "swap( " << ErstesElementUnsortierteTeilfolge->key << " , " << min->key << " );" << std::endl;
		swap(ErstesElementUnsortierteTeilfolge, min);

		Node * tmp = ErstesElementUnsortierteTeilfolge;
		ErstesElementUnsortierteTeilfolge = min;
		min = tmp;

		ErstesElementUnsortierteTeilfolge = ErstesElementUnsortierteTeilfolge->next;
		ptr = ErstesElementUnsortierteTeilfolge->next;
		min = ErstesElementUnsortierteTeilfolge;
	}

	return true;
}

bool List::BubbleSort()
{
	if (_size == 0) return false;
	if (_size == 1) return true;

	Node * ptr1 = head->next;
	Node * ptr2 = ptr1->next;
	Node * ErstesElementSortierteTeilfolge = tail->prev;

	for (int i = 1; i < _size; i++)
	{
		Node * ptr1 = head->next;
		Node * ptr2 = head->next->next;

		while (ptr2 != ErstesElementSortierteTeilfolge)
		{
			if (ptr1->key > ptr2->key)
			{
				swap(ptr1, ptr2);

				Node * tmp = ptr1;
				ptr1 = ptr2;
				ptr2 = tmp;
			}

			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		ErstesElementSortierteTeilfolge = ErstesElementSortierteTeilfolge->prev;
	}
}

int List::size(void)
{
	return _size;
}
bool List::test(void)
{
	Node *ptr = head;
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

void List::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

List & List::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
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

List & List::operator = (const List * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
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

List & List::operator + (const List & List_Append)
{
	Node * tmp_node;
	List * tmp;
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

List & List::operator + (const List * List_Append)
{
	Node * tmp_node;
	List * tmp;
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

std::ostream & operator<<(std::ostream  & stream, List const & Liste)
{
	stream << Liste._form.start;
	for (Node * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

std::ostream & operator << (std::ostream & stream, List const * Liste)
{
	stream << Liste->_form.start;
	for (Node * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}