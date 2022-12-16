#pragma once

#include<iostream>
#include "Buffer.h"
#include "utility"
#include "queue"



// Êëàññ ñîîáùåíèé, ñîäåðæàùèé ðàçìåð è óêàçàòåëü íà äàííûå â áóôåðå

template<typename Type>
struct MessageQueue : Buffer<Type> // Наследование от буфера
{

    MessageQueue() {};
    


    // Ôóíêöèÿ çàïèñè ñîîáùåíèé 
    void read() {

        
        Type* data_ = Buffer<Type>::get(); // Ïîëó÷åíèå àäðåñà õâîñòà
        size_t size = sizeof(this->tail);  // Ðàçìåð õâîñòà

        gq.push({size,data_}); // î÷åðåäü, õðàíÿùàÿ ïàðó èç ðàçìåðà è óêàçàòåëÿ íà îáëàñòü ïàìÿòè

        size_ ++ // óâåëè÷åíèå ðàçìåðà î÷åðåäè 

    }


protected:
    Type* data_ = 0;
    size_t size = 0;
    size_t size_ = 0;
    std::queue<std::pair<size_t, Type*>> gq;
};
