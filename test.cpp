#include <iostream>
#include "Identify.h"
#include "globalFile.h"
#include <fstream>
#include <string>
#include "student.h"
#include "teacher.h"
#include "manager.h"

void managerMenu(Identify *&manager)
{
    while (true)
    {
        manager->operMenu();
        Manager *man = (Manager *)manager;
        int select = 0;
        std::cin >> select;
        if (select == 1)
        {
            std::cout << "Add Account" << std::endl;
            man->addPerson();
        }
        else if (select == 2)
        {
            std::cout << "SHow Account" << std::endl;
            man->showPerson();
        }
        else if (select == 3)
        {
            std::cout << "Show Computer" << std::endl;
            man->showComputer();
        }
        else if (select == 4)
        {
            std::cout << "Clear reservation" << std::endl;
            man->clearFile();
        }
        else if (select == 0)
        {
            delete manager;
            std::cout << "Log off!" << std::endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

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
        int fId;
        std::string fName;
        std::string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                std::cout << "Log in!" << std::endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);

                return;
            }
        }
    }
    else if (type == 2)
    {
        int fId;
        std::string fName;
        std::string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                std::cout << "Log in!" << std::endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);

                return;
            }
        }
    }
    else if (type == 3)
    {
        std::string fName;
        std::string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd)
            {
                std::cout << "Log in!" << std::endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);
                managerMenu(person);

                return;
            }
        }
    }
    std::cout << "Login failed!" << std::endl;
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