#include "Student.h"

Student::Student(){}

void Student::addGrades(const short grade) //получить оценку
{
    if(grade>1 && grade <6){
        grades.push_back(grade);
    }
}

std::vector<short> Student::getGrades()
{
    return grades;
}

bool Student::getExellentGrades()
{
    updateExellentGrades();
    return exellentGrades;
}

void Student::updateExellentGrades()
{
    for(auto i : grades){
        if(i != 5){
            exellentGrades = false;
            return;
        }
    }
    exellentGrades = true;
}
