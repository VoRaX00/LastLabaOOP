#pragma once
#include "Teacher.h"

class SuperTeacher : public Teacher
{
public:
    void giveGrade(std::shared_ptr<Student>& student) override; //поставить оценку студенту
};