#include <iostream>
#include "Stack.h"

int main()
{  
    std::cout << "Initializing Stack()..." << std::endl;
    Stack::Stack<int> s;
    s.print();
    std::cout << "\nPushing elements onto stack with push()..." << std::endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    std::cout << "\nPopping elements from stack with pop()..." << std::endl;
    std::cout << "pop() returned value : " << s.pop().value() << std::endl;

    std::cout << "\nPeeking top element from stack with peek()..." << std::endl;
    std::cout << "peek() returned value : " << s.peek().value() << std::endl;

    std::cout << "\nResulting stack : ";
    s.print();
    
    return 0;
}