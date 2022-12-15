#pragma once




// Ïðè çàïèñè èëè ÷òåíèè ãîëîâà è õâîñò äâèæóòñÿ âïåðåä, ïðè äîñòèæåíèè ïîñëåäíåãî ýëåìåíòà - ïåðåõîä ê ïåðâîìó

template<typename Type>
struct Buffer
{

    Buffer(size_t max_size): max_size(max_size), buffer(new Type[max_size]) {};
    
    ~Buffer() {
        delete[] buffer;
    }

   //Çàïèñü â áóôåð

    void add(Type n) {

        if (full()) 
        {
            throw std::runtime_error("buffer is full");
        }

        buffer[head] = n;

        head = (head + 1) % max_size;

       
    }

    // ×òåíèå èç áóôåðà

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
        return head == tail; // Ïðîâåðêà íà ïóñòîòó
    }
    bool full() {
        return tail == (head + 1) % max_size; // Ïðîâåðêà íà ïåðåïîëíåíèå
    }

    protected:
        
        Type* buffer; // Îáëàñòü ïàìÿòè
        size_t head = 0; // Ãîëîâà áóôåðà
        size_t tail = 0; // Õâîñò áóôåðà
        const size_t max_size; // Ðàçìåð áóôôåðà
       

};
