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

    // Метод записи сообщения в очередь 
    void get_message(std::pair<size_t, Type*> message) {


        if (size_now < size_) {

            size_data.push(message); // очередь, хранящая пару из размера и указателя на область памяти

            size_now++; // увеличение размера очереди 
            
            std::cout << "размер очереди " << size_now << std::endl; // Вывод размера очереди

        }
        else throw std::runtime_error("queue is full");

        cv.notify_one();

    }


    // Метод отправки сообщения из очереди
    std::pair<size_t, Type*> send_message() {

        std::unique_lock<std::mutex> ul2(data_mutex);

        while (size_data.size() == 0) // Ожидание появления сообщения
        {
            cv.wait(ul2);
        }

        std::pair<size_t, Type*> message = size_data.front();

        size_data.pop();

        size_now --;

      

        std::cout << "размер очереди " << size_now << std::endl; // Вывод размера очереди

        return message;

        

        ul2.unlock();

    }

    // Метод pop
    void pop() {
        if (size_data.size() == 0)
        {
            throw std::runtime_error("queue is empty");
        }

        size_data.pop();
    }

    // Метод push
    void push(std::pair<size_t, Type*> n)
    {
        size_data.push(n);

    }

    // Метод получения размера для работы цикла записи
    size_t get()
    {
        std::unique_lock<std::mutex> ul3(data_mutex);

        while (size_data.size() == 0)
        {
            cv.wait(ul3);
        }

        std::pair<size_t, Type*> size = size_data.front();

        return size.first;

        ul3.unlock();
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
