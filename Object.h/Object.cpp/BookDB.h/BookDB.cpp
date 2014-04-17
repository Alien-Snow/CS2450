#pragma once
#include <string>
class Object
{
public:
	Object();
	~Object();
	std::string Title;
	std::string Author;
	std::string ISBN;
	int total, available;
};

//Object.cpp

#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
}

//BookDB.h

#pragma once
#include "Object.h"
#include <string>
#include <vector>
class BookDB
{
public:
	std::string temp_title, temp_author, temp_isbn, temp_available, temp_total;
	std::vector<Object> Books;
	BookDB();
	~BookDB();
	void ReadBooks();
	void ReadAvailable();
	Object* SearchBooks(std::string);
	void AddNewBook(std::string, std::string, std::string);
	void CheckOutBook(std::string);
	void ClearLibrary();
};

//BookDB.cpp

#include "BookDB.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

BookDB::BookDB()
{
}

BookDB::~BookDB()
{
}

void BookDB::ReadBooks()
{
	temp_title = "", temp_author = "", temp_isbn = "", temp_total = "", temp_available = "";
	string line = "";
	ifstream ReadFile("BookDB.txt");
	while (ReadFile)
	{
		getline(ReadFile, line);
		temp_title = strtok(&line[0], ",");
		temp_author = strtok(NULL, ",");
		temp_isbn = strtok(NULL, ",");
		temp_available = strtok(NULL, ",");
		temp_total = strtok(NULL, ",");
		Object Bob;
		Bob.Title = temp_title;
		Bob.Author = temp_author;
		Bob.ISBN = temp_isbn;
		Bob.available = stoi(temp_available);
		Bob.total = stoi(temp_total);
		Books.push_back(Bob);
	}
}

Object* BookDB::SearchBooks(string mine)
{
	for (size_t i = 0; i < Books.size(); i++)
	{
		if (mine == Books[0].Title)
		{
			return &Books[0];
		}
		else if (mine == Books[0].Author)
		{
			return &Books[0];
		}
		else if (mine == Books[0].ISBN)
		{
			return &Books[0];
		}
	}
	return NULL;
}

void BookDB::CheckOutBook(string mine)
{
	for (size_t i = 0; i < Books.size(); i++)
	{
		if (mine == Books[0].ISBN)
		{
			if (Books[0].available == 0)
			{
				cout << "Book is not available. Sorry!" << endl;
			}
			else
			{
				cout << "Book is available, thank you for your patronage!" << endl;
				Books[0].available--;
			}
		}
	}
}

void BookDB::ClearLibrary()
{
	Books.clear();
}
