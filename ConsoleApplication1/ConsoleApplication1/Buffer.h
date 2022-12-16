#pragma once

// При записи или чтении голова и хвост движутся вперед, при достижении последнего элемента - переход к первому

template<typename Type>
struct Buffer
{

    Buffer(size_t max_size): max_size(max_size), buffer(new Type[max_size]) {};

    ~Buffer() {
        delete[] buffer;
    }

   //Запись в буфер

    void add(Type n) {

        if (full())
        {
            throw std::runtime_error("buffer is full");
        }

        buffer[head] = n;

        head = (head + 1) % max_size;


    }

    // Чтение из буфера

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
        return head == tail; // Проверка на пустоту
    }
    bool full() {
        return tail == (head + 1) ; // Проверка на переполнение
    }

    protected:

        Type* buffer; // Область памяти
        size_t head = 0; // Голова буфера
        size_t tail = 0; // Хвост буфера
        const size_t max_size; // Размер буффера


};
