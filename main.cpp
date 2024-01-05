#include "Lesson.h"
#include "SuperTeacher.h"
#include "Meeting.h"
#include <iostream>
using namespace std;

std::ostream &operator<<(std::ostream &out, Grades grade)
{
    switch (grade)
    {
    case Grades::Five:
        std::cout << 5;
        break;
    case Grades::Four:
        std::cout << 4;
        break;
    case Grades::Three:
        std::cout << 3;
        break;
    case Grades::Two:
        std::cout << 2;
        break;
    case Grades::Empty:
        std::cout << "empty";

    default:
        break;
    }
    return out;
}

int main()
{
    Lesson *l1 = new Lesson();
    vector<shared_ptr<Student>> students = {
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>()};
    l1->setTeacher(make_shared<Teacher>());
    l1->setStudents(students);
    l1->conductLesson();
    for (auto i : students)
    {
        auto arr = i->getGrades();
        for (auto j : arr)
        {
            cout << j << " ";
        }
        if (arr.size() != 0)
            cout << endl;
    }
    return 0;
}