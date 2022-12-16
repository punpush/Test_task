#pragma once

#include<iostream>
#include "Buffer.h"
#include "utility"
#include "queue"



// ����� ���������, ���������� ������ � ��������� �� ������ � ������

template<typename Type>
struct MessageQueue : Buffer<Type>
{

    MessageQueue() {};
    


    // ������� ������ ��������� 
    void read() {

        
        Type* data_ = Buffer<Type>::get(); // ��������� ������ ������
        size_t size = sizeof(this->tail);  // ������ ������

        gq.push({size,data_}); // �������, �������� ���� �� ������� � ��������� �� ������� ������

        size_ ++ // ���������� ������� ������� 

    }


protected:
    Type* data_ = 0;
    size_t size = 0;
    size_t size_ = 0;
    std::queue<std::pair<size_t, Type*>> gq;
};