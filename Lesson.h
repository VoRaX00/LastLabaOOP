#pragma once
#include "Teacher.h"
#include "Student.h"
#include <memory>
class Lesson
{
public:
    Lesson();

    void conductLesson();

    void setTeacher(std::shared_ptr<Teacher> _teacher);
    std::shared_ptr<Teacher> getTeacher();

    void setStudents(std::vector<std::shared_ptr<Student>> _students);
    std::vector<std::shared_ptr<Student>> getStudents();

private:
    void setGradesStudents();

private:
    std::shared_ptr<Teacher> teacher;
    std::vector<std::shared_ptr<Student>> students;
};