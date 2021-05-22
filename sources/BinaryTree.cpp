#include "BinaryTree.hpp"
using namespace std;

namespace ariel {

    template<typename T>
    Node<T>* search(Node<T>* node,T data){
        
        if(node == NULL) return NULL;
        if(node->value == data) return node; 

        Node<T>* n = search(node->left, data);
        if(n) return n;

        Node<T>* n2 = search(node->right, data);
        
        return n2;
    }
    
    template<typename T>
    BinaryTree<T>& BinaryTree<T>::add_root(T root){
        this->root.value = root;
        return *this;
    }

    template<typename T>
    BinaryTree<T>& BinaryTree<T>::add_left(T exist, T value){
        Node<T>* n = search((&this->root), exist);
        if(!n){
            throw invalid_argument("Error!");
        }
        if(!n->left){
            n->left = new Node<T>();
        }
        n->left->value = value;

        return *this;
    }

    template<typename T>
    BinaryTree<T>& BinaryTree<T>::add_right(T exist, T value){
        Node<T>* n = search((&this->root), exist);
        if(!n){
            throw invalid_argument("Error!");
        }
        if(!n->right){
            n->right = new Node<T>();
        }
        n->right->value = value;

        return *this;
    }

    template class BinaryTree<int>;
    template class BinaryTree<string>;
}

