#include <vector>

namespace Tree
{
    template <typename T>
    struct Node {
        Node<T>* left = nullptr;
        Node<T>* right = nullptr;
        T value;
    };
}
template <typename T>
bool search(Tree::Node<T>* root, T value_param)
{
    if(root == nullptr) return false;
    if(root->value == value_param) return true;
    else if(value_param < root->value) return search(root->left, value_param);
    else return search(root->right, value_param);
}

template <typename T>
Tree::Node<T>* insert(Tree::Node<T>* root, T value_param)
{
    if(root == nullptr){
        auto newNode = new Tree::Node<T>();
        newNode->value = value_param;
        root = newNode;
    } else if (value_param < root->value){
        root->left = insert(root->left, value_param);
    } else {
        root->right = insert(root->right, value_param);
    }
    return root;
}
// creates binary search tree
template <typename T>
Tree::Node<T>* createTree(Tree::Node<T>* root, const std::vector<T>& values_param)
{
    for(const T& value : values_param){
        root = insert(root, value);
    }
    return root;
}

// creates complete binary tree
template <typename T>
Tree::Node<T>* createTree(T arr[], int start, int end)
{
    if(start >= end){
        return nullptr;
    }

    Tree::Node<T>* root = new Tree::Node<T>();
    root->value = arr[start];

    int left_child_index = 2 * start + 1;
    int right_child_index = 2 * start + 2;

    if(left_child_index < end){
        root->left = createTree<T>(arr, left_child_index, end);
    }
    if(right_child_index < end){ 
        root->right = createTree<T>(arr, right_child_index, end);
    }

    return root;
}

template <typename T>
void dfs_in_order(Tree::Node<T>* node)
{
    if(node == nullptr){
        return;
    }
    dfs_in_order(node->left);
    std::cout << node->value << " ";
    dfs_in_order(node->right);
}

template <typename T>
void dfs_pre_order(Tree::Node<T>* node)
{
    if(node == nullptr){
        return;
    }
    std::cout << node->value << " ";
    dfs_pre_order(node->left);
    dfs_pre_order(node->right);
}

template <typename T>
void dfs_post_order(Tree::Node<T>* node)
{
    if(node == nullptr){
        return;
    }
    dfs_post_order(node->left);
    dfs_post_order(node->right);
    std::cout << node->value << " ";
}