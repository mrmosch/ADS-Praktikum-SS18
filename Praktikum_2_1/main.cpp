#include <iostream>
#include <string>
using namespace std;

#include "RingPuffer.h"

void einfuegen(RingPuffer& ring)
{
cout << "+Neuen Datensatz einfuegen\n";

cout << "Beschreibung ?> ";
string beschreibung; getline(cin, beschreibung);

cout << "Daten ?> ";
string daten; getline(cin, daten);

if(ring.addNode(beschreibung, daten))
cout << "+Ihr Datensatz wurde hinzugefuegt\n";
}

void suchen(RingPuffer& ring)
{
cout << "+Nach welchen Daten soll gesucht werden?\n"
<< "?> ";
string daten; getline(cin, daten);

if (!ring.search(daten))
cout << "+Der gesuchte Datensatz wurde nicht gefunden.\n";
}

void menu(RingPuffer& ring)
{
	ring.trennlinie('=', 34);
	cout << "OneRingToRuleThemAll v0.1, by Sauron Schmidt\n";
	ring.trennlinie('=', 34);

	// Auswahl
	int auswahl = 0;
	cout << "1) Backup einfuegen\n"
		<< "2) Backup suchen\n"
		<< "3) Alle Backups ausgeben\n"
		<< "?> "; cin >> auswahl;

	cin.ignore(); cin.clear();

	switch (auswahl)
	{
	case 1: // Backup einfuegen
		einfuegen(ring);
		break;

	case 2: // Backup suchen
		suchen(ring);
		break;

	case 3: // Alle Backups ausgeben
		ring.print();
		break;

	default:
		cout << "Falsche Eingabe! Bitte fuehren Sie das Programm erneut aus." << endl;
	}
}

int main()
{
RingPuffer ring;

char weiter;

do {
menu(ring);

cout << "Soll eine weitere Aktion ausgefuehrt werden? (j/n)\n"
<< "> "; cin >> weiter;

} while (weiter == 'j');

system("PAUSE");
return 0;
}