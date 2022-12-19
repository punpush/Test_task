#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "Buffer.h"
#include "MessageQueue.h"



// Класс, осуществляющий заполнение буфера, с периодичностью Т
template<typename Type>
struct Counter 
{

    Counter(int T, size_t M, Buffer<Type>& buffer, MessageQueue<std::uint64_t> &queue_): T(T), M(M), buffer(buffer), queue_(queue_) {}

     // метод заполнения буфера
    void fill_in() {
        while ((Wcounter <= M)) // *500000
        {
<<<<<<< HEAD
            while (counter < 10) {    //���������� 1 �� <500000
                buffer.add(Wcounter); // ���������� ���������� �������
=======
            while (counter < 500000) {    //заполнение 1 МБ
                buffer.add(rand() % 100); // заполнение случайными числами
>>>>>>> b436335a784424dd8da5175bb15be10d5fa8b98d
                counter++;
                Wcounter++;
            }
            counter = 0;
            queue_.get_message(buffer);
            std::this_thread::sleep_for(T);
        }
    }
        
<<<<<<< HEAD
 



=======
   // void create_message() {



    }

    void waiting(int T) {
        Sleep(T*1000); // ожидание в секундах
    }

>>>>>>> b436335a784424dd8da5175bb15be10d5fa8b98d
protected:


    std::chrono::seconds T;
    size_t size_of_message = 0;
    Type* data_ = 0;
    Buffer<Type>& buffer;
    MessageQueue<std::uint64_t>& queue_;
    size_t M = 0;
    size_t counter = 0;
    size_t Wcounter = 0;
};
