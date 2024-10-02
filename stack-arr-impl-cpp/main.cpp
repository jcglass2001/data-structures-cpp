#include <iostream>
#include "Stack.h"

int main()
{
    std::cout << "Initializing Stack()..." << std::endl;
    Stack<int> s;

    std::cout << "Pushing elements onto stack..." << std::endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();

    std::cout << "\nPopping last element from stack..." << std::endl;
    s.pop();
    s.print();

    std::cout << "\nGrabbing last element from stack..." << std::endl;
    std::cout << "peek() returns: " << s.peek() << std::endl;

    std::cout << "\nChecking if stack is empty..." << std::endl;
    std::cout << "isEmpty() returns: " << s.isEmpty() << std::endl;

    return 0;
}