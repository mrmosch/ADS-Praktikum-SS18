#pragma once
#include <string>

class RingNode
{
private:
	int OldAge = -1;
	std::string Description;
	std::string SymbolicData;
	RingNode* next;
public:
/*RingNode::RingNode(std::string desc, std::string data)
{
	int OldAge = 0;
	std::string description = desc;
	std::string symbolicDescription = data;
}*/

int RingNode::getAge()
{
	return OldAge;
}

void RingNode::setAge(int age)
{
	OldAge = age;
}

std::string RingNode::getDescription()
{
	return Description;
}

void RingNode::setDescription(std::string desc)
{
	Description = desc;
}

std::string RingNode::getData()
{
	return SymbolicData;
}

void RingNode::setData(std::string data)
{
	SymbolicData = data;
}

RingNode RingNode::setNext(RingNode* tmp)
{
	RingNode* nextNode;
	nextNode = tmp->next;
}

friend class RingPuffer;

};
