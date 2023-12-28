#include "Teacher.h"
#include<iostream>
Teacher::Teacher()
{
    srand(time(0));
    mood = static_cast<Mood>(rand() % 3);
}

void Teacher::giveGrade(std::shared_ptr<Student>& student) //поставить оценку студенту
{
    srand(time(0));
    short grade;
    if(student->getExellentGrades() && mood == Mood::Good){
        grade = 5;
    }
    else if(student->getExellentGrades() &&(mood == Mood::Normal || mood == Mood::Bad)){
        short num = rand()%3 == 0;
        grade = (num == 0) ? 3 : (num == 1 ? 4 : 5);
    }
    else if(!student->getExellentGrades() && mood == Mood::Good){
        if(rand() % 2 == 0){
            grade = 4;
        }
        else{
            grade = 5;
        }
    }
    else if(!student->getExellentGrades() && mood == Mood::Normal){
        if(rand() % 2 == 0){
            grade = 3;
        }
        else{
            grade = 4;
        }
    }
    else{
        if(rand() % 2 == 0){
            grade = 2;
        }
        else{
            grade = 3;
        }
    }

    student->addGrades(grade);
}

void Teacher::setMood(const Mood _mood)
{
    mood = _mood;
}

Mood Teacher::getMood()
{
    return mood;
}
