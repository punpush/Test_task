


// подключение библиотек
#include <iostream>
#include<fstream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>


struct Message
{
    Message(size_t file_size, int* data_);

    size_t file_size;
    int* data_;
};


void read() {
    int T = 0;
    int M = 0;
    std::cout << "Введите периодичность заполнения T = "; // Ввод неоюходимых параметров
    std::cin >> T;
    std::cout << std::endl;
    std::cout << "Введите максимальный объем записываеых данных M = ";
    std::cin >> M;
    std::cout << std::endl;
}

void create() {
    ;
}


int main()
{
    setlocale(LC_ALL, "ru"); // Поддержка русского языка
    
    std::queue<Message> message_queue;

    std::thread th1([&]() {read(); });
    std::thread th2([&]() {create(); });
    th1.join();
    th2.join();
}

