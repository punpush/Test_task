


// подключение библиотек и классов
#include <iostream>
#include<fstream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<chrono>
#include "Buffer.h"
#include "MessageQueue.h"
#include "Counter.h"


// Функция рид, обеспечивающая работу 1 потока
void read() {

    // Выделение памяти буффером, как сделать лучше?

    Buffer<std::uint64_t> buffer(32000000);

    // Ввод необходимых параметров
    int T = 0;
    size_t M = 0;
    std::cout << "Введите периодичность заполнения T в секундах = ";
    std::cin >> T;
    std::cout << std::endl;
    std::cout << "Введите максимальный объем записываеых данных M в МБ = ";
    std::cin >> M;
    std::cout << std::endl;
   
    MessageQueue<std::uint64_t> queue_(256,buffer); // создание очереди месседжей, с которой будут работать потоки
    
    Counter<std::uint64_t> counter(T, M, buffer, queue_);

    counter.fill_in();
    
    buffer.clear();
}

// Функция креэйт, обеспечивающая работу 2 потока 
void create() {
   // создание файла для записи ;

}


int main()
{
    setlocale(LC_ALL, "ru"); // Поддержка русского языка

    
     


    std::thread th1([&]() {read(); });
    std::thread th2([&]() {create(); });
    th1.join();
    th2.join();
}

