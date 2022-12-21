#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "Buffer.h"
#include "MessageQueue.h"
#include "utility"
#include <stdlib.h>



// Счетчик, заполняющий буфер 1МБ данных каждые Т секунд
template<typename Type>
struct Counter
{

    Counter(int T, size_t M, Buffer<Type>& buffer, MessageQueue<std::uint64_t>& queue_) : T(T), M(M), buffer(buffer), queue_(queue_) {}

     // Метод, реализующий заполнение и отправку сообщения
    void fill_in() {

        while ((Wcounter < M)) // *500000
        {
            if (Wcounter == M - 1)
            {
                exit(0);
            }

            while ((counter < 10) && (Wcounter < M))  // 1 МБ (500000)
            {
                buffer.add(Wcounter); // Заполнение счетчиком

                counter++; // Инкрементирование счетчиков
                Wcounter++;
            }
            counter = 0;
            std::pair<size_t, Type*>message = buffer.get();
            queue_.get_message(message);
            buffer.reset();
            std::this_thread::sleep_for(T);
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
