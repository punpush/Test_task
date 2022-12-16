#pragma once

#include<iostream>
#include "Buffer.h"
#include "utility"
#include "queue"



//  ласс сообщений, содержащий размер и указатель на данные в буфере

template<typename Type>
struct MessageQueue : Buffer<Type>
{

    MessageQueue() {};
    


    // ‘ункци€ записи сообщений 
    void read() {

        
        Type* data_ = Buffer<Type>::get(); // ѕолучение адреса хвоста
        size_t size = sizeof(this->tail);  // –азмер хвоста

        gq.push({size,data_}); // очередь, хран€ща€ пару из размера и указател€ на область пам€ти

        size_ ++ // увеличение размера очереди 

    }


protected:
    Type* data_ = 0;
    size_t size = 0;
    size_t size_ = 0;
    std::queue<std::pair<size_t, Type*>> gq;
};