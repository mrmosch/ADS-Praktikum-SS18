#include "List.h"
#include <iostream>

int main() {

	std::cout << "Liste wird erstellt" << std::endl;
	List myList;

	int eingabe = -1; 
	for (int i = 1; i < 6; i++)
	{
		std::cout << "Bitte geben sie die " << i << ". Zahl ein." << std::endl;
		std::cin >> eingabe; 
		myList.insertBack(eingabe); 
	}
	myList.print();
	
	system("Pause");
	return 0;
}