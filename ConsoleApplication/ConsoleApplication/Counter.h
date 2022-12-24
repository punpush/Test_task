#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "Buffer.h"
#include "MessageQueue.h"
#include "utility"



// Счетчик, заполняющий буфер 1МБ данных каждые Т секунд
template<typename Type>
struct Counter
{

    Counter(int T, size_t M, Buffer<Type>& buffer, MessageQueue<Type>& queue_) : T(T), M(M), buffer(buffer), queue_(queue_) {}

    // Метод, реализующий заполнение и отправку сообщения
    void fill_in() {

        while ((Wcounter < M * 125000))
        {

            while ((counter < 125000) && (Wcounter < M* 125000))
            {
                buffer.add(Wcounter); // Заполнение счетчиком

                counter++; // Инкрементирование счетчиков
                Wcounter++;
            }
            counter = 0;
            std::pair<size_t, Type*>message = buffer.get();
            queue_.get_message(message); // Добавление сообщения в очередь 
            buffer.reset();
            std::this_thread::sleep_for(T); // Остановка потока на заданное пользователем время
        }

    }


protected:


    std::chrono::seconds T;
    size_t size_of_message = 0;
    Type* data_ = 0;
    Buffer<Type>& buffer;
    MessageQueue<Type>& queue_;
    size_t M = 0;
    size_t counter = 0;
    size_t Wcounter = 0;
};

