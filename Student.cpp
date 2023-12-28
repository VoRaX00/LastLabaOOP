#include "Student.h"

Student::Student(){}

void Student::addGrades(const short grade) //получить оценку
{
    if(grade>0 && grade <6){
        grades.push_back(grade);
    }
}

std::vector<short> Student::getGrades()
{
    return grades;
}
