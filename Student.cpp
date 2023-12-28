#include "Student.h"

Student::Student(){}

void Student::addGrades(short grade)
{
    if(grade>0 && grade <6){
        grades.push_back(grade);
    }
}

std::vector<short> Student::getGrades()
{
    return grades;
}
