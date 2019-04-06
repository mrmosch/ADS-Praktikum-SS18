#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Tree.h" 

void einfuegen_manuell(Tree& tree)
{
	cout << "+ Bitte geben Sie den Datensatz ein\n";

	cout << "Name ?> ";
	string Name; getline(cin, Name);

	cout << "Alter ?> ";
	int Alter; cin >> Alter; cin.ignore(); cin.clear();

	cout << "Einkommen ?> ";
	double Einkommen; cin >> Einkommen; cin.ignore(); cin.clear();

	cout << "PLZ ?> ";
	int PLZ; cin >> PLZ; cin.ignore(); cin.clear();

	if (tree.addNode(Name, Alter, Einkommen, PLZ))
		cout << "+ Ihr Datensatz wurde eingefuegt\n";
	else
		cout << "+ Beim Einfuegen des Datensatzes ist ein Fehler aufgetreten\n";
}

void einfuegen_csv(Tree& tree)
{
	cout << "Moechten Sie die Daten aus der Datei 'ExportZielanalyse.csv' importieren (j/n) ?>";
	char antwort; cin >> antwort; cin.ignore(); cin.clear();

	if (antwort == 'j')
	{
		ifstream csv("ExportZielanalyse.csv");

		if (!csv.is_open())
		{
			cout << "+ Fehler beim Einlesen der Datei\n";
			return;
		}

		std::string speicher;

		while (!csv.eof())
		{
			string Name; getline(csv, Name, ';');
			getline(csv, speicher, ';'); int Alter = std::stoi(speicher);
			getline(csv, speicher, ';'); double Einkommen = std::stoi(speicher);
			getline(csv, speicher, '\n'); int PLZ = std::stoi(speicher);

			if (!tree.addNode(Name, Alter, Einkommen, PLZ))
				cout << "+ Beim Einfügen mind. eines Datensatzes ist ein Fehler aufgetreten\n";
		}

		cout << "+ Daten wurden dem Baum hinzugefuegt\n";
	}
}

void loeschen(Tree& tree)
{
	cout << "+ Bitte geben Sie den zu loeschenden Datensatz an\n"
		<< "PosID ?> ";
	int PosID; cin >> PosID; cin.ignore(); cin.clear();

	if (tree.deleteNode(PosID))
		cout << "+ Datensatz wurde geloescht\n";
	else
		cout << "+ Der zu loeschende Datensatz wurde nicht gefunden\n";
}

void suchen(Tree& tree)
{
	cout << "+ Bitte geben Sie den zu suchenende Datensatz an\n"
		<< "Name ?> ";
	string Name; getline(cin, Name);

	if (!tree.search(Name))
		cout << "+ Der gesuchte Datensatz wurde nicht gefunden.\n";
}

void menu(Tree& tree)
{
	// Titel
	tree.trennlinie('=', 34);
	cout << "Person Analyser v19.84, by George Orwell\n";
	tree.trennlinie('=', 34);

	// Auswahl
	int auswahl = 0;
	cout << "1) Datensatz einfuegen, manuell\n"
		<< "2) Datensatz einfuegen, CSV Datei\n"
		<< "3) Datensatz loeschen\n"
		<< "4) Suchen\n"
		<< "5) Datenstruktur anzeigen\n"
		<< "?> "; cin >> auswahl;

	cin.ignore(); cin.clear();

	switch (auswahl)
	{
	case 1: // Datensatz einfuegen, manuell
		einfuegen_manuell(tree);
		break;

	case 2: // Datensatz einfuegen, CSV Datei
		einfuegen_csv(tree);
		break;

	case 3: // Datensatz loeschen
		loeschen(tree);
		break;

	case 4: // Suchen
		suchen(tree);
		break;

	case 5: // Datenstruktur anzeigen
		tree.print();
		break;

	default:
		cout << "Falsche Eingabe! Bitte fuehren Sie das Programm erneut aus." << endl;
	}
}

int main()
{
	Tree tree;

	char weiter;

	do {
		menu(tree);

		cout << "Soll eine weitere Aktion ausgefuehrt werden? (j/n)\n"
			<< "> "; cin >> weiter;

	} while (weiter == 'j');

	system("PAUSE");
	return 0;
}