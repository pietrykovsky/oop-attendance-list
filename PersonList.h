#pragma once
#include "Person.h"

class PersonList
{
	unsigned int size;
	Person *person;

public:
	PersonList();
	PersonList(unsigned int size);
	bool add(Person person); //add person to end of the list

	//setters
	bool setPerson(Person person, unsigned int index);

	//getters
	unsigned int getSize();
	Person getPerson(unsigned int index);
	Person * getList();
};

