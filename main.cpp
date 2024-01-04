#include "Lesson.h"
#include "SuperTeacher.h"
#include <iostream>
using namespace std;

int main(){
    Lesson* l1 = new Lesson();
    vector<shared_ptr<Student>>students = {
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>(),
        make_shared<Student>()
    };
    l1->setTeacher(make_shared<SuperTeacher>());
    l1->setStudents(students);
    l1->conductLesson();
    for(auto i : students){
        auto arr = i->getGrades();
        for(auto j : arr){
            cout << j << " ";
        }
        if(arr.size() != 0)
            cout << endl;
    }
}