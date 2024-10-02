#include <iostream>
#include "Tree.h"

int main()
{
    // int arr[] = {1,2,3,4,5,6,7};
    char arr[] = {'a','b','c','d','e'};
    // bool arr[] = {true, false, true, true, false};
    int size = sizeof(arr) / sizeof(arr[1]);
    auto root = createTree<char>(arr,0,size);

    std::cout << "Tree (In-order traversal) : ";
    dfs_in_order(root);
    std::cout << std::endl;
    
    std::cout << "Tree (Pre-order traversal) : ";
    dfs_pre_order(root);
    std::cout << std::endl;

    std::cout << "Tree (Post-order traversal) : ";
    dfs_post_order(root);
    std::cout << std::endl;
}
