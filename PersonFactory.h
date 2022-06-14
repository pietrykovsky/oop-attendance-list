#pragma once
#include "Person.h"
#include <string>

class PersonFactory
{
public:
	PersonFactory();
	Person getPerson(std::string nationalilty);
	Person getPersonFromUser(std::string nationality);
};

