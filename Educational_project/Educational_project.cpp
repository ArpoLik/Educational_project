#include <iostream>
#include <string>
#include <limits>
#include "Windows.h"

class Students 
{
    struct Student //приватная структура
    {
        int age;
        int average;
        std::string name;
    };

    Student* base; //указатель на динамический массив
    size_t size;
public:
    // Конструктор класса - создаёт массив
    Students(size_t size) : size(size) {
        base = new Student[size]; // Выделяем память для массива студентов
    }

    //деконструктор класса - удаляет массив
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
    //параметр base и k - теперь поля класса, так что тело не изменилось
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "Введите данные о студенте [" << i + 1 << "] (ФИО, возраст, Средний балл(по 5-и бальной системе): " << std::endl;
        
        // Используем std::getline для считывания всей строки
        std::cout << "ФИО: ";
        std::getline(std::cin, base[i].name);
    
        std::cout << "Возраст: ";
        std::cin >> base[i].age;

        std::cout << "Средний балл: ";
        std::cin >> base[i].average;
    
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }
    std::cout << "\n" << std::endl;
}

void Students::output_class()
{
    //Вывод студентов
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "ФИО: " << base[i].name << std::endl;
        std::cout << "Возраст: " << base[i].age << std::endl;
        std::cout << "Средний балл: " << base[i].average << std::endl;
        std::cout << "\n" << std::endl;
    }
}

void Students::output_grade()
{
    //проверка успеваемости студентов
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "Студент: " << base[i].name << std::endl;  // Выводим имя студента
        switch (base[i].average)
        {
        case 1:
            std::cout << "Плохо" << std::endl;
            break;
        case 2:
            std::cout << "Не удовлетворительно" << std::endl;
            break;
        case 3:
            std::cout << "Удовлетворительно" << std::endl;
            break;
        case 4:
            std::cout << "Хорошо" << std::endl;
            break;
        case 5:
            std::cout << "Превосходно" << std::endl;
            break;
        default:
            std::cout << "Не корректное значение" << std::endl;
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
