#pragma once
#include "PersonList.h"
#include "Date.h"

class AttendanceList
{
	unsigned int size;
	Date date;
	bool* attendance;

public:
	AttendanceList();
	AttendanceList(unsigned int size);
	AttendanceList(Date date, unsigned int size);
	void print();

	//setters
	bool setAttendance(bool attendance, unsigned int id);
	bool setDate(Date date);

	//getters
	bool getAttendance(unsigned int id);
	Date getDate();
};