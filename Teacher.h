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

    virtual void giveGrade(std::shared_ptr<Student>& student); //поставить оценку студенту

    void setMood(const Mood _mood);

    Mood getMood();

    void setMaxGrades(unsigned num);

protected:
    void appendCountGrade();

protected:
    Mood mood;
    unsigned countGrade;
    unsigned maxGrades;
};