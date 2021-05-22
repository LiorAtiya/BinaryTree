#pragma once
#include <string>
#include <iostream>

using namespace std;
namespace ariel {

    template<typename T> 
    class Node {
        public:
            T value;
            Node<T>* right;
            Node<T>* left;
            Node():right(NULL),left(NULL) {}
    };  

    template<typename T> 
    class BinaryTree {
        
        private:

        
        public:

            Node<T> root;

            // BinaryTree():root(nullptr){} 
            BinaryTree<T>& add_root(T root);
            BinaryTree<T>& add_left(T exist, T value);
            BinaryTree<T>& add_right(T exist, T value);

            // class Iterator{
            //     Node<T>* p;

            //     public:
            //         Iterator(Node<T>* n):p(n){}

            //         Iterator& operator++ ();
            //         bool operator!= (Iterator const& other);
            //         T& operator*();
            //         string* operator->();
            // };

            // Iterator& begin_preorder();
            // Iterator& end_preorder();
            // Iterator& begin_inorder();
            // Iterator& end_inorder();
            // Iterator& begin_postorder();
            // Iterator& end_postorder();

            // Iterator& begin();
            // Iterator& end();

            // friend ostream& operator<< (ostream& os,BinaryTree& b);
    };
}
