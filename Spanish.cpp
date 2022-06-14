#include "Spanish.h"
#include <iostream>

bool Spanish::isPerson_idValid(int p[9]) {
    int n = 0, j = 1;

    for (int i = 7; i >= 0; i--) {
        n += p[i] * j;
        j *= 10;
    }
    if (n % 23 == p[8])
        return 1;
    return 0;
}

Spanish::Spanish() {}

Spanish::Spanish(std::string firstname, std::string lastname, bool sex, unsigned age, std::string person_id, Date birthdate) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->sex = sex;
    this->age = age;
    if (setPerson_id(person_id))
        std::cout << "\n\nERROR - PERSON ID IS NOT VALID\n\n";
    if (setBirthdate(birthdate))
        std::cout << "\n\nERROR - BIRTHDATE IS NOT VALID\n\n";
}

bool Spanish::setPerson_id(std::string person_id) {
    if (person_id.length() == 9) {
        std::string dict = "TRWAGMYFPDXBNJZSQVHLCKE";
        if (!(dict.find(person_id[8]) != std::string::npos))
            return 1;

        for (int i = 0; i < person_id.length()-1; i++)
            if (person_id[i] < 48 || person_id[i] > 57)
                return 1;
         
        //konwersja person_id na tablice int na potrzebe funkcji walidacyjnej wzietej z programu z poprzedniego semestru
        int p[9];
        for (int i = 0; i < 8; i++)
            p[i] = int(person_id[i]) - 48;
        
        for (int i = 0; i < dict.length(); i++) {
            if (dict[i] == person_id[8])
                p[8] = i;
        }
        //sprawdzamy czy pesel jest poprawny
        if (isPerson_idValid(p))
            this->person_id = person_id;
        else
            return 1;
    }
    else
        return 1;

    return 0;
}