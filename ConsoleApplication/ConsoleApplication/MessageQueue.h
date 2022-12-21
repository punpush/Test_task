#pragma once

#include<iostream>
#include "utility"
#include "queue"
#include <mutex>
#include <condition_variable>


// Класс сообщений, содержащий размер и указатель на данные в буфере

template<typename Type>
struct MessageQueue
{

    MessageQueue(size_t size_) : size_(size_) {}


    void get_message(std::pair<size_t, Type*> message) {

        std::unique_lock<std::mutex> ul1(data_mutex);

        if (size_now < size_) {
            size_data.push(message); // очередь, хранящая пару из размера и указателя на область памяти
            size_now++; // увеличение размера очереди 

        }
        else throw std::runtime_error("queue is full");

        cv.notify_one();

        ul1.unlock();
    }



    std::pair<size_t, Type*> send_message() {

        std::unique_lock<std::mutex> ul2(data_mutex);

        while (size_data.size() == 0)
        {
            cv.wait(ul2);
        }

        std::pair<size_t, Type*> message = size_data.front();

        size_data.pop();

        return message;

        ul2.unlock();

    }



public:

    std::condition_variable cv;
    std::mutex data_mutex;
    Type* data_;
    size_t size_of_message = 0; // размер читаемых данных
    size_t size_now = 0; // текущая очередь
    size_t size_ = 0; // дазмер очереди
    std::queue<std::pair<size_t, Type*>> size_data; // очередь сообщений 
};
