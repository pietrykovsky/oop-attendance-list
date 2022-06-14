#include "PersonFactory.h"
#include "Spanish.h"
#include "Portuguese.h"
#include "functions.h"
#include <iostream>
#include "Date.h"

PersonFactory::PersonFactory() {}

Person PersonFactory::getPerson(std::string nationality) {
	nationality = normalize(nationality);
	if (nationality == "spanish")
		return Spanish();
	else if (nationality == "portuguese")
		return Portuguese();
	else
		return Person();
}

Person PersonFactory::getPersonFromUser(std::string nationality) {
	nationality = normalize(nationality);
    Person *person;
    std::string firstname, lastname, person_id;
    bool sex;
    unsigned int age;
    Date birthdate;
    std::cout << "Enter your firstname: ";
    std::cin >> firstname;
    std::cout << "Enter your lastname: ";
    std::cin >> lastname;
    std::cout << "Enter your sex (0 - woman, 1 - man): ";
    std::cin >> sex;
    std::cout << "Enter your age: ";
    std::cin >> age;

    if (nationality == "spanish")
        person = new Spanish();
    else if (nationality == "portuguese")
        person = new Portuguese();
    else
        person = new Person();

    person->setFirstname(firstname);
    person->setLastname(lastname);
    person->setAge(age);
    person->setSex(sex);

    do {
        std::cout << "Enter your person id: ";
        std::cin >> person_id;
    } while (person->setPerson_id(person_id));

    if (nationality == "spanish" || nationality == "portuguese") {
        unsigned int day, month, year;
        do {
            std::cout << "Enter birhtdate (DD MM YYYY): ";
            std::cin >> day >> month >> year;
        } while (birthdate.setDate(day, month, year));
        person->setBirthdate(birthdate);
    }

    return *person;
}
