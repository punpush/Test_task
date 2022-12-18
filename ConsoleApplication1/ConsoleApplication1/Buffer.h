#pragma once

// При записи или чтении голова и хвост движутся вперед, при достижении последнего элемента - переход к первому

template<typename Type>
struct Buffer
{

    Buffer(size_t max_size):max_size(max_size), buffer (new Type[max_size]) {}

    Buffer() {}

   

  //  void init() {
   // buffer(new Type[max_size];
   // }

    void clear() {
        delete[] buffer;
    }

    void add(Type n) {

        if (full())
        {
            throw std::runtime_error("buffer is full");
        }

        buffer[head] = n;

        std::cout << &buffer[head] <<"  " << buffer[head] << std::endl << head << std::endl;

        head = (head + 1) % max_size;

        

    }

    // Чтение адреса хвоста из буфера

        Type* get() {
        if (empty())
        {
            throw std::runtime_error("buffer is empty");
        }

        std::cout << &buffer[tail] <<"  "<< buffer[tail] << std::endl << tail << std::endl;

        tail = (tail + 1) % max_size;

        return &buffer[tail-1];

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
        const size_t max_size = 0; // Размер буффера


};
