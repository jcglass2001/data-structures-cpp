#include <iostream>
#include <vector>
#include "Tree.h"

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    //char arr[] = {'a','b','c','d','e'};
    // bool arr[] = {true, false, true, true, false};
    int size = sizeof(arr) / sizeof(arr[1]);
    // auto root = create_tree<int>(arr,0,size);

    Tree::Node<int>* root = nullptr;
    std::vector<int> values = {6,10,3,5,8,1,9};
    root = create_tree(root,values);

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

    std::cout << "Tree (Level-order traversal) : ";
    bfs_level_order(root);
    std::cout << "\n";

    std::cout << "Height of tree : " << find_height(root) << "\n";
    std::cout << "Minimum value in tree : " << find_min(root) << "\n";
    std::cout << "Maximum value in tree : " << find_max(root) << "\n";

    delete_tree(root);
    std::cout << "Tree nodes deleted...\n";

    return 0;
}
