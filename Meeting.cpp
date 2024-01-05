#include "Meeting.h"
#include <iostream>
#include <algorithm>
Meeting::Meeting() {}

Meeting::Meeting(std::vector<std::shared_ptr<Lesson>> &_lessons, std::vector<std::shared_ptr<Teacher>> &_teachers, std::vector<std::shared_ptr<Parent>> &_parents) : lessons(_lessons), teachers(_teachers), parents(_parents) {}

void Meeting::discuss()
{
    std::vector<std::shared_ptr<Student>> notMeeting;
    for (int i = 0; i < lessons.size(); i++)
    {
        std::cout << "Занятие " << i + 1 << ":\n";
        if (isTeacher(lessons[i]->getTeacher()))
        {
            for (auto j : lessons[i]->getStudents())
            {
                if(j->getGrades()[i] != Grades::Empty){
                    std::shared_ptr<Parent> parent = findParent(j);

                    if (parent != nullptr)
                        parent->tellAboutChild(j);
                    else{
                        if(std::find(notMeeting.begin(), notMeeting.end(), j) == notMeeting.end())
                            notMeeting.push_back(j);
                    }
                }
                else{
                    std::cout << "Не получил оценку за урок\n";
                }
            }
        }
        else
        {
            std::cout << "Преподавателя нет на собрании\n";
        }
    }

    std::cout << "Список отсутствующих:\n";
    for (auto i : notMeeting)
    {
        std::cout << *i << std::endl;
    }
}

std::shared_ptr<Parent> Meeting::findParent(std::shared_ptr<Student> student)
{
    for (auto i : parents)
    {
        if (i->itMyChild(student))
        {
            return i;
        }
    }
    return nullptr;
}

bool Meeting::isTeacher(std::shared_ptr<Teacher> teacher)
{
    for (auto i : teachers)
    {
        if (i == teacher)
            return true;
    }
    return false;
}
