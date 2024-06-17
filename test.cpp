#include <iostream>
#include "Identify.h"
#include "globalFile.h"
#include <fstream>
#include <string>

void LoginIn(std::string fileName, int type)
{
    Identify *person = NULL;
    std::ifstream ifs;
    ifs.open(fileName, std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "None" << std::endl;
        ifs.close();
        return;
    }

    int id = 0;
    std::string name;
    std::string pwd;

    if (type == 1)
    {
        std::cout << "Enter student ID" << std::endl;
        std::cin >> id;
    }
    else if (type == 2)
    {
        std::cout << "Enter teacher ID" << std::endl;
        std::cin >> id;
    }
    std::cout << "Enter name" << std::endl;
    std::cin >> name;
    std::cout << "Enter password" << std::endl;
    std::cin >> pwd;

    if (type == 1)
    {
    }
    else if (type == 2)
    {
    }
    else if (type == 3)
    {
    }
    std::cout << "Login failed" << std::endl;
    system("pause");
    system("cls");
    return;
}

int main()
{
    int select = 0;
    while (true)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "----1. student----" << std::endl;
        std::cout << "----2. teacher----" << std::endl;
        std::cout << "----3. admin  ----" << std::endl;
        std::cout << "----0.exit    ----" << std::endl;
        std::cout << "------------------" << std::endl;

        std::cout << "Select:";
        std::cin >> select;
        switch (select)
        {
        case 1:
            LoginIn(STUDENT_FILE, 1);
            break;
        case 2:
            LoginIn(TEACHER_FILE, 2);
            break;
        case 3:
            LoginIn(ADMIN_FILE, 3);
            break;
        case 0:
            std::cout << "See You" << std::endl;
            system("pause");
            return 0;
            break;
        default:
            std::cout << "Error" << std::endl;
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}