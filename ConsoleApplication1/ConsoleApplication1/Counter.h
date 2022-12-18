#pragma once
#include <iostream>
#include <windows.h>
#include "Buffer.h"


// Класс, осуществляющий заполнение буфера, с периодичностью Т
template<typename Type>
struct Counter : Buffer<Type>
{

    Counter(int T, size_t M, Buffer<Type>& buffer): T(T), M(M), buffer(buffer) {}

     // метод заполнения буфера
    void fill_in() {
        while ((Wcounter <= M * 500000))
        {
            while (counter < 500000) {    //заполнение 1 МБ
                buffer.add(rand() % 100); // заполнение случайными числами
                counter++;
                Wcounter++;
            }
            counter = 0;
            waiting(T*1000);
        }
    }
        
   // void create_message() {



    }

    void waiting(int T) {
        Sleep(T*1000); // ожидание в секундах
    }

protected:

    size_t size_of_message = 0;
    Type* data_ = 0;
    Buffer<Type>& buffer;
    size_t M = 0;
    int T = 0;
    size_t counter = 0;
    size_t Wcounter = 0;
};
