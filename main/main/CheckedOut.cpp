#include "CheckedOut.h"

CheckedOut::CheckedOut(size_t id, size_t bookNum){
	this->patronId = id;
	this->isbn = bookNum;
	time_t raw;
	auto current = localtime(&raw);
	current->tm_mday += TWO_WEEKS;
	mktime(current);
	this->dueDate = *current;
}

CheckedOut::~CheckedOut(){

}
