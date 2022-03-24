#ifndef PERSON_H
#define PERSON_H

#include <string>

//класс, хранящий личность
class Person
{
public:
    Person(); //конструктор по умолчанию
    Person (std::string _last_name, std::string _first_name, std::string _patronymic); //конструктор от "фамилия", "имя", "отчество" (отчества нет - пустая строка)
    Person(const Person&);//конструктор копирования

    void setLastName(const std::string&); //метод, устанавливающий фамилию личности
    void setFirstame(const std::string&); //метод, устанавливающий имя личности
    void setPatronymic(const std::string&); //метод, устанавливающий отчество личности
    const std::string& getLastName() const { return last_name; } //метод возвращающий фамилию личности
    const std::string& getFirstName() const { return first_name; } //метод возвращающий имя личности
    const std::string& getPatronymic() const { return patronymic; } //метод возвращающий отчество личности

private:
    long key; //ключ
    std::string last_name; //содержит фамилию
    std::string first_name; //содержит имя
    std::string patronymic; //содержит отчество
};

#endif // PERSON_H
