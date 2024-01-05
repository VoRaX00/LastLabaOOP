#include "Student.h"
#include <iostream>

Student::Student() {}

Student::Student(std::string _surname, std::string _name, std::string _patronymic) : surname(_surname), name(_name), patronymic(_patronymic) {}

void Student::addGrades(const Grades grade) // получить оценку
{
    grades.push_back(grade);
}

std::vector<Grades> Student::getGrades()
{
    return grades;
}

bool Student::getExcellentGrades()
{
    updateExcellentGrades();
    return excellentGrades;
}

void Student::updateExcellentGrades()
{
    for (auto i : grades)
    {
        if (i != Grades::Five && i != Grades::Empty)
        {
            excellentGrades = false;
            return;
        }
    }
    excellentGrades = true;
}

std::ostream &operator<<(std::ostream &out, Student student)
{
    out << student.surname << " " << student.name << " " << student.patronymic;
    return out;
}
