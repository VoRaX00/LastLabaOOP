#pragma once
#include <vector>
#include <string>

enum class Grades
{
    Five,
    Four,
    Three,
    Two,
    Empty
};

class Student
{
public:
    Student();
    Student(std::string _surname, std::string _name, std::string _patronymic);

    void addGrades(const Grades grade); // получить оценку
    std::vector<Grades> getGrades();

    bool getExcellentGrades(); // узнаём отличник ли студент

    friend std::ostream &operator<<(std::ostream &out, Student student);

private:
    void updateExcellentGrades(); // обновляем информацию отличник студент или нет

private:
    std::string surname;
    std::string name;
    std::string patronymic;

    std::vector<Grades> grades;
    bool excellentGrades = true;
};