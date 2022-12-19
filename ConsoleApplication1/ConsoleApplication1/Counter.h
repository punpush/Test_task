#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "Buffer.h"
#include "MessageQueue.h"



// �������, ����������� ����� 1�� ������ ������ � ������
template<typename Type>
struct Counter 
{

    Counter(int T, size_t M, Buffer<Type>& buffer, MessageQueue<std::uint64_t> &queue_): T(T), M(M), buffer(buffer), queue_(queue_) {}

     // �����, ����������� ���������� � �������� ���������
    void fill_in() {
        while ((Wcounter < M)) // *500000
        {

                while (counter < 10) 
                {   
                    buffer.add(Wcounter); // ���������� ���������

                    counter++;
                    Wcounter++;
                }
                counter = 0;
                queue_.get_message(buffer);
                buffer.reset();
                std::this_thread::sleep_for(T);
            }
        }
    

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
