#include "Lesson.h"
#include <time.h>
Lesson::Lesson() {}

void Lesson::conductLesson()
{
    setGradesStudents();
}

void Lesson::setTeacher(std::shared_ptr<Teacher> _teacher)
{
    teacher = _teacher;
}

std::shared_ptr<Teacher> Lesson::getTeacher()
{
    return teacher;
}

void Lesson::setStudents(std::vector<std::shared_ptr<Student>> _students)
{
    students = _students;
}

std::vector<std::shared_ptr<Student>> Lesson::getStudents()
{
    return students;
}

void Lesson::setGradesStudents()
{
    short countStudent = rand() % students.size() + 1;
    short numStudent = rand() % students.size();
    for (int i = 0; i < students.size(); i++)
    {
        if (i < countStudent)
            teacher->giveGrade(students[(numStudent + i) % students.size()]);
        else
            students[(numStudent + i) % students.size()]->addGrades(Grades::Empty);
    }
}
