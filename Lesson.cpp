#include "Lesson.h"
#include <iostream>
Lesson::Lesson()
{
    srand(time(0));
}

void Lesson::conductLesson()
{
    setGradesStudents();
}

void Lesson::setTeacher(std::shared_ptr<Teacher> _teacher)
{
    teacher = _teacher;
}

void Lesson::setStudents(std::vector<std::shared_ptr<Student>> _students)
{
    students = _students;
}

void Lesson::setGradesStudents()
{
    srand(time(0));
    short countStudent = rand() % students.size() + 1;
    for(int i=0; i < countStudent; i++){
        short numStudent = rand() % students.size() + 1;
        teacher->giveGrade(students[numStudent]);
    }
}
