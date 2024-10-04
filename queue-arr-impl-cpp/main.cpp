#include <iostream>
#include "Queue.h"

int main()
{
    std::cout << "Initializing Queue..." << std::endl;
    Queue::Queue<int> queue;

    std::cout << "Inserting elements into queue..." << std::endl;
    queue.enqueue(4);
    queue.enqueue(6);
    queue.enqueue(2);

    std::cout << "Queue size: " << queue.size() << std::endl;

    std::cout << "Removing elements from queue..." << std::endl;
    queue.dequeue();
    queue.dequeue();

    std::cout << "Queue size: " << queue.size() << std::endl;

    return 0;
}