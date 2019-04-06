#include <iostream>
#include "Aufgabe1a_List.h"
#include <cmath>
using namespace std;

int main(void)
{
	int i;
	List MyList;
	

	/*for (i = 0; i < 10; i++) {
		MyList.InsertFront(i);
		MyList.InsertBack(i+100);
	}*/
	MyList.InsertBack(1);
	MyList.InsertBack(2);
	MyList.InsertBack(3);
	MyList.InsertBack(4);
	MyList.InsertBack(5);
	MyList.InsertBack(6);
	MyList.InsertBack(7);
	MyList.InsertBack(8);
	MyList.InsertBack(9);
	MyList.InsertBack(0);


	cout << MyList;
	//MyList.swap_singlylinked(MyList.getNodeByKey(2), MyList.getNodeByKey(1));
	cout << MyList;
	

	//MyList.BubbleSort();
	//MyList.SelectionSort();
	std::cout << "jetzt kommt insertionsort:" << endl << endl;
	MyList.InsertionSort();
	cout << MyList;
	std::cout << endl << "jetzt kommt invertieren: " << endl << endl;
	MyList.invert();
	cout << MyList;


	/*
	cout << "100: " << (MyList.search(100) ? "gefunden" : "nicht gefunden") << endl;
	cout << "99: " << (MyList.search(99) ? "gefunden" : "nicht gefunden") << endl << endl;

	while (MyList.getBack(i))
		cout << i << " ";
	cout << endl << endl;

	List MyList1, MyList2, MyList3;
	List * MyList_dyn = new List;

	for (i = 0; i < 10; i++) {
		MyList1.InsertFront(i + 1);
		MyList2.InsertBack(i + 100);
	}*/

	

	//MyList1.format("MyList1\n<<", ", ", ">>\n\n");
	//cout << MyList1;

	//MyList_dyn->format("MyList_dyn\n<<", ", ", ">>\n\n");
	//MyList_dyn->InsertFront(-111);
	//cout << MyList_dyn;

	//MyList2.format("MyList2\n<<", ", ", ">>\n\n");
	//cout << MyList2;

	//MyList3 = MyList1 + MyList_dyn + MyList2;

	//delete MyList_dyn;

	//cout << "Groesse von MyList3: " << MyList3.size() << endl << endl;

	//MyList3.format("MyList3\n<<", ", ", ">>\n\n");
	//cout << MyList3 << endl;

	//cout << "tauschen von 8 mit 103\n\n";
	////MyList3.swap(9, 8);

	//cout << MyList3;

	/*if (MyList3.test())
		cout << "MyList3: Zeiger OK\n";
	else
		cout << "MyList3: Zeiger ******Error\n";
*/
	system("Pause");
	return 0;
}