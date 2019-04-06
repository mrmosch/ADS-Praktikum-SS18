#pragma once

#include <string>

class TreeNode {
private:
	int NodePosID;
	int NodeID;
	std::string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	
	TreeNode * links = nullptr;
	TreeNode * rechts = nullptr;

	friend class Tree;

public:
	TreeNode() {}
	TreeNode(std::string Name, int Alter, double Einkommen, int PLZ);
	std::string getName() { return Name; }
	int getAlter() { return Alter; }
	double getEinkommen() { return Einkommen; }
	int getPLZ() { return PLZ; }
	void setName(std::string Name) { this->Name = Name; }
	void setAlter(int Alter) { this->Alter = Alter;}
	void setEinkommen(double Einkommen) { this->Einkommen = Einkommen; }
	void setPLZ(int PLZ) { this->PLZ = PLZ; }

	static int counter;
};