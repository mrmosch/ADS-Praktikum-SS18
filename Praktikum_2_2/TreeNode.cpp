#include "TreeNode.h"

int TreeNode::counter = 0;

TreeNode::TreeNode(std::string Name, int Alter, double Einkommen, int PLZ)
{
	this->Name = Name;
	this->Alter = Alter;
	this->Einkommen = Einkommen;
	this->PLZ = PLZ;

	this->NodePosID = Alter + PLZ + Einkommen;

	this->NodeID = counter++;
}
