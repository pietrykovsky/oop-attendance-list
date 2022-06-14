#include "Person.h"
#include <iostream>

bool Person::isPerson_idValid(int p[11]) {
    int sum = 1 * p[0] +
        3 * p[1] +
        7 * p[2] +
        9 * p[3] +
        1 * p[4] +
        3 * p[5] +
        7 * p[6] +
        9 * p[7] +
        1 * p[8] +
        3 * p[9];
    sum %= 10;
    if (sum == 0)
        return true;
    else {
        sum = 10 - sum;
        if (sum == p[10])
            return true;
        else
            return false;
    }
}

Date Person::convertBirthdate(int p[11]) {
    //ddmmrrrr
    int monthNumber = p[2] * 10 + p[3];
    int date[8];
    date[0] = p[4];
    date[1] = p[5];
    date[6] = p[0];
    date[7] = p[1];
    if (monthNumber >= 81 && monthNumber <= 92) {
        date[4] = 1;
        date[5] = 8;
        date[2] = p[2] - 8;
        date[3] = p[3];
    }
    else if (monthNumber >= 1 && monthNumber <= 12) {
        date[4] = 1;
        date[5] = 9;
        date[2] = p[2];
        date[3] = p[3];
    }
    else if (monthNumber >= 21 && monthNumber <= 32) {
        date[4] = 2;
        date[5] = 0;
        date[2] = p[2] - 2;
        date[3] = p[3];
    }
    else if (monthNumber >= 41 && monthNumber <= 52) {
        date[4] = 2;
        date[5] = 1;
        date[2] = p[2] - 4;
        date[3] = p[3];
    }
    int day, month, year;
    day = date[0] * 10 + date[1];
    month = date[2] * 10 + date[3];
    year = date[4] * 1000 + date[5] * 100 + date[6] * 10 + date[7];

    return Date(day, month, year);
}

Person::Person() {}

Person::Person(std::string firstname, std::string lastname, bool sex, unsigned age, std::string person_id) {
	this->firstname = firstname;
	this->lastname = lastname;
	this->sex = sex;
	this->age = age;
    if (setPerson_id(person_id))
        std::cout << "\n\nERROR - PERSON ID IS NOT VALID\n\n";
}

void Person::print() {
    std::cout << "\nfirstname: " << firstname << "\n" << "lastname: " << lastname << "\n";
    if (sex)
        std::cout << "sex: man\n";
    else
        std::cout << "sex: woman\n";
    std::cout << "age: " << age << "\n" << "birthdate: " << birthdate.toString() << "\n" << "person id: " << person_id << "\n";
}

//setters
bool Person::setFirstname(std::string firstname) {
	this->firstname = firstname;
	return 0;
}

bool Person::setLastname(std::string lastname) {
	this->lastname = lastname;
	return 0;
}

bool Person::setPerson_id(std::string person_id) {
    if (person_id.length() == 11) {
        for (int i = 0; i < person_id.length(); i++)
            if (person_id[i] < 48 || person_id[i] > 57)
                return 1;

        //konwersja person_id na tablice int na potrzebe funkcji walidacyjnej wzietej z programu z poprzedniego semestru
        int p[11];
        for (int i = 0; i < 11; i++)
            p[i] = int(person_id[i]) - 48;

        //sprawdzamy czy pesel jest poprawny
        if (isPerson_idValid(p)) {
            this->person_id = person_id;
            this->birthdate = convertBirthdate(p);
        } else
            return 1;
    } else
        return 1;

    return 0;
}

bool Person::setSex(bool sex) {
    if (sex == 0 || sex == 1)
        this->sex = sex;
    else
        return 1;
	return 0;
}

bool Person::setAge(unsigned int age) {
	this->age = age;
	return 0;
}

bool Person::setBirthdate(Date birthdate) { 
    this->birthdate = birthdate;
    return 0;
}

//getters
std::string Person::getFirstname() {
    return firstname;
}

std::string Person::getLastname() {
    return lastname;
}

std::string Person::getPerson_id() {
    return person_id;
}

Date Person::getBirthdate() {
    return birthdate;
}

bool Person::getSex() {
    return sex;
}

unsigned int Person::getAge() {
    return age;
}