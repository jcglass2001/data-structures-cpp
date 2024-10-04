#include <optional>
#include <iostream>
#define INTIAL_SIZE 20
namespace Queue 
{
    template <typename T>
    class Queue
    {
        private : 
            T* arr;
            int head;
            int tail;
            int capacity;
        public :
            Queue() {
                arr = new T[INTIAL_SIZE];
                capacity = INTIAL_SIZE;
                head = -1;
                tail = -1; 
            };
            Queue(int size_param) {
                arr = new T[size_param];
                capacity = size_param;
                head = -1;
                tail = -1;
            }
            ~Queue() {
                delete[] arr;
            }
            void enqueue(T value_param);
            std::optional<T> dequeue();
            std::optional<T> front();
            std::optional<T> rear();
            bool is_empty();
            bool is_full();
            int size();
            void print_info();
    };
    
    template <typename T>
    void Queue<T>::enqueue(T value_param)
    {
        if(is_full()){
            std::cerr << "enqueue() failed : queue is full" << std::endl;
            return;
        }
        if (is_empty()) {
            head = 0;
            tail = 0;
            arr[tail] = value_param;
        } else {
            tail = (tail + 1) % capacity;
            arr[tail] = value_param;
        }
    }

    template <typename T>
    std::optional<T> Queue<T>::dequeue()
    {
        if(is_empty()) return std::nullopt;

        if(head == tail){
            T value = arr[head];
            head = -1; 
            tail = -1;
            return value;
        }
        T value = arr[head];
        head = (head + 1) % capacity;
        return value;
    }

    template <typename T>
    std::optional<T> Queue<T>::front()
    {
        if(is_empty()) return std::nullopt;
        return arr[head];
    }

    template <typename T>
    std::optional<T> Queue<T>::rear()
    {
        if(is_empty()) return std::nullopt;
        return arr[tail];
    }

    template <typename T>
    bool Queue<T>::is_empty()
    {
        return (head == -1 && tail == -1);
    }

    template <typename T>
    bool Queue<T>::is_full()
    {
        return (tail + 1) % capacity == head;
    }

    template <typename T>
    int Queue<T>::size()
    {
        if(is_empty()) return 0;
        if(tail >= head) return tail - head + 1;
        return capacity - (head - tail - 1);
    }

    
    
}