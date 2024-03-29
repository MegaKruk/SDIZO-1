#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <math.h>
#include <string>


using namespace std;

class Heap //Kopiec binarny
{
private:
	int *p;
	string upperCorner, lowerCorner, vertical;
public:
	int numbOfElements;
	Heap()
	{
		upperCorner = lowerCorner = vertical = "  ";
		upperCorner[0] = 218; upperCorner[1] = 196;
		lowerCorner[0] = 192; lowerCorner[1] = 196;
		vertical[0] = 179;
		numbOfElements = 0;
		p = new int[numbOfElements + 1];
	};
	~Heap()
	{
		numbOfElements = 0;
		delete[]p;
	};
	void randomFill(int n); //Losowe wypełnienie
	void buildFromFile(string name); //Budowanie z pliku
	void buildHeap(); //Budowanie kopca
	void Display(string text1, string text2, int nodeNumber); //Wyświetlenie
	bool Search(int numbToFind); //Przeszukiwanie
	void Add(int numbToAdd); //Dodawanie
	void Relocate(); //Relokacja
	void Delete(int numbToDelete); //Usuwanie
};
	class Table //Tablica
	{
	public:
		int numbOfElements;
	private:
		int *p;
	public:
		Table()
		{
			numbOfElements = 0;
			p = new int[numbOfElements];
		}

		~Table()
		{
			delete[]p;
			numbOfElements = 0;
		}
		void randomFill(int numb); //Losowe wypełnienie
		void display(); //Wyświetlenie tablicy
		void Delete(int ElementIndex); //Usuwanie Elementu
		void relocate();
		void DeleteFromBeginning(); //Usunięcie z początku
		void DeleteFromEnd(); //Usunięcie z końca
		void AddInBeginning(int newElementValue);
		void AddAtEnd(int valueOfNewElement);
		void Add(int newElementIndex, int newElementValue); //Dodanie we wskazanym miejscu
		void Search(int numbToFind); //Wyszukiwanie
		void BuildFromFile(string name); //Budowanie z pliku
	};

	class ListElement //Element listy dwukierunkowej
	{
	public:
		ListElement *nextElement, *prevElement;
		int key;
	};

	class List //Lista dwukierunkowa
	{
	private:
		ListElement *head, *tail;
	public:
		int NumbOfElements;
	public:
		List() //Konstruktor
		{

			tail = head = NULL;
			NumbOfElements = 0;

		}
		~List() //Destruktor
		{
			ListElement * element;

			while (head)
			{
				element = head->nextElement;
				delete head;
				head = element;
			}
			NumbOfElements = 0;
		}
		void randomFill(int n); //Losowe Wypełnienie Listy
		bool search(int NumbToFind); //Przeszukiwanie Listy
		void BuildFromFile(string name); //Budowanie Listy z Pliku 
		void AddNewElementUsingKey(int KeyOfPrevElement, int newKey); //Dodawanie za elementem o podanym kluczu
		void AddAtBeginning(int newKey); //Dodawanie na początku
		void AddAtEnd(int newKey); //Dodawanie na końcu
		void deleteFromBeginning(); //Usuwanie z początku
		void deleteFromEnd();
		void Delete(int keyToDelete); //Usuwanie po kluczu
		void Display();//Wyświetlanie listy
	};