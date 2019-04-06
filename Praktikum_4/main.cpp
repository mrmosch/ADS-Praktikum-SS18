#include <iostream>
#include <string>

#include "graph.h"

void displayMenu()
{
	std::cout << "Working on Graphs. Please choose:" << std::endl
		<< "1) Graph einlesen" << std::endl
		<< "2) Tiefensuche" << std::endl
		<< "3) Breitensuche " << std::endl
		<< "4) Prim" << std::endl
		<< "5) Kruskal" << std::endl
		<< "6) Print Graph as nodelist" << std::endl
		<< "0) for quit" << std::endl
		<< "?> ";
}


int main() {

	//Insert a switch-case to call your algorithms
	//Maybe you can copy from older Projects
	Graph* myGraph = new Graph();
	int menuwahl = -1;
	int key = -1;

	while (menuwahl != 0) {

		do {
			displayMenu();
			std::cin >> menuwahl;
		} while (menuwahl > 6 || menuwahl < 0);

		//Read Graph
		if (menuwahl == 1)
		{
			std::string path;
			std::cout << "Insert path of Graphfile: " << std::endl;
			std::cin >> path;
			path += ".txt";

			bool done = myGraph->init(path);

			if (done)
				std::cout << "Initialize graph successful" << std::endl;
			else
				std::cout << "Cannot read file" << std::endl;
		}

		//Depthsearch
		if (menuwahl == 2)
		{
			std::cout << "Choose a startkey: " << std::endl;
			std::cin >> key;

			bool done = myGraph->depthSearchRek(key);

			if (done)
				std::cout << "Tiefensuche war erfolgreich." << std::endl;
			else
				std::cout << "! Bei der Tiefensuche ist ein Fehler aufgetreten." << std::endl;
		}

		//Breadthsearch
		if (menuwahl == 3) {

			std::cout << "Choose a startkey: " << std::endl;
			std::cin >> key;

			bool done = myGraph->breadthSearchIter(key);

			if (done)
				std::cout << "Breitensuche war erfolgreich." << std::endl;
			else
				std::cout << "! Bei der Breitensuche ist ein Fehler aufgetreten." << std::endl;
		}

		//Prim
		if (menuwahl == 4) {
			std::cout << "Choose a startkey: " << std::endl;
			std::cin >> key;

			std::cout << "Der Graph wurde mit den Kosten " << myGraph->prim(key) << " traversiert. (Prim Algorithmus)" << std::endl;
		}

		//Kruskal
		if (menuwahl == 5) {

			std::cout << "Der Graph wurde mit den Kosten " << myGraph->kruskal() << " traversiert. (Kruskal Algorithmus)" << std::endl;
		}

		//Print function
		if (menuwahl == 6) {
			bool done = myGraph->print();

			if (done)
				std::cout << "Print graph successful" << std::endl;
			else
				std::cout << "Not able to print" << std::endl;
		}

		//Quit
		if (menuwahl == 0) {
			delete myGraph;
		}
	}
	// system("PAUSE");
	return 0;
}
