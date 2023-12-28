#pragma once
#include "Student.h"

enum class Mood{
    Bad,
    Normal,
    Good
};

class Teacher
{
public:
    Teacher();

    void giveGrade(Student& student); //поставить оценку студенту

    void setMood(const Mood _mood);
    Mood getMood();

private:
    Mood mood;
};