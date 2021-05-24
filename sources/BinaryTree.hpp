#pragma once
#include <string>
#include <queue>
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
            ~Node() { delete left; delete right; }
    };  

    template<typename T> 
    class Iterator{
        private:
            queue <Node<T>*> nodes_queue;
            Node<T>* p;
        
        public:
            Iterator(Node<T>* n):p(n){}
            void fill_preorder();
            void fill_inorder();
            void fill_postorder();

            Iterator<T>& operator++(){
                this->p = this->nodes_queue.front();
                this->nodes_queue.pop();
                return *this;
            }

            bool operator!= (Iterator const& other){
                return other.p != this->p;
            }

            T& operator*(){
                return this->p->value;
            }

            string* operator->(){
                string s = "5";
                string* size = &s;
                return size;
            }
    };

    template<typename T> 
    class BinaryTree {
        
        private:
            Node<T> root;

        public:

            BinaryTree<T>& add_root(T root);
            BinaryTree<T>& add_left(T exist, T value);
            BinaryTree<T>& add_right(T exist, T value);

            Iterator<T>& begin_preorder();
            Iterator<T>& end_preorder();
            Iterator<T>& begin_inorder();
            Iterator<T>& end_inorder();
            Iterator<T>& begin_postorder();
            Iterator<T>& end_postorder();

            Iterator<T>& begin();
            Iterator<T>& end();

            template<typename U>
            friend ostream& operator<< (ostream& os,BinaryTree<U>& b);

    };
}
