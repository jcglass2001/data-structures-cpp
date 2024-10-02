#include <iostream>
#include "LinkedListImpl.h"

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}
void DoublyLinkedList::insertFirst(int value_param)
{
    Node* newNode = new Node();
    newNode->value = value_param;
    if(length == 0){
        newNode->next = head;
        head = newNode;
        tail = newNode;
        ++length;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    ++length;
}
void DoublyLinkedList::insertLast(int value_param)
{
    if(length == 0){
        insertFirst(value_param);
        return;
    }
    Node* current = tail;
    Node* newNode = new Node();
    newNode->value = value_param;
    newNode->prev = current;
    current->next = newNode;
    tail = newNode;
    ++length;
}
void DoublyLinkedList::insertAt(int value_param, int index_param)
{  
    if(index_param < 0 || index_param >= length){
        std::cout << "Failed insert: Index parameter out of bounds..." << std::endl;
        return;
    } 
    if(index_param == 0 || length == 0){
        insertFirst(value_param);
        return;
    }
    if(index_param == length-1){
        insertLast(value_param);
        return;
    }
    int count{};
    Node* current;
    Node* newNode = new Node();
    newNode->value = value_param;
    if(index_param > length/2){
        current = tail;
        count = length-1;

        while(count != index_param){
            current = current->prev;
            --count;
        }
    } else {
        current = head;
        while(count != index_param){
            current = current->next;
            ++count;
        }
    }
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    ++length;   
}
void DoublyLinkedList::deleteFirst()
{
    if(length == 0){
        std::cout << "Failed deletion: Cannot delete from empty list..." << std::endl;
        return;
    }
    Node* current = head;
    current->next->prev = nullptr;
    head = current->next;
    delete current;
    --length;

}
void DoublyLinkedList::deleteLast()
{   
    if(length == 0){
        std::cout << "Failed deletion: Cannot delete from empty list..." << std::endl;
        return;
    }
    Node* current = tail;
    current->prev->next = nullptr;
    tail = current->prev;
    delete current;
    --length;
}
void DoublyLinkedList::deleteAt(int index_param)
{
    if(length == 0){
        std::cout << "Failed deletion: Cannot delete from empty list..." << std::endl;
        return;
    }
    if(index_param < 0 || index_param >= length){
        std::cout << "Failed deletion: Index parameter out of bounds..." << std::endl;
        return;
    }
    if(index_param == 0){
        deleteFirst();
        return;
    }
    Node* current;
    int count{};

    if(index_param > length/2){
        current = tail;
        count = length-1;
        while(count != index_param){
            current = current->prev;
            --count;
        }
    } else {
        current = head;
        while(count != index_param){
            current = current->next;
            ++count;
        }
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    --length;
}
Node* DoublyLinkedList::searchAt(int index_param)
{
    if(length == 0){
        std::cout << "List empty..." << std::endl;
        return nullptr;
    }
    if(index_param < 0 || index_param >= length){
        std::cout << "Failed search: Index parameter out of bounds..." << std::endl;
        return nullptr;
    }
    Node* current = head;
    int count{};

    while(count != index_param){
        current = current->next;
        ++count;
    }
    return current;
}
void DoublyLinkedList::printInfo()
{
    std::cout << std::endl;
    if(length == 0){
        std::cout << "null" << std::endl;
    } else {
        std::cout << "null <- ";

        Node* current = head;
        while(current != nullptr){
            std::cout << current->value;
            if(current->next != nullptr){
                std::cout << " <-> ";
            }
            current = current->next;
        }
    
        std::cout << " -> null" << std::endl;
        std::cout << "Length: " << length << std::endl;
    }
    std::cout << std::endl;
    
}
