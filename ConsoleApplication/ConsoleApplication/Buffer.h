#pragma once
#include "utility"
#include "MessageQueue.h"
// ��� ������ ��� ������ ������ � ����� �������� ������, ��� ���������� ���������� �������� - ������� � �������

template<typename Type>
struct Buffer
{

    Buffer(size_t max_size) :max_size(max_size), buffer(new Type[max_size]) {}

    Buffer() {}

    void clear() {
        delete[] buffer;
    }

    void add(Type n) {

        if (full())
        {
            throw std::runtime_error("buffer is full");
        }

        buffer[head] = n;

        //std::cout << &buffer[head] <<"  " << buffer[head] << std::endl << head << std::endl; //���������� ������

        head = (head + 1) % max_size;



    }

    // ��������� �� ������ � �� ������

    std::pair<size_t, Type*> get() {
        if (empty())
        {

            throw std::runtime_error("buffer is empty");
        }

        return std::pair<size_t, Type*>((head - tail), &buffer[tail]);

    }


    void reset()
    {
        tail = head;
    }

    bool empty() {
        return head == tail; // �������� �� �������
    }
    bool full() {
        return tail == (head + 1); // �������� �� ������������
    }

protected:

    Type* buffer; // ������� ������
    size_t head = 0; // ������ ������
    size_t tail = 0; // ����� ������
    const size_t max_size = 0; // ������ �������


};

