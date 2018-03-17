#include "Header.h"

double PCFreqT = 0.0;
__int64 counterT = 0;

void startTimerT()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "Error!\n";

	PCFreqT = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	counterT = li.QuadPart;
}
void getTimeT()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operation took: " << (li.QuadPart - counterT) / PCFreqT << " miliseconds \n";

}


	void Table::randomFill(int numb) //Losowe wype³nienie
	{
		numbOfElements = numb;
		p = new int[2 * numbOfElements];
		for (int i = 0; i < numbOfElements; i++)
		{
			p[i] = ((rand() % 2000) - 1000);
		}

	}
	void Table::display() //Wyœwietlenie tablicy
	{
		if (numbOfElements == 0) cout << "Table is empty \n";
		else
		{
			for (int i = 0; i < numbOfElements; i++) { cout << i << ": " << p[i] << endl; }
			cout << endl;
		}
	}

	void Table::Delete(int ElementIndex) //Usuwanie Elementu
	{
		if (numbOfElements == 0) { cout << "Table is empty, can't delete! \n"; }
		else if (ElementIndex >= numbOfElements) cout << "Table has less elements now! \n";
		else
		{
			counterT = 0;
			startTimerT();
			for (int i = ElementIndex; i < numbOfElements; i++)
			{
				p[i] = p[i + 1];

			}

			numbOfElements--;
			getTimeT();
			relocate();
		}
	}

	void Table::relocate()
	{
		int *t = new int[numbOfElements];
		for (int i = 0; i < numbOfElements; i++)
		{
			t[i] = p[i];
		}
		p = new int[2 * numbOfElements];
		for (int i = 0; i < numbOfElements; i++)
		{
			p[i] = t[i];
		}
		delete[]t;
	}

	void Table::DeleteFromBeginning() //Usuniêcie z pocz¹tku
	{
		if (numbOfElements == 0) { cout << "Table is empty, can't delete anything... \n"; }
		else
		{
			counterT = 0;
			startTimerT();
			numbOfElements--;
			for (int i = 0; i < numbOfElements; i++)
			{
				p[i] = p[i + 1];
			}
			relocate();
			getTimeT();
		}

	}

	void Table::DeleteFromEnd() //Usuniêcie z koñca
	{
		if (numbOfElements == 0) { cout << "Table is empty, can't delete anything... \n"; }

		else
		{
			counterT = 0;
			startTimerT();
			p[numbOfElements - 1] = NULL;
			numbOfElements--;
			getTimeT();
			relocate();
		}
	}
	void Table::AddInBeginning(int newElementValue) //Dodanie na pocz¹tek
	{
		numbOfElements++;

		for (int i = numbOfElements - 1; i > 0; i--)
		{
			p[i] = p[i - 1];
		}
		p[0] = newElementValue;
		relocate();
	}
	void Table::AddAtEnd(int valueOfNewElement) //Dodanie na koniec
	{
		counterT = 0;
		startTimerT();
		p[numbOfElements] = valueOfNewElement;
		numbOfElements++;
		getTimeT();
		relocate();

	}
	void Table::Add(int newElementIndex, int newElementValue) //Dodanie we wskazanym miejscu
	{


		if (newElementIndex >= numbOfElements)
		{

			AddAtEnd(newElementValue);
			cout << "The given index is beyond size of table. Element has been added at the end of table. \n";
		}
		else
		{
			counterT = 0;
			startTimerT();
			numbOfElements++;
			for (int i = numbOfElements - 1; i > newElementIndex; i--)
			{
				p[i] = p[i - 1];
			}
			p[newElementIndex] = newElementValue;
			getTimeT();

		}

	}
	void Table::Search(int numbToFind) //Wyszukiwanie
	{
		counterT = 0;
		startTimerT();
		bool Exist = false;
		for (int i = 0; i < numbOfElements; i++) { if (numbToFind == p[i]) { Exist = true; break; } }
		getTimeT();
		if (Exist) cout << "The element you're searching for is in the table! \n";
		if (!Exist) cout << "There is no such element in table! \n";

	}
	void Table::BuildFromFile(string name) //Budowanie z pliku
	{
		string s;
		int i = 0;

		name = name + ".txt";
		ifstream file(name);

		if (!file)
		{
			cout << "Can't open file ! \n";

		}
		else
		{
			getline(file, s);
			int n = atoi(s.c_str());
			numbOfElements = n;
			while (!file.eof())
			{
				if (i < numbOfElements)
				{
					getline(file, s);
					p[i] = atoi(s.c_str());
					i++;
				}
				else break;

			}
			file.close();
			for (i; i < numbOfElements; i++)
			{
				p[i] = 0;
			}
			relocate();
		}

	};