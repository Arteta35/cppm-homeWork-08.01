
#include <iostream>
#include <string>
#include <Windows.h>

class Proverka : public std::exception
{
public:
    
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }

};


int function(std::string str, int forbidden_length)
{
    if (forbidden_length == str.length()) throw Proverka();

    return str.length();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int bad_length = 0;
    std::string str;

    std::cout << "Введите запретную длину: ";
    std::cin >> bad_length;

    try {
        do
        {
            std::cout << "Введите слово: ";
            std::cin >> str;
            function(str, bad_length);
            std::cout << "Длина слова: " << str << " равна " << function(str, bad_length) << std::endl;

        } while (true);

    }
    catch (const Proverka& ex) { std::cout << ex.what() << std::endl; }
    catch (...) { std::cout << "Неизвестная ошибка!" << std::endl; }
    
    
    
}

