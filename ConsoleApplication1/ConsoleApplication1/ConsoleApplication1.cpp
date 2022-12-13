


// подключение библиотек
#include <iostream>
#include<fstream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>


int main()
{
    setlocale(LC_ALL, "ru"); // Ввод неоюходимых параметров
    int T = 0;
    int M = 0;
    std::cout << "Введите периодичность заполнения T = ";
    std::cin >> T;
    std::cout << std::endl;
    std::cout << "Введите максимальный объем записываеых данных M = ";
    std::cin >> M;
    std::cout << std::endl;
}

