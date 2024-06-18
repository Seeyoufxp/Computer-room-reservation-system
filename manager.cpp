#include "manager.h"
#include <string>

Manager::Manager()
{
    
}

Manager::Manager(std::string name, std::string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;
}

void Manager::operMenu()
{
    std::cout << "hello," << this->m_Name << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "-------1.Add Account---------" << std::endl;
    std::cout << "-------2.Show Account--------" << std::endl;
    std::cout << "-------3.Show Computer-------" << std::endl;
    std::cout << "-------4.Clear reservation---" << std::endl;
    std::cout << "-------0.Log off-------------" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout<<std::endl;
}   

void Manager::addPerson()
{
    
}

void Manager::showPerson()
{

}

void Manager::showComputer()
{

}

void Manager::clearFile()
{
    
}