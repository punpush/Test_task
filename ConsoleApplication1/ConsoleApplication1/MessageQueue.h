#pragma once

#include<iostream>
#include "Buffer.h"
#include "utility"
#include "queue"



// Класс сообщений, содержащий размер и указатель на данные в буфере

template<typename Type>
struct MessageQueue : Buffer<Type> // Наследование от буфера
{

    MessageQueue() {};
    


     // Функция записи сообщений 
    void read() {

        
        Type* data_ = Buffer<Type>::get(); // Получение адреса хвоста
        size_t size = sizeof(this->tail);  // Размер хвоста

        gq.push({size,data_}); // очередь, хранящая пару из размера и указателя на область памяти

        size_ ++ // увеличение размера очереди 

    }


protected:
    Type* data_ = 0;
    size_t size = 0;
    size_t size_ = 0;
    std::queue<std::pair<size_t, Type*>> gq;
};
