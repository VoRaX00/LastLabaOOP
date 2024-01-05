#include "Grandmother.h"
#include <time.h>
#include <iostream>
Grandmother::Grandmother()
{
    srand(time(0));
}

void Grandmother::tellAboutChild(std::shared_ptr<Student> child)
{
    std::cout << "Мой внук самый лучший!!! Он лучше всех\n";
}

void Grandmother::tellAboutAllChildren()
{
    std::cout << "Мои внуки лучше всех!!!\n";
}
