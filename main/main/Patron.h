#ifndef PATRON_H
#define PATRON_H

#if _MSC_VER > 1000
#pragma once
#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<string>
#include<iomanip>
#include<iostream>
#include<sstream>

class Patron{
	static int nextId;

	int patronId;
	std::string firstName;
	std::string lastName;
	std::string address;
	double fineOwed;

	struct patronStruct{
		int patronId;
		char firstName[25];
		char lastName[25];
		char address[25];
		double fineOwed;
	};

public:
	Patron(const std::string& first = "", const std::string& last = "", const std::string address = "", double bal = 0.0)\
		: firstName(first), lastName(last), address(address){
		this->patronId = Patron::nextId += 1;
		this->fineOwed = bal;
	};
	~Patron();
	void setFirstName(std::string first){ this->firstName = first; };
	void setLastName(std::string last){ this->lastName = last; };
	void setAddress(std::string address){ this->address = address; };
	void setBalance(double owe){ this->fineOwed = owe; };
	void display(std::ostream& os) const;
	void write(std::fstream& fs) const;
	void store(std::fstream& fs) const;
	static Patron* findByName(std::fstream& fs, std::string& first, std::string& last);
	static Patron* findById(std::fstream& fs, int id);
};

#endif

