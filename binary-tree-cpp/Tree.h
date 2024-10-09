#include <vector>
#include <queue>
#include <limits>

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
bool is_bst_util(Tree::Node<T>* root, T lower_bound, T upper_bound)
{
    if(root == nullptr) return true;
    if(root->value >= lower_bound && root->value <= upper_bound){
        return is_bst_util(root->left, lower_bound, root->value)
                && is_bst_util(root->right, root->value, upper_bound);
    }
    
    return false;
}

template <typename T>
bool is_bst(Tree::Node<T>* root)
{
    return is_bst_util(root, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}

template <typename T>
Tree::Node<T>* find_min(Tree::Node<T>* root)
{
    if(root == nullptr){
        throw std::runtime_error("Tree is empty...");
    }
    auto current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}

template <typename T>
Tree::Node<T>* find_max(Tree::Node<T>* root)
{
    if(root == nullptr){
        throw std::runtime_error("Tree is empty...");
    }
    auto current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    return current;
}


template <typename T>
Tree::Node<T>* insert_node(Tree::Node<T>* root, T value_param)
{
    if(root == nullptr){
        auto newNode = new Tree::Node<T>();
        newNode->value = value_param;
        root = newNode;
    } else if (value_param < root->value){
        root->left = insert_node(root->left, value_param);
    } else {
        root->right = insert_node(root->right, value_param);
    }
    return root;
}

template <typename T>
Tree::Node<T>* delete_node(Tree::Node<T>* root, T value_param)
{
    if(root == nullptr) return root;
    else if(value_param < root->value) root->left = delete_node(root->left, value_param);
    else if(value_param > root->value) root->right = delete_node(root->right, value_param);
    else {
        // no child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        // one child
        else if(root->left == nullptr){
            auto temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr){
            auto temp = root;
            root = root->left;
            delete temp;
        }
        // two children
        else {
            Tree::Node<T>* temp = find_min(root->right);
            root->value = temp->value;
            root->right = delete_node(root->right,temp->value);
        }
    }
    return root;
}

// creates binary search tree
template <typename T>
Tree::Node<T>* create_tree(Tree::Node<T>* root, const std::vector<T>& values_param)
{
    for(const T& value : values_param){
        root = insert_node(root, value);
    }
    return root;
}

// creates complete binary tree
template <typename T>
Tree::Node<T>* create_tree(T arr[], int start, int end)
{
    if(start >= end){
        return nullptr;
    }

    Tree::Node<T>* root = new Tree::Node<T>();
    root->value = arr[start];

    int left_child_index = 2 * start + 1;
    int right_child_index = 2 * start + 2;

    if(left_child_index < end){
        root->left = create_tree<T>(arr, left_child_index, end);
    }
    if(right_child_index < end){ 
        root->right = create_tree<T>(arr, right_child_index, end);
    }

    return root;
}

template <typename T>
void delete_tree(Tree::Node<T>* node)
{
    if(node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template <typename T>
int find_height(Tree::Node<T>* node)
{
    if(node == nullptr) return 0;

    int left_height = find_height(node->left);
    int right_height = find_height(node->right);

    return std::max(left_height, right_height) + 1;
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

template <typename T>
void bfs_level_order(Tree::Node<T>* node)
{
    if(node == nullptr) return;

    std::queue<Tree::Node<T>*> discovered_nodes;

    discovered_nodes.push(node);
    while(!discovered_nodes.empty()){
        auto current = discovered_nodes.front();
        std::cout << current->value << " ";
        if(current->left != nullptr) discovered_nodes.push(current->left);
        if(current->right != nullptr) discovered_nodes.push(current->right);
        discovered_nodes.pop();
    }
}