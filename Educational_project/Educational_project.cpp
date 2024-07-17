#include <iostream>
#include <string>
#include <limits>
#include "Windows.h"

class Students 
{
    struct Student //��������� ���������
    {
        int age;
        int average;
        std::string name;
    };

    Student* base; //��������� �� ������������ ������
    size_t size;
public:
    // ����������� ������ - ������ ������
    Students(size_t size) : size(size) {
        base = new Student[size]; // �������� ������ ��� ������� ���������
    }

    //������������� ������ - ������� ������
    ~Students()
    {
        delete[] base;
    }

    void input_class();
    void output_class();
    void output_grade();
};

void Students::input_class()
{
    //�������� base � k - ������ ���� ������, ��� ��� ���� �� ����������
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "������� ������ � �������� [" << i + 1 << "] (���, �������, ������� ����(�� 5-� ������� �������): " << std::endl;
        
        // ���������� std::getline ��� ���������� ���� ������
        std::cout << "���: ";
        std::getline(std::cin, base[i].name);
    
        std::cout << "�������: ";
        std::cin >> base[i].age;

        std::cout << "������� ����: ";
        std::cin >> base[i].average;
    
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }
    std::cout << "\n" << std::endl;
}

void Students::output_class()
{
    //����� ���������
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "���: " << base[i].name << std::endl;
        std::cout << "�������: " << base[i].age << std::endl;
        std::cout << "������� ����: " << base[i].average << std::endl;
        std::cout << "\n" << std::endl;
    }
}

void Students::output_grade()
{
    //�������� ������������ ���������
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "�������: " << base[i].name << std::endl;  // ������� ��� ��������
        switch (base[i].average)
        {
        case 1:
            std::cout << "�����" << std::endl;
            break;
        case 2:
            std::cout << "�� �����������������" << std::endl;
            break;
        case 3:
            std::cout << "�����������������" << std::endl;
            break;
        case 4:
            std::cout << "������" << std::endl;
            break;
        case 5:
            std::cout << "�����������" << std::endl;
            break;
        default:
            std::cout << "�� ���������� ��������" << std::endl;
            break;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Students* students = new Students(2);
    
    students->input_class();
    students->output_class();
    students->output_grade();

    delete students;
    std::system("pause");
    return 0;
}
