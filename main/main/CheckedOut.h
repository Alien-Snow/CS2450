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
#include<ctime>

class CheckedOut
{
	static const size_t TWO_WEEKS = 14;

	size_t patronId;
	size_t isbn;
	tm dueDate;

	struct checkOutStruct{
		int patronId;
		int isbn;
		tm dueDate;
	};
public:
	CheckedOut(size_t id, size_t bookNum);
	~CheckedOut();
	double returned(checkOutStruct& book);
};

#endif

