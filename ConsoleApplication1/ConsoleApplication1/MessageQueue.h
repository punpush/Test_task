#pragma once

#include<iostream>
#include "Buffer.h"
#include "utility"
#include "queue"



// Класс сообщений, содержащий размер и указатель на данные в буфере

template<typename Type>
struct MessageQueue  
{

    MessageQueue(size_t size_,Buffer<Type>& buffer) : size_(size_), buffer(buffer) {}
    

    void get_message(Buffer<Type>& buffer) {

        std::pair<size_t, Type*> message = buffer.get();
        if (size_now < size_) {
            gq.push(message); // очередь, хранящая пару из размера и указателя на область памяти
            size_now++; // увеличение размера очереди 

        }
    }

protected:

    Type* data_;
    Buffer<Type>& buffer;
    size_t size_of_message = 0; // размер читаемых данных
    size_t size_now = 0; // текущая очередь
    size_t size_ = 0; // дазмер очереди
    std::queue<std::pair<size_t, Type*>> gq; // очередь сообщений 
};
