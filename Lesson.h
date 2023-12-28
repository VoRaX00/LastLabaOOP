#pragma once
#include "Teacher.h"
#include "Student.h"
#include <memory>
class Lesson{
public:
    Lesson();

    void conductLesson();

    void setTeacher(std::shared_ptr<Teacher>_teacher);
    void setStudents(std::vector<std::shared_ptr<Student>>_students);

private:
    void setGradesStudents();

private:
    std::shared_ptr<Teacher> teacher;
    std::vector<std::shared_ptr<Student>> students;
};