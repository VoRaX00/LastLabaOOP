#pragma once
#include "Teacher.h"

class Parent
{
public:
    Parent();
    Parent(std::vector<std::shared_ptr<Student>>_children);

    void tellAboutEveryChildren(); //рассказать о каждом своём ребёнке
    void tellAboutChild(); //рассказать об одном случайном ребёнке
    void tellAboutChild(std::shared_ptr<Student>child); //рассказать о конкретном ребёнке
    void tellAboutAllChildren();  //рассказать в общем обо всех детях

    void addChild(std::shared_ptr<Student>child);

private:
    short getCountExcellentStudents();

private:
    Mood mood;
    std::vector<std::shared_ptr<Student>>children;
};