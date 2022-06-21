#pragma once
#include "PersonList.h"
#include "AttendanceList.h"

class Model
{
	unsigned int size;
	AttendanceList *attendance_list;
	//PersonList person_list;
public:
	PersonList person_list;
	Model();
	Model(PersonList person_list);
	Model(unsigned int size, PersonList person_list);
	bool add(Date date);
	//getters
	AttendanceList getDate(Date date);
	AttendanceList* getList();
	unsigned int getSize();
};