#include <iostream>
#include <string>
#include <vector>
#include "Windows.h"

class Students
{
    struct Student //приватная структура
    {
        std::string name;
        int age;
        int average;
    };

    int select;
    std::vector<Student> student;

public:
    // Конструктор класса - создаёт массив
    Students()
    {
        student.push_back({"Петров Алексей Иванович", 18, 3});
        student.push_back({ "Трофинов Сергей Юрьевич",20, 4 });
    }

    //деконструктор класса - удаляет массив
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
    std::string name = "Анкета";

    std::cout << "Введите ФИО студента: ";
    std::getline(std::cin, name);// Используйте std::getline для ввода ФИО



    std::cout << "Укажите возраст студента: ";
    while (!(std::cin >> age)) { // Проверка корректного ввода возраста
        std::cout << "Некорректный ввод возраста. Попробуйте снова: ";
        std::cin.clear(); // Очищаем флаги ошибок
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // Очищаем буфер ввода
    }

    std::cout << "Укажите средний балл: ";
    while (!(std::cin >> average)) { // Проверка корректного ввода среднего балла
        std::cout << "Некорректный ввод среднего балла. Попробуйте снова: ";
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
        std::cout << "Что хотите изменить?" << std::endl;
        std::cout << "1. ФИО" << std::endl;
        std::cout << "2. Возраст" << std::endl;
        std::cout << "3. Средний балл" << std::endl;

        std::cout << "Выберите операцию: ";
        std::cin >> choice;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        if (choice < 1 || choice > 3)
        {
            std::cout << "Некорректный номер операции. Попробуйте снова" << std::endl;
        }
    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        std::cout << "Укажите новые данные: ";
        std::getline(std::cin, student[person].name);
        break;
    case 2:
        std::cout << "Укажите новые данные: ";
        std::cin >> student[person].age;
        break;
    case 3:
        std::cout << "Укажите новые данные: ";
        std::cin >> student[person].average;
        break;
    default:
        break;
    }

}

void Students::showInfo()
{
    int choice = selectStudent();

    std::cout << "ФИО: " << student[choice].name << std::endl;
    std::cout << "Возраст: " << student[choice].age<< std::endl;
    std::cout << "Средний балл: " << student[choice].average << std::endl;
    std::cout << "Успеваемость: " << showPerfomance(choice) << std::endl;
    std::cout << std::endl;

}

void Students::listStudent()
{
    std::cout << "Список студентов: " << std::endl;
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
        std::cout << "Выберите студента: ";
        std::cin >> choice;
        
        if (choice < 1 || choice > student.size())
        {
            std::cout << "Некорректный номер студента. Попробуйте снова" << std::endl;
        }
    } while (choice < 1 || choice > student.size());
 
    return choice - 1;
}

std::string Students::showPerfomance(int person)
{
    switch (student[person].average)
    {
    case 1:
        return "Плохая";
        break;
    case 2:
        return "Не удовлетворительная";
        break;
    case 3:
        return "Удовлетворительная";
        break;
    case 4:
        return "Хорошая";
        break;
    case 5:
        return "Превосходная";
        break;
    default:
        return "Неверное значение";
        break;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Students* person = new Students();
    int choice = 0;

    std::cout << "1. Список студентов" << std::endl;
    std::cout << "2. Добавить студента" << std::endl;
    std::cout << "3. Информация о студенте" << std::endl;
    std::cout << "4. Изменить информацию студента" << std::endl;
    
    std::cout << "Выберите операцию: ";
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
        std::cout << "Неверное значение";
        break;
    }

    std::system("pause");
    return 0;
}
