#include "Teacher.h"
#include<iostream>
Teacher::Teacher()
{
}

void Teacher::giveGrade(Student &student) //поставить оценку студенту
{
    srand(time(0));
    short grade = rand()%5 + 1;
    student.addGrades(grade);
}
