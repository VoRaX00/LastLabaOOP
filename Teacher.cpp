#include "Teacher.h"
#include <time.h>
Teacher::Teacher()
{
    srand(time(0));
    mood = (Mood)(rand() % 3);

    setMaxGrades(5);
}

void Teacher::giveGrade(std::shared_ptr<Student> &student) // поставить оценку студенту
{
    Grades grade;
    if (student->getExcellentGrades() && mood == Mood::Good)
    {
        grade = Grades::Five;
    }
    else if (student->getExcellentGrades() && (mood == Mood::Normal || mood == Mood::Bad))
    {
        short num = rand() % 3 == 0;
        grade = (num == 0) ? Grades::Three : (num == 1 ? Grades::Four : Grades::Five);
    }
    else if (!student->getExcellentGrades() && mood == Mood::Good)
    {
        if (rand() % 2 == 0)
        {
            grade = Grades::Four;
        }
        else
        {
            grade = Grades::Five;
        }
    }
    else if (!student->getExcellentGrades() && mood == Mood::Normal)
    {
        if (rand() % 2 == 0)
        {
            grade = Grades::Three;
        }
        else
        {
            grade = Grades::Four;
        }
    }
    else
    {
        if (rand() % 2 == 0)
        {
            grade = Grades::Two;
        }
        else
        {
            grade = Grades::Three;
        }
    }

    student->addGrades(grade);
    appendCountGrade();
    if (countGrade == maxGrades)
    {
        countGrade = 0;
        setMood((Mood)(rand() % 3));
    }
}

void Teacher::setMood(const Mood _mood)
{
    mood = _mood;
}

Mood Teacher::getMood()
{
    return mood;
}

void Teacher::setMaxGrades(unsigned num)
{
    maxGrades = num;
}

void Teacher::appendCountGrade()
{
    countGrade++;
}
