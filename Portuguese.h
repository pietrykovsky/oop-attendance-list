#pragma once
#include "Person.h"

class Portuguese : public Person{
public:
	Portuguese();
	Portuguese(std::string firstname, std::string lastname, bool sex, unsigned int age, std::string person_id, Date birthdate);

	bool setPerson_id(std::string person_id);
};

