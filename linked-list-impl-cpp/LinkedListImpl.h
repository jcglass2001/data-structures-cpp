struct Node
{
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class SinglyLinkedList
{
    private :
        Node* head;
        int length;
    
    public : 
        SinglyLinkedList();
        Node* getHead();
        // insertions
        void insertFirst(int value_param);
        void insertLast(int value_param);
        void insertAt(int value_param, int index_param);
        // deletions
        void deleteFirst();
        void deleteLast();
        void deleteAt(int index_param);
        // searches
        int findNode(int value_param);
        // util
        Node* sort(Node* head);
        Node* getMedian(Node* head);
        Node* merge(Node* left, Node* right);
        void reverseList();
        void printInfo();
};
class DoublyLinkedList
{
    private : 
        Node* head;
        Node* tail;
        int length;
    
    public :
        DoublyLinkedList();
        // insertions
        void insertFirst(int value_param);
        void insertLast(int value_param);
        void insertAt(int value_param, int index_param);
        // deletions
        void deleteFirst();
        void deleteLast();
        void deleteAt(int index_param);
        // searches
        Node* searchAt(int index_param);
        // util
        Node* sort(Node* head);
        Node* getMedian(Node* head);
        Node* merge(Node* left, Node* right);
        void printInfo();
};