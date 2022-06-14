#pragma once
#include <string>
#include "Model.h"

class UserInterface
{
	bool is_end;
	unsigned int user_choice;
	Model model;
	void printPersonList();
	void addPersonToList();
	void changePersonInList();
	void printDateList();
	void addDateToList();
	void printAttendanceList();
	void setAttendanceList();
public:
	UserInterface(Model model);
	void menu();
};

