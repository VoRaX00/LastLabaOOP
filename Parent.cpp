#include "Parent.h"
#include <iostream>
#include <algorithm>
#include <time.h>
Parent::Parent()
{
    srand(time(0));
    mood = (Mood)(rand() % 3);
}

Parent::Parent(std::vector<std::shared_ptr<Student>> _children) : children(_children)
{
    srand(time(0));
    mood = (Mood)(rand() % 3);
}

void Parent::tellAboutEveryChildren()
{
    for (int i = 0; i < children.size(); i++)
    {
        std::cout << "Это ребёнок номер: " << i << std::endl;
        tellAboutChild(children[i]);
    }
}

void Parent::tellAboutChild()
{
    if (children.empty())
    {
        std::cout << "Детей нет\n";
        return;
    }

    short numChild = rand() % children.size();
    tellAboutChild(children[numChild]);
}

void Parent::tellAboutChild(std::shared_ptr<Student> child)
{
    if (!itMyChild(child))
    {
        std::cout << "Error: это чужой ребёнок\n";
        return;
    }

    if (mood == Mood::Good)
    {
        if (child->getExcellentGrades())
            std::cout << "Этот ребёнок красавчик, он отличник!!!\n";
        else
            std::cout << "Этот ребёнок красавчик, но не отличник\n";
    }
    else if (mood == Mood::Normal)
    {
        if (child->getExcellentGrades())
            std::cout << "Этот ребёнок отличник, он молодец!\n";
        else
            std::cout << "Этот ребёнок не отличник\n";
    }
    else
    {
        if (child->getExcellentGrades())
            std::cout << "Этот ребёнок заучка\n";
        else
            std::cout << "Этот ребёнок дурак, т.к. не отличник\n";
    }
}

void Parent::tellAboutAllChildren()
{
    short countExcStudents = getCountExcellentStudents();
    if (countExcStudents > children.size() / 2)
    {
        switch (mood)
        {
        case Mood::Good:
            std::cout << "Мои дети самые крутые большинство из них отличники!\n";
            break;
        case Mood::Normal:
            std::cout << "Мои дети хорошие большинство из них отличники!\n";
            break;
        case Mood::Bad:
            std::cout << "Большинство детей отличники!\n";
            break;

        default:
            break;
        }
    }
    else
    {
        switch (mood)
        {
        case Mood::Good:
            std::cout << "Мои дети самые крутые, но им нужно немного постараться!\n";
            break;
        case Mood::Normal:
            std::cout << "Мои дети хорошие, но им нужно немного постараться!\n";
            break;
        case Mood::Bad:
            std::cout << "Моим детям нужно пахать!\n";
            break;

        default:
            break;
        }
    }
}

void Parent::addChild(std::shared_ptr<Student> child)
{
    children.push_back(child);
}

bool Parent::itMyChild(std::shared_ptr<Student> child)
{
    return std::find(children.begin(), children.end(), child) != children.end();
}

short Parent::getCountExcellentStudents()
{
    short count = 0;
    for (auto i : children)
    {
        if (i->getExcellentGrades())
            count++;
    }
    return count;
}
