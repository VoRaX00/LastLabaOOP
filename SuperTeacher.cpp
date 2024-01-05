#include "SuperTeacher.h"

void SuperTeacher::giveGrade(std::shared_ptr<Student> &student)
{
    student->addGrades(Grades::Five);
}