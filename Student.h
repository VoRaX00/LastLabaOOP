#pragma once
#include <vector>

class Student
{
public:
    Student();

    void addGrades(const short grade); //получить оценку
    std::vector<short> getGrades();

    bool getExellentGrades(); //узнаём отличник ли студент
    
private:
    void updateExellentGrades(); //обновляем информацию отличник студент или нет

private:
    std::vector<short>grades;
    bool exellentGrades = true;
};