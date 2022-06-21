#include "Model.h"
#include <iostream>

Model::Model() {
	size = 0;
	attendance_list = new AttendanceList[size];
}

Model::Model(PersonList person_list) {
	size = 0;
	this->person_list = person_list;
	attendance_list = new AttendanceList[size];
}

Model::Model(unsigned int size, PersonList person_list) {
	this->size = size;
	this->person_list = person_list;
	attendance_list = new AttendanceList[size];
}
bool Model::add(Date date) {
	AttendanceList* temp = new AttendanceList[size];
	for (unsigned int i = 0; i < size; i++)
		temp[i] = attendance_list[i];
	delete[] attendance_list;
	attendance_list = new AttendanceList[size + 1];
	for (unsigned int i = 0; i < size; i++)
		attendance_list[i] = temp[i];
	attendance_list[size] = AttendanceList(date, person_list.getSize());
	delete[] temp;
	size++;

	return 0;
}

AttendanceList Model::getDate(Date date) {
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			if (attendance_list[i].getDate() == date) {
				return attendance_list[i];
			}
		}
	}
}

AttendanceList* Model::getList()
{
	return attendance_list;
}

unsigned int Model::getSize() {
	return size;
}
