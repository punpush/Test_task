// подключение библиотек и классов
// подключение библиотек и классов
#include <iostream>
#include<thread>
#include "Buffer.h"
#include "MessageQueue.h"
#include "Counter.h"
#include "FileManager.h"


// Функция рид, обеспечивающая работу 1 потока
template<typename Type>
void read(int T, size_t M, Buffer<Type>& buffer, MessageQueue<Type>& queue_) {



    Counter<Type> counter(T, M, buffer, queue_);

    // Запись данных в буфер

    counter.fill_in();


}

// Функция креэйт, обеспечивающая работу 2 потока 
template<typename Type>
void create(MessageQueue<Type>& queue_, size_t M) {
    // Создание файла для записи ;

    FileManager file;
    file.create_file();

    size_t counter = 0;

    // Запись данных в файл
    while (counter < M * 125000) {

        counter += queue_.get();
        
        file.writing(queue_.send_message());
       

    }

}


int main()
{
    setlocale(LC_ALL, "ru"); // Поддержка русского языка

    // Выделение памяти буффером

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

    system("cls"); // очистка экрана консоли

    MessageQueue<std::uint64_t> queue_(256); // создание очереди месседжей, с которой будут работать потоки

    // Потоки

    std::thread th1([&]() {read(T, M, buffer, queue_); });
    std::thread th2([&]() {create(queue_,M); });
    th1.join();
    th2.join();

    buffer.clear(); // Очистка памяти
}
