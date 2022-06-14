#include "Portuguese.h"
#include <iostream>

Portuguese::Portuguese() {}

Portuguese::Portuguese(std::string firstname, std::string lastname, bool sex, unsigned age, std::string person_id, Date birthdate) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->sex = sex;
    this->age = age;
    if (setPerson_id(person_id))
        std::cout << "\n\nERROR - PERSON ID IS NOT VALID\n\n";
    if (setBirthdate(birthdate))
        std::cout << "\n\nERROR - BIRTHDATE IS NOT VALID\n\n";
}

bool Portuguese::setPerson_id(std::string person_id) {
    if (person_id.length() == 8) {
        for (int i = 0; i < person_id.length(); i++)
            if (person_id[i] < 48 || person_id[i] > 57)
                return 1;
    }
    else
        return 1;
    this->person_id = person_id;
    return 0;
}