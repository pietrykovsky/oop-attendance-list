#pragma once
#include "Person.h"
class Spanish : public Person
{
private:
	bool isPerson_idValid(int p[9]);
public:
	Spanish();
	Spanish(std::string firstname, std::string lastname, bool sex, unsigned int age, std::string person_id, Date birthdate);

	bool setPerson_id(std::string person_id);
};

