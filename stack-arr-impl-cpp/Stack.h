#include <iostream>
#define MAX_SIZE 101

template <typename T>
class Stack 
{   
    private : 
        int arr [MAX_SIZE];
        int top;

    public :
        Stack();
        void push(int value_param);
        void pop();
        T peek();
        bool isEmpty();
        void print();
};

template <typename T>
Stack<T>::Stack() : top(-1) {};


template <typename T>
void Stack<T>::push(int value_param)
{
    if(top == MAX_SIZE - 1){
        std::cout << "Push error: Stack overflow..." << std::endl;
        return;
    }
    arr[++top] = value_param;
}
template <typename T>
void Stack<T>::pop()
{
    if(isEmpty()){
        std::cout << "Pop error: Cannot pop() from empty stack..." << std::endl;
        return;
    }
    --top;
}
template <typename T>
T Stack<T>::peek()
{
    if(isEmpty()){
        std::cout << "Peek error: Stack is empty..." << std::endl;
        return -1;
    }
    return arr[top];
}
template <typename T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}
template <typename T>
void Stack<T>::print()
{
    std::cout << "\nStack:\t";
    for(size_t i{}; i <= top; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}