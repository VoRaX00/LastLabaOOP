#pragma once
#include "Lesson.h"
#include "Parent.h"

class Meeting
{
public:
    Meeting();
    Meeting(std::vector<std::shared_ptr<Lesson>> &_lessons, std::vector<std::shared_ptr<Teacher>> &_teachers, std::vector<std::shared_ptr<Parent>> &_parents);

    void discuss();

private:
    std::shared_ptr<Parent> findParent(std::shared_ptr<Student> student);
    bool isTeacher(std::shared_ptr<Teacher> teacher);

private:
    std::vector<std::shared_ptr<Lesson>> lessons;
    std::vector<std::shared_ptr<Teacher>> teachers;
    std::vector<std::shared_ptr<Parent>> parents;
};