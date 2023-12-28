#pragma once
#include "Teacher.h"

class SuperTeacher : public Teacher
{
public:
    void giveGrade(std::shared_ptr<Student>& student); //поставить оценку студенту
};