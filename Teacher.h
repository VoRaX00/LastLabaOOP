#pragma once
#include "Student.h"
#include <memory>
enum class Mood{
    Bad,
    Normal,
    Good
};

class Teacher
{
public:
    Teacher();

    void giveGrade(std::shared_ptr<Student>& student); //поставить оценку студенту

    void setMood(const Mood _mood);
    Mood getMood();

private:
    Mood mood;
};