#include "UserInterface.h"
#include "PersonFactory.h"
#include <iostream>

UserInterface::UserInterface(Model model) {
	is_end = false;
	user_choice = NULL;
	this->model = model;
}

void UserInterface::menu() {
	while (!is_end) {
		std::cout << "\n\n-----MENU-----\n  1 - print list\n  2 - add person to the list\n  3 - change person in the list\n  4 - print date list\n  5 - add attendance list\n  6 - print attendance list\n  7 - set attendance \n  8 - exit\n\n";
		std::cout << "Insert number: ";
		std::cin >> user_choice;
		if (user_choice == 8)
			is_end = true;
		else {
			switch (user_choice) {
			case 1:
				printPersonList();
				break;
			case 2:
				addPersonToList();
				break;
			case 3:
				changePersonInList();
				break;
			case 4:
				printDateList();
				break;
			case 5:
				addDateToList();
				break;
			case 6:
				printAttendanceList();
				break;
			case 7:
				setAttendanceList();
				break;
			}
		}		
	}
}

void UserInterface::printPersonList() {
	Person *list = model.person_list.getList();
	unsigned int size = model.person_list.getSize();
	for (unsigned int i = 0; i < size; i++)
		list[i].print();
}

void UserInterface::addPersonToList() {
	std::string nationality;
	PersonFactory factory;
	Person person;
	do {
		std::cout << "Enter nationality: ";
		std::cin >> nationality;
		person = factory.getPersonFromUser(nationality);
	}  while (model.person_list.add(person));
}

void UserInterface::changePersonInList() {
	unsigned int index;
	PersonFactory factory;
	Person person;
	std::string nationality;
	do {
		std::cout << "Enter ID of the person: ";
		std::cin >> index;
		std::cout << "Enter nationality: ";
		std::cin >> nationality;
		person = factory.getPersonFromUser(nationality);
	} while (model.person_list.setPerson(person, index));
}
void UserInterface::printDateList() {
	AttendanceList *list = model.getList();
	unsigned int size = model.getSize();
	for (int i = 0; i < size; i++)
		list[i].getDate().print();
}
void UserInterface::addDateToList() {
	Date date;
	unsigned int day, month, year;
	do {
		std::cout << "Enter birhtdate (DD MM YYYY): ";
		std::cin >> day >> month >> year;
	} while (date.setDate(day, month, year));
	model.add(date);
}
void UserInterface::printAttendanceList() {
	Date date;
	unsigned int day, month, year;
	do {
		std::cout << "Enter birhtdate (DD MM YYYY): ";
		std::cin >> day >> month >> year;
	} while (date.setDate(day, month, year));
	AttendanceList* list = model.getList();
	unsigned int size = model.getSize();
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			if (list[i].getDate() == date) {
				for (int j = 0; j < model.person_list.getSize(); j++) {
					model.person_list.getPerson(j).print();
					std::cout << "Was present: ";
					if (list->getAttendance(j))
						std::cout << "Yes";
					else
						std::cout << "No";
					std::cout << "\n";
				}
			}

		}
	}
	else
		std::cout << "NIE MA TAKIEGO DNIA W BAZIE DANYCH" << '\n';
}
void UserInterface::setAttendanceList() {
	Date date;
	unsigned int day, month, year, index;
	do {
		std::cout << "Enter date (DD MM YYYY): ";
		std::cin >> day >> month >> year;
	} while (date.setDate(day, month, year));
	std::cout << "Enter ID of the person: ";
	std::cin >> index;
	if (model.getDate(date).getAttendance(index))
		model.getDate(date).setAttendance(false, index);
	else
		model.getDate(date).setAttendance(true, index);
}