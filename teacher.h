#pragma once
#include <iostream>
#include <string>
#include "Identify.h"

class Teacher:public Identify
{
public:
    Teacher();
    Teacher(int empId,std::string name,std::string pwd);
    virtual void operMenu() = 0;
    void showAllOrder();
    void validOrder();

    int m_EmpId;
};