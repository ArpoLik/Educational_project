#include <iostream>
#include <string>
#include <vector>
#include "Windows.h"

class Students
{
    struct Student //��������� ���������
    {
        std::string name;
        int age;
        int average;
    };

    int select;
    std::vector<Student> student;

public:
    // ����������� ������ - ������ ������
    Students()
    {
        student.push_back({"������ ������� ��������", 18, 3});
        student.push_back({ "�������� ������ �������",20, 4 });
    }

    //������������� ������ - ������� ������
    ~Students()
    {
    }

    void showInfo();
    void addStudent();
    void listStudent();
    void changeData();
    int selectStudent();
    std::string showPerfomance(int person);
};

void Students::addStudent()
{
    int age, average;
    std::string name = "������";

    std::cout << "������� ��� ��������: ";
    std::getline(std::cin, name);// ����������� std::getline ��� ����� ���



    std::cout << "������� ������� ��������: ";
    while (!(std::cin >> age)) { // �������� ����������� ����� ��������
        std::cout << "������������ ���� ��������. ���������� �����: ";
        std::cin.clear(); // ������� ����� ������
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // ������� ����� �����
    }

    std::cout << "������� ������� ����: ";
    while (!(std::cin >> average)) { // �������� ����������� ����� �������� �����
        std::cout << "������������ ���� �������� �����. ���������� �����: ";
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }

    student.push_back({ name, age, average });
}

void Students::changeData()
{
    int person = selectStudent();
    int choice;
    do
    {
        std::cout << "��� ������ ��������?" << std::endl;
        std::cout << "1. ���" << std::endl;
        std::cout << "2. �������" << std::endl;
        std::cout << "3. ������� ����" << std::endl;

        std::cout << "�������� ��������: ";
        std::cin >> choice;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        if (choice < 1 || choice > 3)
        {
            std::cout << "������������ ����� ��������. ���������� �����" << std::endl;
        }
    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        std::cout << "������� ����� ������: ";
        std::getline(std::cin, student[person].name);
        break;
    case 2:
        std::cout << "������� ����� ������: ";
        std::cin >> student[person].age;
        break;
    case 3:
        std::cout << "������� ����� ������: ";
        std::cin >> student[person].average;
        break;
    default:
        break;
    }

}

void Students::showInfo()
{
    int choice = selectStudent();

    std::cout << "���: " << student[choice].name << std::endl;
    std::cout << "�������: " << student[choice].age<< std::endl;
    std::cout << "������� ����: " << student[choice].average << std::endl;
    std::cout << "������������: " << showPerfomance(choice) << std::endl;
    std::cout << std::endl;

}

void Students::listStudent()
{
    std::cout << "������ ���������: " << std::endl;
    for (int i = 0; i < student.size(); ++i)
    {
        std::cout << i + 1 << ". " << student[i].name << std::endl;
    }
    std::cout << std::endl;
}

int Students::selectStudent()
{
    int choice;

    listStudent();

    do 
    {
        std::cout << "�������� ��������: ";
        std::cin >> choice;
        
        if (choice < 1 || choice > student.size())
        {
            std::cout << "������������ ����� ��������. ���������� �����" << std::endl;
        }
    } while (choice < 1 || choice > student.size());
 
    return choice - 1;
}

std::string Students::showPerfomance(int person)
{
    switch (student[person].average)
    {
    case 1:
        return "������";
        break;
    case 2:
        return "�� ������������������";
        break;
    case 3:
        return "������������������";
        break;
    case 4:
        return "�������";
        break;
    case 5:
        return "������������";
        break;
    default:
        return "�������� ��������";
        break;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Students* person = new Students();
    int choice = 0;

    std::cout << "1. ������ ���������" << std::endl;
    std::cout << "2. �������� ��������" << std::endl;
    std::cout << "3. ���������� � ��������" << std::endl;
    std::cout << "4. �������� ���������� ��������" << std::endl;
    
    std::cout << "�������� ��������: ";
    std::cin >> choice;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

    switch (choice)
    {
    case 1:
        person->listStudent();
        break;
    case 2:
        person->addStudent();
        person->showInfo();
        break;
    case 3:
        person->showInfo();
        break;
    case 4:
        person->changeData();
        person->showInfo();
        break;
    default:
        std::cout << "�������� ��������";
        break;
    }

    std::system("pause");
    return 0;
}
