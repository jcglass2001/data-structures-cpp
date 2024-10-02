#include <iostream>
#include "LinkedListImpl.h"
void sll_operations()
{
    std::cout << "Initializing SinglyLinkedList()..." << std::endl;
    SinglyLinkedList sll = SinglyLinkedList();
    sll.printInfo();
    std::cout << "Inserting values using insertFirst()..." << std::endl;
    sll.insertFirst(1);
    sll.insertFirst(2);
    sll.insertFirst(4);
    sll.printInfo(); // 4 -> 2 -> 1 -> null
    std::cout << "Inserting values using insertLast()..." << std::endl;
    sll.insertLast(0);
    sll.printInfo(); // 4 -> 2 -> 1 -> 0 -> null
    std::cout << "Inserting values using insertAt()..." << std::endl;
    sll.insertAt(3,1);
    sll.printInfo(); // 4 -> 3 -> 2 -> 1 -> 0 -> null
    std::cout << "Deleting values using deleteFirst()..." << std::endl;
    sll.deleteFirst();
    sll.printInfo(); // 3 -> 2 -> 1 -> 0 -> null
    std::cout << "Deleting values using deleteLast()..." << std::endl;
    sll.deleteLast();
    sll.printInfo(); // 3 -> 2 -> 1 -> null
    std::cout << "Deleting values using deleteAt()..." << std::endl;
    sll.deleteAt(1);
    sll.printInfo(); // 3 -> 1 -> null
    std::cout << "Searching node by value using findeNode()..." << std::endl;
    std::cout << "Node found at index: " << sll.findNode(1) << std::endl; // function should return 1
    std::cout << std::endl;
    std::cout << "Reversing SinglyLinkedList using reverseList()..." << std::endl;
    sll.reverseList();
    sll.printInfo();
    sll.reverseList();
    sll.printInfo();
    std::cout << std::endl;
    std::cout << "Sorting SinglyLinkedList using sort()..." << std::endl;
    Node* sll_sorted = sll.sort(sll.getHead());
    Node* current = sll_sorted;
    while(current != nullptr){
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}
void dll_operations()
{
    std::cout << "Initializing DoublyLinkedList()..." << std::endl;
    DoublyLinkedList dll = DoublyLinkedList();
    dll.printInfo();
    std::cout << "Inserting values using insertFirst()..." << std::endl;
    dll.insertFirst(5); // null <- (5) -> null
    dll.insertFirst(6); // null <- (6) <-> 5 -> null
    dll.insertFirst(3); // null <- (3) <-> 6 <-> 5 -> null
    dll.printInfo();
    std::cout << "Inserting values using insertLast()..." << std::endl;
    dll.insertLast(7); // null <- 3 <-> 6 <-> 5 <-> (7) -> null
    dll.insertLast(2); // null <- 3 <-> 6 <-> 5 <-> 7 <-> (2) -> null
    dll.printInfo();
    std::cout << "Inserting values using insertAt()..." << std::endl;
    dll.insertAt(9,3); // null <- 3 <-> 6 <-> 5 <-> (9) <-> 7 <-> 2 -> null
    dll.printInfo();
    std::cout << "Deleting values using deleteFirst()..." << std::endl;
    dll.deleteFirst(); // null <- 6 <-> 5 <-> 9 <-> 7 <-> 2 -> null
    dll.printInfo();
    std::cout << "Deleting values using deleteLast()..." << std::endl;
    dll.deleteLast(); // null <- 6 <-> 5 <-> 9 <-> 7 -> null;
    dll.printInfo();
    std::cout << "Deleting values using deleteAt()..." << std::endl;
    dll.deleteAt(2); // null <- 6 <-> 5 <-> 7 -> null;
    dll.printInfo();
    std::cout << "Searching values using findAt()..." << std::endl;
    int idx = 2;
    Node* node = dll.searchAt(idx);
    std::cout << "Node at position: [" << idx << "] has value of : " << node->value << std::endl;
}

void printList(Node* current)
{
    while(current != nullptr){
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std:: cout << "null" << std::endl;
}
int main()
{   
    sll_operations();
    // dll_operations();
    return 0;
}