#pragma once
#include "Parent.h"
class Grandmother : public Parent
{
public:
    Grandmother();
    
    void tellAboutChild(std::shared_ptr<Student> child) override;
    void tellAboutAllChildren() override;
private:
};