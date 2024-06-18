#pragma once
#include "Identify.h"
#include <iostream>

class Manager:public Identify
{
public:
    Manager();
    Manager(std::string name,std::string pwd);
    virtual void operMenu();
    void addPerson();
    void showPerson();
    void showComputer();
    void clearFile();
};