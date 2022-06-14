#pragma once
#include <string>
#include "Date.h"

class Person
{
protected:
    std::string firstname = "NONE", lastname = "NONE", person_id = "NONE";
    Date birthdate;
    bool sex=0;
    unsigned int age=0;

    virtual bool isPerson_idValid(int p[11]);
    virtual Date convertBirthdate(int p[11]);

public:
    Person();
    Person(std::string firstname, std::string lastname, bool sex, unsigned int age, std::string person_id);
    void print();

    //setters
    bool setFirstname(std::string firstname);
    bool setLastname(std::string lastname);
    virtual bool setPerson_id(std::string person_id);
    bool setSex(bool sex); // 0 - woman, 1 - man
    bool setAge(unsigned int age);
    bool setBirthdate(Date birthdate);

    //getters
    std::string getFirstname();
    std::string getLastname();
    std::string getPerson_id();
    Date getBirthdate();
    bool getSex();
    unsigned int getAge();
};

