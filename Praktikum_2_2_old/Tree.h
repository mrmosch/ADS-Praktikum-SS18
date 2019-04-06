#pragma once
#include "TreeNode.h"
#include <fstream>
#include <iostream>
#include <iomanip>

class Tree
{
private:
	TreeNode* anker;
public:
	Tree::Tree()
	{
		anker = nullptr;
	}

	bool Tree::addNode(std::string Name, int Alter, double Einkommen, int PLZ)
	{
		TreeNode * neu = new TreeNode(Name, Alter, Einkommen, PLZ);

		add_intern(anker, neu);

		return true;
	}
	void Tree::add_intern(TreeNode * ptr, TreeNode * neu)
	{
		if (ptr == nullptr) // Fall: Baum ist leer (erster Eintrag)
			anker = neu;

		else // Normalfall: neu in Baum einfuegen
		{
			if (neu->NodePosID < ptr->NodePosID)
			{
				if (ptr->links == nullptr)
					ptr->links = neu;

				else add_intern(ptr->links, neu);
			}
			else if (neu->NodePosID > ptr->NodePosID)
			{
				if (ptr->rechts == nullptr)
					ptr->rechts = neu;

				else add_intern(ptr->rechts, neu);
			}
		}
	}

	bool Tree::deleteNode(int PosID)
	{
		if (anker == nullptr)
			return false;

		if (PosID == anker->NodePosID) // Fall 0: Wurzelknoten
		{
			delete_intern(anker, nullptr);
			return true;
		}

		// Normalfall: Knoten im Baum suchen

		TreeNode * prev = anker, *ptr = nullptr;

		if (PosID > anker->NodePosID)
			ptr = anker->rechts;

		else if (PosID < anker->NodePosID)
			ptr = anker->links;

		while (ptr != nullptr)
		{
			if (PosID == ptr->NodePosID)
			{
				delete_intern(ptr, prev);
				return true;
			}

			prev = ptr;

			if (PosID > ptr->NodePosID)
				ptr = ptr->rechts;

			else if (PosID < ptr->NodePosID)
				ptr = ptr->links;
		}

		return false;
	}
	void Tree::delete_intern(TreeNode * delnode, TreeNode * prev)
	{
		if (delnode == anker)
		{
			if (anker->rechts == nullptr && anker->links == nullptr)
			{
				delete anker;
				anker = nullptr;
				return;
			}
			else if (anker->rechts != nullptr && anker->links != nullptr)
			{
				TreeNode * ptr = anker->rechts;
				while (ptr->links != nullptr) ptr = ptr->links;
				ptr->links = anker->links;

				ptr = anker->rechts;
				delete anker;
				anker = ptr;
			}
			else if (anker->rechts != nullptr && anker->links == nullptr)
			{
				TreeNode * ptr = anker->rechts;
				delete anker;
				anker = ptr;
			}
			else if (anker->links != nullptr && anker->rechts == nullptr)
			{
				TreeNode * ptr = anker->links;
				delete anker;
				anker = ptr;
			}

			return;
		}

		// Fall 1: 0 Nachfolger
		if (delnode->links == nullptr && delnode->rechts == nullptr)
		{
			if (prev->links == delnode)
				prev->links = nullptr;

			else if (prev->rechts == delnode)
				prev->rechts = nullptr;
		}

		// Fall 2: 1 Nachfolger
		else if (delnode->links != nullptr && delnode->rechts == nullptr)
		{
			if (prev->rechts == delnode)
				prev->rechts = delnode->links;

			else if (prev->links == delnode)
				prev->links = delnode->links;
		}
		else if (delnode->rechts != nullptr && delnode->links == nullptr)
		{
			if (prev->rechts == delnode)
				prev->rechts = delnode->rechts;

			else if (prev->links == delnode)
				prev->links = delnode->rechts;
		}

		// Fall 3: 2 Nachfolger
		else if (delnode->links != nullptr && delnode->rechts != nullptr)
		{
			if (prev->rechts == delnode)
			{
				prev->rechts = delnode->links;

				TreeNode * ptr = delnode->links;
				while (ptr->rechts != nullptr) ptr = ptr->rechts;
				ptr->rechts = delnode->rechts;
			}
			else if (prev->links == delnode)
			{
				prev->links = delnode->rechts;

				TreeNode * ptr = delnode->rechts;
				while (ptr->links != nullptr) ptr = ptr->links;
				ptr->links = delnode->links;
			}
		}

		// Knoten loeschen
		delete delnode;
	}

	bool gefunden = false;
	bool Tree::search(std::string Name)
	{
		if (anker == nullptr) return false;

		if (anker != nullptr)
			search_intern(anker, Name);

		if (!gefunden)
			return false;

		gefunden = false; // fuer spaetere Suche
		return true;
	}
	void Tree::search_intern(TreeNode * ptr, std::string Name)
	{
		if (ptr->Name == Name)
		{
			ausgabe_suche(ptr);
			gefunden = true;
		}

		if (ptr->links != nullptr)
			search_intern(ptr->links, Name);

		if (ptr->rechts != nullptr)
			search_intern(ptr->rechts, Name);
	}
	void Tree::ausgabe_suche(TreeNode * ptr)
	{
		static int counter = 0;

		if (counter == 0)
			std::cout << "+ Fundstellen:" << std::endl;

		std::cout << "NodeID: " << ptr->NodeID << ", "
			<< "Name: " << ptr->Name << ", "
			<< "Alter: " << ptr->Alter << ", "
			<< "Einkommen: " << ptr->Einkommen << ", "
			<< "PLZ: " << ptr->PLZ << ", "
			<< "PosID " << ptr->NodePosID << std::endl;

		counter++;
	}

	void Tree::print()
	{
		if (anker == nullptr)
		{
			ausgabe(nullptr);
			return;
		}

		print_preorder(anker);
	}
	void Tree::print_preorder(TreeNode * ptr)
	{
		ausgabe(ptr);

		if (ptr->links != nullptr)
			print_preorder(ptr->links);

		if (ptr->rechts != nullptr)
			print_preorder(ptr->rechts);
	}
	void Tree::ausgabe(TreeNode * ptr)
	{
		using namespace std;
		cout << setfill(' ');

		if (ptr == nullptr)
		{
			cout << "+ Es wurden keine Daten zum Ausgeben gefunden" << endl;
			return;
		}

		if (ptr == anker)
		{
			cout << left << setw(2) << "ID" << " | "
				<< left << setw(10) << "Name" << " | "
				<< left << setw(5) << "Alter" << " | "
				<< left << setw(9) << "Einkommen" << " | "
				<< left << setw(3) << "PLZ" << " | "
				<< left << setw(3) << "Pos" << endl;

			cout << "---+------------+-------+-----------+-----+-------" << endl;
		}

		cout << left << setw(2 + 1) << ptr->NodeID << "|"
			<< right << setw(10 + 2) << ptr->Name << "|"
			<< right << setw(5 + 2) << ptr->Alter << "|"
			<< right << setw(9 + 2) << ptr->Einkommen << "|"
			<< right << setw(4 + 1) << ptr->PLZ << "|"
			<< ptr->NodePosID << endl;
	}

	void trennlinie(char c, int anz)
	{
		while (anz-- > 0)
			std::cout << c;

		std::cout << std::endl;
	}
};