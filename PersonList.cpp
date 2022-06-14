#include "PersonList.h"
#include <iostream>

PersonList::PersonList() {
	this->size = 0;
	person = new Person[size];
}

PersonList::PersonList(unsigned int size) {
	this->size = size;
	person = new Person[size];
}

bool PersonList::add(Person person) {
	Person *temp = new Person[size];
	for (unsigned int i = 0; i < size; i++)
		temp[i] = this->person[i];
	delete[] this->person;
	this->person = new Person[size + 1];
	for (unsigned int i = 0; i < size; i++)
		this->person[i] = temp[i];
	this->person[size] = person;
	delete[] temp;
	size++;

	return 0;
}

void PersonList::print() {
	for (unsigned int i = 0; i < size; i++) {
		std::cout << "\nID: " << i << '\n';
		person[i].print();
		std::cout << '\n';
	}
}

//setters
bool PersonList::setPerson(Person person, unsigned int index) {
	if (index >= size)
		return 1;
	else
		this->person[index] = person;

	return 0;
}

//getters
Person PersonList::getPerson(unsigned int index) {
	if (index < size)
		return person[index];
}

unsigned int PersonList::getSize() {
	return size;
}