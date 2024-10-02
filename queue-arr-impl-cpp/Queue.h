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
        public :
            Queue() {
                arr = new T[INTIAL_SIZE];
                head = -1;
                tail = -1; 
            };
            void enqueue(T value_param);
            T dequeue();
            T peek();
            bool is_empty();
    };

    template <typename T>
    bool Queue<T>::is_empty()
    {
        return (head == -1 && tail == -1);
    }

    
    
}