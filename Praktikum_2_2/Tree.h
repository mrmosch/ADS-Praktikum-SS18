#pragma once

#include "TreeNode.h"

class Tree {
private:
	TreeNode * anker;

	void add_intern(TreeNode * anker, TreeNode * neu);
	void delete_intern(TreeNode * delnode, TreeNode * prev = nullptr);
	void search_intern(TreeNode * ptr, std::string Name);
	void ausgabe_suche(TreeNode * ptr);
	void print_preorder(TreeNode * ptr);
	void ausgabe(TreeNode * ptr);

public: 
	Tree();
	bool addNode(std::string Name, int Alter, double Einkommen, int PLZ);
	bool deleteNode(int PosID);
	bool search(std::string Name);
	void print();
};

void trennlinie(char c, int anz);
