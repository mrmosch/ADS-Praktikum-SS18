#pragma once
#include <string>
#include "RingNode.h"
#include <iostream>

class RingPuffer
{
private:
	RingNode* anker;


public:
	RingPuffer::RingPuffer()
	{
		anker = nullptr;
	}

	RingPuffer::~RingPuffer()
	{
		if (anker != nullptr)
		{
			RingNode * tmp = anker->next;

			while (tmp != anker)
			{
				RingNode * tmp_next = tmp->next;

				delete tmp;
				tmp = tmp_next;
			}

			delete anker;
		}
	}

	bool RingPuffer::addNode(std::string beschreibung, std::string daten)
	{
		RingNode * neu = new RingNode;
		neu->Description = beschreibung;
		neu->SymbolicData = daten;
		neu->OldAge = -1;

		// Fall 1: erster Eintrag
		if (anker == nullptr)
		{
			anker = neu;
			neu->next = anker;
		}

		// Fall 2: Elemente vorhanden, aber noch nicht voll
		else if (anker->next->OldAge != 5)
		{
			neu->next = anker->next;
			anker->next = neu;

			anker = neu;
		}

		// Fall 3: Liste voll
		else if (anker->next->OldAge == 5)
		{
			RingNode * tmp = anker->next;
			neu->next = anker->next->next;
			anker->next = neu;

			anker = neu;

			delete tmp;
		}

		IncrementAge();
		return true;
	}

	bool RingPuffer::search(std::string daten)
	{
		if (anker == nullptr) // Fall 1: kein Element 
			return false;

		if (anker == anker->next) // Fall 2: ein Element
		{
			if (anker->SymbolicData == daten)
			{
				std::cout << "+Gefunden in Backup: ";
				Ausgabe_Datensatz(anker);
				return true;
			}

			return false;
		}

		// Fall 3: mehrere Elemente
		RingNode * ptr = anker->next;

		while (ptr != anker)
		{
			if (ptr->SymbolicData == daten)
			{
				std::cout << "+Gefunden in Backup: ";
				Ausgabe_Datensatz(ptr);
				return true;
			}

			ptr = ptr->next;
		}

		return false;
	}

	void RingPuffer::print()
	{
		if (anker == nullptr)
			return;

		// ersten Datensatz ausgeben (0)
		Ausgabe_Datensatz(anker);
		trennlinie('-', 25);

		print_intern(anker->next);
	}

	void RingPuffer::print_intern(RingNode * ptr)
	{
		if (ptr == anker)
			return;

		print_intern(ptr->next);

		Ausgabe_Datensatz(ptr);
		trennlinie('-', 25);
	}

	void RingPuffer::IncrementAge()
	{
		RingNode * tmp = anker->next;

		while (tmp != anker)
		{
			tmp->OldAge++;
			tmp = tmp->next;
		}

		anker->OldAge++;
	}

	void RingPuffer::Ausgabe_Datensatz(RingNode * obj)
	{
		std::cout << "OldAge: " << obj->OldAge
			<< ", Beschreibung: " << obj->Description
			<< ", Data: " << obj->SymbolicData
			<< std::endl;
	}

	void trennlinie(char c, int anz)
	{
		while (anz-- > 0)
			std::cout << c;

		std::cout << std::endl;
	}
};