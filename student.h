#pragma once
#include "Identify.h"
#include <iostream>
#include <string>


class Student:public Identify
{
public:
    Student();
    Student(int id, std::string name, std::string pwd);
    virtual void operMenu();
    void applyOrder();
    void showOrder();
    void showAllOrder();
    void cancelOrder();

    int m_Id;
};