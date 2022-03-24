#include "Person.h"

Person::Person() {}

Person::Person (std::string _last_name, std::string _first_name, std::string _patronymic)
{
    //устанавливаем член-данные аргументами конструкора
    last_name = _last_name;
    first_name = _first_name;
    patronymic = _patronymic;
}

 Person::Person(const Person& p)
 {
     //устанавливаем член-данные данными существующего экземпляра класса
     first_name = p.first_name;
     last_name = p.last_name;
     patronymic = p.patronymic;
     key = p.key;
 }

void Person::setFirstame(const std::string & _first_name)
{
    first_name = _first_name; //устанавливаем имя
}

void Person::setLastName(const std::string & _last_name)
{
    last_name = _last_name; //устанавливаем фамилию
}

void Person::setPatronymic(const std::string & _patronymic)
{
    patronymic = _patronymic; //устанавливаем отчество
}

