#pragma once
#include <string>
class TreeNode
{
private:
	int NodePosID; //alter+plz+einkommen
	int NodeID; //Fortlaufende Seriennummer
	std::string Name;
	int Alter; 
	double Einkommen;
	int PLZ;
	TreeNode* links;
	TreeNode* rechts;
public:
//////////////////////////////////////////Getter//////////////////////////////////////////
	TreeNode() {}
	TreeNode(std::string Name, int Alter, int Einkommen, int PLZ)
	{
		this->Name = Name;
		this->Alter = Alter;
		this->Einkommen = Einkommen;
		this->PLZ = PLZ;
	};
	std::string getName()
	{
		return this->Name;
	}
	int getAlter()
	{
		return this->Alter;
	}
	double getEinkommen()
	{
		return this->Einkommen;
	}
	int getPLZ()
	{
		return this->PLZ;
	}
//////////////////////////////////////////Setter//////////////////////////////////////////
	void setName(std::string tmp)
	{
		this->Name = tmp;
	}
	void setAlter(int i)
	{
		this->Alter = i;
	}
	void setEinkommen(double d)
	{
		this->Einkommen = d;
	}
	void setPLZ(int i)
	{
		this->PLZ = i;
	}
	void berechnePosID()
	{
		this->NodePosID = this->Alter + this->PLZ + this->Einkommen;
	}
//////////////////////////////////////////Funktionen//////////////////////////////////////////
	void printData()
	{
		//todo
	}

	friend class Tree;
};