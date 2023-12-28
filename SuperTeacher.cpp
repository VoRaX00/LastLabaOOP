#include "SuperTeacher.h"

void SuperTeacher::giveGrade(std::shared_ptr<Student> &student)
{
    student->addGrades(5);
}