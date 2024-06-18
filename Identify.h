#pragma once
#include <iostream>
#include <string>

class Identify
{
public:
    virtual void operMenu() = 0;
    std::string m_Name;
    std::string m_Pwd;
};