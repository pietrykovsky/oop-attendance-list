#pragma once
#include "PersonList.h"
#include "AttendanceList.h"

class Model
{
	unsigned int size;
	AttendanceList *attendance_list;

public:
	PersonList person_list;
	Model();
	Model(PersonList person_list);
	Model(unsigned int size, PersonList person_list);
	bool add(Date date);
	void print(Date date); //prints attendance list for the date
	void printDates();
	//getters
	AttendanceList get(Date date);
};