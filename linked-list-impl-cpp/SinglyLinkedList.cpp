#include "LinkedListImpl.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList()
{
    head = nullptr;
    length = 0;
}
Node* SinglyLinkedList::getHead(){
    return head;
}
// INSERT OPERATIONS
void SinglyLinkedList::insertFirst(int value_param)
{
    Node* newNode = new Node();
    newNode->value = value_param;
    newNode->next = head;
    head = newNode;
    ++length;
}
void SinglyLinkedList::insertLast(int value_param)
{
    if(length == 0){
         insertFirst(value_param);
         return; 
    }
    Node* current = head;
    Node* newNode = new Node();
    newNode->value = value_param;
    newNode->next = nullptr;

    while(current->next != nullptr){ current = current->next; }
    current->next = newNode;
    ++length;
}
void SinglyLinkedList::insertAt(int value_param, int index_param)
{
    if(index_param < 0 || index_param > length){
        std::cout << "Failed Insert: Index parameter out of bounds..." << std::endl;
        return;
    }
    if(index_param == 0){
        insertFirst(value_param);
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    Node* newNode = new Node();
    int count{};
    newNode->value = value_param;

    while(count != index_param){
        prev = current;
        current = current->next;
        ++count;
    }
    prev->next = newNode;
    newNode->next = current;
    ++length;
}
// DELETE OPERATIONS
void SinglyLinkedList::deleteFirst()
{
    if(length == 0){
        std::cout << "Failed Delete: Cannot delete from empty list..." << std::endl;
        return;
    }
    Node* current = head;
    head = current->next;
    delete current;
    --length;
}
void SinglyLinkedList::deleteLast()
{
    if(length == 0){
        std::cout << "Failed Delete: Cannot delete from empty list..." << std::endl;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    while(current->next != nullptr){
        prev = current;
        current = current->next;
    }
    prev->next = nullptr;
    delete current;
    --length;
}
void SinglyLinkedList::deleteAt(int index_param)
{
    if(index_param < 0 || index_param > length){
        std::cout << "Failed Delete: Index parameter out of bounds..." << std::endl;
        return;
    }
    if(index_param == 0){
        deleteFirst();
        return;
    }
    if(index_param == length-1){
        deleteLast();
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    int count{};

    while(count != index_param){
        prev = current;
        current = current->next;
        ++count;
    }
    prev->next = current->next;
    delete current;
    --length;
}
// SEARCH OPERATIONS
int SinglyLinkedList::findNode(int value_param)
{
    if(length == 0){
        std::cout << "Find Failed: List is empty" << std::endl;
        return -1;
    }
    Node* current = head;
    int idx{};
    while(current != nullptr){
        if(current->value == value_param){ return idx; }
        current = current->next;
        ++idx;
    }
    return -1;
}
// UTILITY OPERATIONS
void SinglyLinkedList::reverseList()
{
    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
Node* SinglyLinkedList::getMedian(Node* head)
{
    if(!head) return nullptr; 
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node* SinglyLinkedList::merge(Node* left, Node* right)
{
    if(!left) return right;
    if(!right) return left;

    Node* res = nullptr;

    if(left->value <= right->value){
        res = left;
        res->next = merge(left->next,right);
    } else {
        res = right;
        res->next = merge(left, right->next);
    }

    return res;
}
Node* SinglyLinkedList::sort(Node* head){
    if(!head || !head->next){
        return head;
    }
    Node* middle = getMedian(head);
    Node* nextMiddle = middle->next;
    middle->next = nullptr;

    Node* left = sort(head);
    Node* right = sort(nextMiddle);

    return merge(left,right);
}

void SinglyLinkedList::printInfo()
{
    std::cout << std::endl;

    Node* current = head;
    while(current != nullptr){
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "null\nLength: " << length << std::endl;
    std::cout << std::endl;
}
