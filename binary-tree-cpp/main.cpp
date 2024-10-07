#include <iostream>
#include <vector>
#include "Tree.h"

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    //char arr[] = {'a','b','c','d','e'};
    // bool arr[] = {true, false, true, true, false};
    int size = sizeof(arr) / sizeof(arr[1]);
    // auto root = createTree<int>(arr,0,size);

    Tree::Node<int>* root = nullptr;
    std::vector<int> values = {6,10,3,5,8,1,9};

    root = createTree(root,values);

    int input;
    std::cout << "Enter number to be searched: ";
    std::cin >> input;
    if(search(root,input) == true) std::cout << "Found\n";
    else std::cout << "Not Found\n";

    std::cout << "Tree (In-order traversal) : ";
    dfs_in_order(root);
    std::cout << "\n";
    
    std::cout << "Tree (Pre-order traversal) : ";
    dfs_pre_order(root);
    std::cout << "\n";

    std::cout << "Tree (Post-order traversal) : ";
    dfs_post_order(root);
    std::cout << "\n";
}
