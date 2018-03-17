#include<iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <math.h>
#include <string>
#include "Header.h"



using namespace std;

double PCFreq = 0.0;
__int64 counter = 0;

void startTimerM()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "Error!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	counter = li.QuadPart;
}
void getTimeM()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operation took: " << (li.QuadPart - counter) / PCFreq << " miliseconds \n";

}

int main() //Program g³ówny
{
	srand(time(NULL));
	bool atBeginning = true;
	while (atBeginning == true) {

		int choice;
		cout << "Pick the structure for testing \n 1. Table \n 2. List \n 3. Heap \n ";
		cin >> choice;


		system("cls");
		switch (choice)
		{
		case 1:
		{
			atBeginning = false;
			Table* table;
			table = new Table();
			int n;
			while (atBeginning == false)
			{
				cout << " Table of - " << table->numbOfElements << " elements\n What do you want to do? \n 1. Build from file \n 2. Randomize table \n 3. Delete \n 4. Add \n 5. Search \n 6. Display \n 7. Destroy Structure \n 8. Back to Structure Pick menu \n 9. Exit Program \n";
				cin >> choice;

				switch (choice)
				{
				case 1: 
					{
					string name;
					table = new Table();
					cout << "Enter the name of file to load data from\n";
					cin >> name;
					cout << endl;
					table->BuildFromFile(name);
					table->display();
				} break;
				case 2:
				{

					while (true)
					{
						cout << "How many elements to create? \n";
						cin >> n;
						if (n <= 0) cout << "Number should be more than zero ! \n";
						else break;
					}
					table = new Table();
					cout << endl;
					table->randomFill(n);
					table->display();
				}break;
				case 3: 
					{
					int  value;
					cout << "1. Delete from Beginning \n 2. Delete from End \n 3. Delete certain element \n";
					cin >> choice;
					switch (choice)

					{

					case 1:
					{
						table->DeleteFromBeginning();
						table->display();

					}break;

					case 2:
					{
						table->DeleteFromEnd();
						table->display();
					}break;
					case 3:
						{
						while (true)
						{
							cout << "Enter index of element you'd like to delete \n";
							cin >> n;
							cout << endl;
							if (n < 0) cout << "Number should be more than zero ! \n";
							else break;
						}

						table->Delete(n);
						table->display();

					}break;

					}

				}break;
				case 4: 
					{
					int  value;
					cout << "1. Add at Beginning \n 2. Add at End \n 3. Add in cretain place \n";
					cin >> choice;
					switch (choice)

					{

					case 1:
					{
						cout << "Enter value of new element \n";
						cin >> value;
						cout << endl;
						counter = 0;
						startTimerM();
						table->AddInBeginning(value);
						getTimeM();
						table->display();

					}break;

					case 2:
					{
						cout << "Enter value of new element \n";
						cin >> value;
						cout << endl;
						table->AddAtEnd(value);
						table->display();
					}break;
					case 3: 
						{
						while (true)
						{
							cout << "Enter index where new element should be added. \n";
							cin >> n;
							cout << endl;
							if (n < 0) cout << "Number should be more than zero! \n";
							else break;
						}

						cout << "Enter value of new Element \n";
						cin >> value;
						cout << endl;
						table->Add(n, value);
						table->display();

					}break;

					}


				}break;
				case 5: 
					{
					int  value;
					cout << "Enter value which you'd like to check if exists in table \n";
					cin >> value;
					cout << endl;
					table->Search(value);
					table->display();
				}break;
				case 6: 
					{
					table->display();
				}break;
				case 7: 
					{
					table->~Table();
					table = new Table();
				}break;
				case 8: 
					{
					delete table;
					system("cls");
					atBeginning = true;
				}break;
				case 9: 
					{
					delete table;
					return 0;
				}
				}
			}
		}break;
		case 2: 
			{
			atBeginning = false;
			unsigned n;
			List* list;
			list = new List();

			while (atBeginning == false) 
			{
				cout << "List of - " << list->NumbOfElements << " elements \n What do you want to do? \n 1. Build form file \n 2. Randomize list \n 3. Delete\n 4. Add \n 5. Search \n 6. Display \n 7. Destroy Structure \n 8. Back to Structure Pick menu \n 9. Exit Program \n";
				cin >> choice;
				switch (choice)
				{
				case 1: 
					{
					list->~List();
					list = new List();
					string name;
					cout << "Enter name of file to load data from \n";
					cin >> name;
					cout << endl;
					list->BuildFromFile(name);
					list->Display();
				}break;
				case 2: 
					{
					list->~List();
					while (true)
					{
						cout << "How many elements to create? \n";
						cin >> n;
						cout << endl;
						if (n <= 0) cout << "Number should be more than zero ! \n";
						else break;
					}
					list = new List();
					list->randomFill(n);
					list->Display();
				}break;
				case 3: 
					{
					int  value;
					cout << "1. Delete from Beginning \n 2. Delete from End \n 3. Delete chosen Element \n";
					cin >> choice;
					switch (choice)

					{

					case 1:
					{
						list->deleteFromBeginning();
						list->Display();

					}break;

					case 2:
					{
						list->deleteFromEnd();
						list->Display();
					}break;
					case 3: 
						{

						cout << "What to delete (element key)? \n";
						cin >> n;
						cout << endl;
						list->Delete(n);
						list->Display();

					}break;

					}

				}break;

				case 4: 
					{
					int  value;
					cout << "1. Add at Beginning \n 2. Add at End \n 3. Add behind chosen element \n";
					cin >> choice;
					switch (choice)

					{
					case 1:
					{
						cout << "Enter key of new Element \n";
						cin >> value;
						cout << endl;
						counter = 0;
						startTimerM();
						list->AddAtBeginning(value);
						getTimeM();
						list->Display();

					}break;

					case 2:
					{
						cout << "Enter key of new element \n";
						cin >> value;
						cout << endl;
						counter = 0;
						startTimerM();
						list->AddAtEnd(value);
						getTimeM();
						list->Display();
					}break;
					case 3: 
						{
						int key;
						cout << "Enter key of element to add \n";
						cin >> key;
						cout << endl;
						cout << "Behind which element you'd like to add new one (enter key)? \n";
						cin >> n;
						cout << endl;
						list->AddNewElementUsingKey(n, key);
						list->Display();

					}break;

					}



				}break;
				case 5: 
					{
					cout << "Enter key of element you'd like to check if is on list \n";
					cin >> n;
					cout << endl;
					counter = 0;
					startTimerM();
					list->search(n);
					getTimeM();
					list->Display();
					if (list->search(n)) cout << "Element you search is on the list \n";
					if (!list->search(n)) cout << "Element you search doesn't exist \n";


				}break;
				case 6: 
					{
					list->Display();
				}break;
				case 7: 
					{
					list->~List();
					list = new List();


				}break;
				case 8: 
					{
					delete list;
					system("cls");
					atBeginning = true;

				}break;
				case 9: 
					{
					delete list;
					return 0;
				}break;

				}


			}break;
		}break;
		case 3: 
			{
			atBeginning = false;
			int n;
			system("cls");
			Heap *heap;
			heap = new Heap();
			while (atBeginning == false)
			{
				cout << "Heap of - " << heap->numbOfElements << " elements \n What would you like to do? \n 1. Build from file \n 2. Randomize Heap \n 3. Delete \n 4. Add \n 5. Search \n 6. Display \n 7. Destroy Structure \n 8. Back to Structure Pick menu \n 9. Exit Program \n ";
				cin >> choice;

				switch (choice)
				{
				case 1: 
					{
					string file;
					cout << "Enter name of file to load data from \n ";
					cin >> file;
					cout << endl;
					heap = new Heap();
					heap->buildFromFile(file);
					heap->Display("   ", " ", 1);
				}break;

				case 2:
				{
					while (true)
					{
						cout << "How many elements to create? \n";
						cin >> n;
						if (n > 0) break;
						else cout << "Number should be more than zero ! \n";

					}
					heap = new Heap();
					heap->randomFill(n);
					heap->Display("   ", " ", 1);
				}break;
				case 3: 
					{
					cout << "What to delete (element key)? \n";
					cin >> n;
					cout << endl;
					heap->Delete(n);
					heap->Display("   ", " ", 1);

				}break;

				case 4: 
					{
					cout << "Enter key of element to add \n";
					cin >> n;
					cout << endl;
					heap->Add(n);
					heap->Display("   ", " ", 1);


				}break;

				case 5: 
					{
					cout << "Enter value which you'd like to check if exists in heap \n";
					cin >> n;
					cout << endl;
					counter = 0;
					startTimerM();
					heap->Search(n);
					getTimeM();
					if (heap->Search(n)) cout << "Element you search is in the heap \n";
					if (!heap->Search(n)) cout << "Element you search doesn't exist \n";
				}break;
				case 6: 
					{
					heap->Display("   ", " ", 1);
				}break;
				case 7: 
					{
					heap->~Heap();
					heap = new Heap();
				}break;
				case 8: 
					{
					system("cls");
					delete heap;
					atBeginning = true;
				}break;
				case 9: 
					{
					delete heap;
					return 0;
				}break;
				}
			}

		}break;
		}
	}
	system("pause");
	return 0;
}