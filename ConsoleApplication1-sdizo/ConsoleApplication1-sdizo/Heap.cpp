#include "Header.h"

double PCFreqH = 0.0;
__int64 counterH = 0;

void startTimerH()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "Error!\n";

	PCFreqH = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	counterH = li.QuadPart;
}
void getTimeH()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operation took: " << (li.QuadPart - counterH) / PCFreqH << " miliseconds \n";

}


	void Heap::randomFill(int n) //Losowe wype³nienie
	{
		numbOfElements = n;
		p = new int[numbOfElements + 1];
		for (int i = 1; i <= numbOfElements; i++)
			p[i] = ((rand() % 2000) - 1000);
		buildHeap();
	}

	void Heap::buildFromFile(string name) //Budowanie z pliku
	{
		string s;
		int i = 0;
		int *t;
		name = name + ".txt";
		ifstream file(name);

		if (!file)
		{
			cout << "Can't open file! \n";

		}
		else
		{
			getline(file, s);
			int n = atoi(s.c_str());
			numbOfElements = n;
			t = new int[numbOfElements];
			while (!file.eof())
			{
				if (i <= numbOfElements)
				{
					getline(file, s);
					t[i] = atoi(s.c_str());
					i++;
				}
				else break;
			}
			file.close();
			for (i; i <= numbOfElements; i++)
			{
				t[i] = 0;
			}
			p = t;
			buildHeap();
		}
	}
	void Heap::buildHeap() //Budowanie kopca
	{
		for (int i = 2; i <= numbOfElements; i++)
		{
			int elementPosition, parentPosition, element;
			elementPosition = i;
			parentPosition = (elementPosition) / 2;
			element = p[i];
			while ((parentPosition > 0) && (p[parentPosition] < element))
			{
				p[elementPosition] = p[parentPosition];
				elementPosition = parentPosition;
				parentPosition = (elementPosition) / 2;
			}
			p[elementPosition] = element;
		}
	}
	void Heap::Display(string text1, string text2, int nodeNumber) //Wyœwietlenie
	{
		if (numbOfElements == 0)
			cout << "Heap is empty! \n";
		string text;

		if (nodeNumber <= numbOfElements)
		{
			text = text1;
			if (text2 == upperCorner)
				text[text.length() - 2] = ' ';

			Display(text + vertical, upperCorner, 2 * nodeNumber + 1);

			text = text.substr(0, text1.length() - 2);

			cout << text << text2 << p[nodeNumber] << endl;

			text = text1;
			if (text2 == lowerCorner)
				text[text.length() - 2] = ' ';
			Display(text + vertical, lowerCorner, 2 * nodeNumber);
		}
	}
	bool Heap::Search(int numbToFind) //Przeszukiwanie
	{
		bool Exist = false;
		for (int i = 1; i <= numbOfElements; i++)
		{
			if (numbToFind == p[i])
			{
				Exist = true;
				break;
			}
		}
		return Exist;

	}
	void Heap::Add(int numbToAdd) //Dodawanie
	{
		counterH = 0;
		startTimerH();
		numbOfElements++;
		p[numbOfElements] = numbToAdd;
		int newElementPosition = numbOfElements;
		while ((p[newElementPosition] > p[newElementPosition / 2]) && (newElementPosition > 1))
		{
			int temp = p[newElementPosition / 2];
			p[newElementPosition / 2] = p[newElementPosition];
			p[newElementPosition] = temp;
			newElementPosition = (newElementPosition / 2);
		}
		Relocate();
		getTimeH();
	}
	void Heap::Relocate() //Relokacja
	{
		int *t = new int[numbOfElements + 1];
		for (int i = 1; i <= numbOfElements; i++)
		{
			t[i] = p[i];
		}
		p = new int[numbOfElements + 1];
		for (int i = 1; i <= numbOfElements; i++)
		{
			p[i] = t[i];
		}
		delete[]t;
	}
	void Heap::Delete(int numbToDelete) //Usuwanie
	{

		if (numbOfElements == 0) cout << "Heap is empty, can't delete anything! \n";
		else
		{
			if (!Search(numbToDelete)) cout << "The given number doesn't exist in heap, can't delete! \n";
			else
			{
				counterH = 0;
				startTimerH();
				int i;
				for (i = 1; i <= numbOfElements; i++)
				{
					if (p[i] == numbToDelete) break;
				}
				if (i == numbOfElements)
				{
					p[i] = NULL;
					numbOfElements--;
					getTimeH();
				}
				if (i < numbOfElements)
				{
					p[i] = p[numbOfElements];
					p[numbOfElements] = NULL;
					numbOfElements--;
					if (2 * i > numbOfElements)
					{
						while (i > 1)
						{
							if (p[i] > p[i / 2])
							{
								int temp = p[i / 2];
								p[i / 2] = p[i];
								p[i] = temp;
							}
							i = i / 2;
						}
					}
					else
					{
						while (i <= numbOfElements / 2)
						{
							if ((p[i] < (p[2 * i])) || (p[i] < (p[2 * i + 1])))
							{
								if (p[2 * i] > p[2 * i + 1])
								{
									int temp = p[i];
									p[i] = p[2 * i];
									p[2 * i] = temp;
									i = 2 * i;
								}
								else
								{
									int temp = p[i];
									p[i] = p[2 * i + 1];
									p[2 * i + 1] = temp;
									i = 2 * i + 1;
								}
							}
							else break;
						}

					}
				}
				getTimeH();
				Relocate();
			}
		}
	};
