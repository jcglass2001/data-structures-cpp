#include <iostream>
#include <optional>

namespace Stack
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T>* next = nullptr;
    };

    template <typename T>
    class Stack
    {
    private:
        Node<T> *top;

    public:
        Stack() : top(nullptr) {};
        ~Stack(); 
        void push(T value_param);
        std::optional<T> pop();
        std::optional<T> peek();
        bool is_empty();
        void print();
    };
    template <typename T>
    Stack<T>::~Stack()
    {
        while (!is_empty()) {
            pop();
        }
    }
    template <typename T>
    void Stack<T>::push(T value_param)
    {
        Node<T>* newNode = new Node<T>();
        newNode->value = value_param;
        newNode->next = top;
        top = newNode;
    }
    template <typename T>
    std::optional<T> Stack<T>::pop()
    {
        if(is_empty()){
            return std::nullopt;
        }
        Node<T>* node = top;
        T popped_value = node->value;
        top = node->next;
        delete node;
        return popped_value;
    }
    template <typename T>
    std::optional<T> Stack<T>::peek()
    {
        if(is_empty()) {
            return std::nullopt;
        }
        return top->value;
    }
    template <typename T>
    bool Stack<T>::is_empty()
    {
        return top == nullptr;
    }

    template <typename T>
    void Stack<T>::print()
    {
        Node<T>* node = top;
        while(node != nullptr){
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
}