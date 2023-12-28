#pragma once
#include <vector>
class Student
{
public:
    Student();

    void addGrades(short grade);
    std::vector<short> getGrades();
    
private:
    std::vector<short>grades;
};