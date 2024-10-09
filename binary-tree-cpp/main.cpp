#include <iostream>
#include <vector>
#include "Tree.h"

template <typename T>
void input_search(Tree::Node<T>* root)
{
    T input;
    std::cout << "Enter value to be searched: ";
    std::cin >> input;
    if(search(root,input) == true) std::cout << "Value found...\n";
    else std::cout << "Value not found...\n";
}
int main()
{

    Tree::Node<int>* root = nullptr;
    std::vector<int> values = {12,5,15,3,7,13,17,1,9,14,20,8,11,18};
    root = create_tree(root,values);

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

    std::cout << "Is Binary Search Tree : " << std::boolalpha << is_bst(root) << "\n";
    std::cout << "Height of tree : " << find_height(root) << "\n";
    std::cout << "Minimum value in tree : " << find_min(root)->value << "\n";
    std::cout << "Maximum value in tree : " << find_max(root)->value << "\n";

    input_search(root);

    delete_node(root, 15);

    std::cout << "Tree after deletion (Level-order traversal) : ";
    bfs_level_order(root);
    std::cout << "\n";

    delete_tree(root);
    std::cout << "Tree nodes deallocated...\n";

    return 0;
}
