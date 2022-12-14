


// подключение библиотек и классов
#include <iostream>
#include<fstream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<chrono>
#include "Buffer.h"



// Класс сообщений, содержащий размер и указатель на данные 
struct Message
{
    Message(size_t file_size, int* data_):file_size(file_size), data_(new int[file_size]) {};

    ~Message() {
        delete [] data_;
    }

    size_t file_size;
    int* data_;
};





// Функция рид, обеспечивающая работу 1 потока
void read() {

    // Выделение памяти буффером, как сделать лучше?

    Buffer<std::uint64_t> buffer(32000000);


    // Ввод необходимых параметров
    int T = 0;
    size_t M = 0;
    std::cout << "Введите периодичность заполнения T = "; 
    std::cin >> T;
    std::cout << std::endl;
    std::cout << "Введите максимальный объем записываеых данных M = ";
    std::cin >> M;
    std::cout << std::endl;


}

// Функция креэйт, обеспечивающая работу 2 потока 
void create() {
   // создание файла для записи ;

}


int main()
{
    setlocale(LC_ALL, "ru"); // Поддержка русского языка
    
    std::queue<Message> message_queue; // создание очереди месседжей, с которой будут работать потоки





    std::thread th1([&]() {read(); });
    std::thread th2([&]() {create(); });
    th1.join();
    th2.join();
}

