#include "Header.h"

double PCFreqL = 0.0;
__int64 counterL = 0;

void startTimerL()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "Error!\n";

	PCFreqL = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	counterL = li.QuadPart;
}
void getTimeL()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operation took: " << (li.QuadPart - counterL) / PCFreqL << " miliseconds \n";

}


	void List::randomFill(int n) //Losowe Wype³nienie Listy
	{
		for (int i = 1; i <= n; i++)
			AddAtBeginning((rand() % 2000) - 1000);
	}
	bool List::search(int NumbToFind) //Przeszukiwanie Listy
	{
		bool Exist = false;
		ListElement *element;
		element = head;
		for (int i = 1; i <= NumbOfElements; i++)
		{
			if (element->key == NumbToFind) { Exist = true; break; }
			else element = element->nextElement;
		}
		return Exist;
	}
	void List::BuildFromFile(string name) //Budowanie Listy z Pliku 
	{
		string s;
		int i = 1;
		name = name + ".txt";
		ifstream file(name);
		if (!file)
			cout << "Can't open file." << endl;
		else
		{
			getline(file, s);
			int n = atoi(s.c_str());

			while (!file.eof())
			{
				if (i <= n)

				{
					getline(file, s);
					int key = atoi(s.c_str());
					AddAtEnd(key);
					i++;
				}
				else break;
			}
			file.close();
			for (i; i <= n; i++)
			{
				AddAtEnd(0);
			}
		}

	}
	void List::AddNewElementUsingKey(int KeyOfPrevElement, int newKey) //Dodawanie za elementem o podanym kluczu
	{
		counterL = 0;
		startTimerL();
		ListElement *element;
		ListElement * newElement = new ListElement();
		if (!(search(KeyOfPrevElement)))
		{
			AddAtBeginning(newKey);
			cout << "The element with certain value doesn't exist - added in the beginning \n";
		}
		else
		{
			element = head;
			for (unsigned i = 1; i <= NumbOfElements; i++)
			{
				if (element->key == KeyOfPrevElement)
				{
					newElement->nextElement = element->nextElement; newElement->prevElement = element;
					element->nextElement = newElement;

					if (newElement->nextElement) newElement->nextElement->prevElement = newElement;
					else tail = newElement;
					newElement->key = newKey;
					NumbOfElements++;
					break;
				}
				else element = element->nextElement;
			}

		}
		getTimeL();
	}
	void  List::AddAtBeginning(int newKey) //Dodawanie na pocz¹tku
	{
		ListElement * newElement = new ListElement();
		newElement->nextElement = head;
		newElement->prevElement = NULL;
		if (head) head->prevElement = newElement;
		head = newElement;
		if (!tail) tail = head;
		newElement->key = newKey;
		NumbOfElements++;
	}
	void List::AddAtEnd(int newKey) //Dodawanie na koñcu
	{
		ListElement * newElement = new ListElement();
		newElement->prevElement = tail;
		newElement->nextElement = NULL;
		if (tail) tail->nextElement = newElement;
		tail = newElement;
		if (!head) head = tail;
		newElement->key = newKey;
		NumbOfElements++;
	}
	void List::deleteFromBeginning() //Usuwanie z pocz¹tku
	{
		if (NumbOfElements == 0) cout << "List is empty, can't delete \n";
		else
		{
			counterL = 0;
			startTimerL();
			head = head->nextElement;
			NumbOfElements--;
			getTimeL();
		}

	}

	void List::deleteFromEnd() //Usuwanie z koñca
	{
		if (NumbOfElements == 0) cout << "List is empty, can't delete \n";
		else
		{
			counterL = 0;
			startTimerL();
			tail->prevElement->nextElement = NULL;
			tail->prevElement = tail;
			NumbOfElements--;
			getTimeL();
		}
	}
	void List::Delete(int keyToDelete) //Usuwanie po kluczu
	{
		ListElement *element;
		element = head;
		if (NumbOfElements == 0) cout << "List is empty, can't delete \n";
		else
		{
			counterL = 0;
			startTimerL();
			while ((element->nextElement != NULL) && (element->key != keyToDelete)) { element = element->nextElement; }
			if (element->key == keyToDelete)
			{
				if (element->nextElement) element->nextElement->prevElement = element->prevElement;
				else tail = element->prevElement;
				if (element->prevElement) { element->prevElement->nextElement = element->nextElement; }
				else head = element->nextElement;
				NumbOfElements--;
				getTimeL();
			}
			else cout << "The element with given key doesn't exist \n";
		}
	}
	void List::Display() //Wyœwietlanie listy
	{
		ListElement * element1 = new ListElement();
		ListElement * element2 = new ListElement();
		int i = 1;
		int j = NumbOfElements;
		if (!head) cout << "List is empty. \n";
		else
		{
			element1 = head;
			while (element1)
			{
				cout << " " << element1->key << " ";
				element1 = element1->nextElement;
				i++;
			}
			cout << endl;

			element2 = tail;
			while (element2)
			{
				cout << " " << element2->key << " ";
				element2 = element2->prevElement;
				j--;
			}
			cout << endl;
		}
		delete element1;
	};
