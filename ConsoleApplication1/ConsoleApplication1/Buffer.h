#pragma once




// ��� ������ ��� ������ ������ � ����� �������� ������, ��� ���������� ���������� �������� - ������� � �������

template<typename Type>
struct Buffer
{

    Buffer(size_t max_size): max_size(max_size), buffer(new Type[max_size]) {};

   //������ � �����

    void add(Type n) {

        if (full()) 
        {
            throw std::runtime_error("buffer is full");
        }

        buffer[head] = n;

        head = (head + 1) % max_size;

    }

    // ������ �� ������

    Type get() {
        if (empty())
        {
            throw std::runtime_error("buffer is empty");
        }

        Type value = buffer[tail];
        tail = (tail + 1) % max_size;

        return value;
    }

    bool empty() {
        return head == tail; // �������� �� �������
    }
    bool full() {
        return tail == (head + 1) ; // �������� �� ������������
    }

    private:
        
        Type* buffer; // ������� ������
        size_t head = 0; // ������ ������
        size_t tail = 0; // ����� ������
        const size_t max_size; // ������ �������
       

};