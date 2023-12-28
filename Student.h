#pragma once
#include <vector>
class Student
{
public:
    Student();

    void addGrades(const short grade); //получить оценку
    std::vector<short> getGrades();
    
private:
    std::vector<short>grades;
};