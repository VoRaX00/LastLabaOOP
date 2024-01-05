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
    srand(time(0));
    vector<shared_ptr<Student>> students = {
        make_shared<Student>("Кержаков" , "Никита", "Алексеевич"),
        make_shared<Student>("Лосевский" , "Иван", "Захарович"),
        make_shared<Student>("Млакир" , "Глеб", "Константинович"),
        make_shared<Student>("Орлов" , "Артём", "Олегович"),
        make_shared<Student>("Михайлов" , "Константин", "Николаевич"),
        make_shared<Student>("Родохлеб" , "Владислав", "Андреевич"),
        make_shared<Student>("Варавко" , "Петр", "Михайлович")
    };

    vector<shared_ptr<Parent>> parents = {
        make_shared<Parent>(),
        make_shared<Parent>(),
        make_shared<Parent>()
    };

    parents[0]->addChild(students[0]);
    parents[0]->addChild(students[1]);
    parents[1]->addChild(students[2]);
    parents[1]->addChild(students[3]);
    parents[2]->addChild(students[4]);
    parents[2]->addChild(students[5]);


    vector<shared_ptr<Teacher>> teachers = {
        make_shared<Teacher>(),
        make_shared<Teacher>(),
        make_shared<Teacher>()
    };

    vector<shared_ptr<Lesson>> lessons = {
        make_shared<Lesson>(),
        make_shared<Lesson>(),
        make_shared<Lesson>()
    };

    lessons[0]->setStudents(students);
    lessons[1]->setStudents(students);
    lessons[2]->setStudents(students);

    lessons[0]->setTeacher(teachers[0]);
    lessons[1]->setTeacher(teachers[1]);
    lessons[2]->setTeacher(teachers[2]);

    lessons[0]->conductLesson();
    lessons[1]->conductLesson();
    lessons[2]->conductLesson();

    shared_ptr<Meeting>meeting = make_shared<Meeting>(lessons, teachers, parents);

    meeting->discuss();
    return 0;
}