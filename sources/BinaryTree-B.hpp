#pragma once
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
namespace ariel {
    
    //Nodes for binary tree
    template<typename T> 
    class Node {
        public:
            T value;
            Node* right;
            Node* left;
            Node():right(nullptr),left(nullptr) {}
    };  

    template<typename T> 
    class BinaryTree {
        
        private:
            Node<T>* root;
            void release_nodes(Node<T>* root){
                if(root != nullptr){
                    release_nodes(root->right);
                    release_nodes(root->left);
                    delete root;
                }
            }

        public:
            BinaryTree():root(nullptr){}
            ~BinaryTree(){ release_nodes(this->root); } 

            //Auxiliary function for adding nodes
            Node<T>* search(Node<T>* node,T data){
                if(node == nullptr) return nullptr;
                if(node->value == data) return node; 

                Node<T>* n = search(node->left, data);
                if(n) return n;

                Node<T>* n2 = search(node->right, data);
                
                return n2;
            }

            BinaryTree<T>& add_root(T root_node){
                //if the tree is empty
                if(this->root == nullptr){
                    this->root = new Node<T>();
                }
                this->root->value = root_node;
                return *this;
            }

            BinaryTree<T>& add_left(T parent, T child){
                Node<T>* n = search((this->root), parent);
                if(!n){
                    throw invalid_argument("There is no parent to attach to him!");
                }
                if(!n->left){
                    n->left = new Node<T>();
                }
                n->left->value = child;
                return *this;
            }

            BinaryTree<T>& add_right(T parent, T child){
                Node<T>* n = search((this->root), parent);
                if(!n){
                    throw invalid_argument("There is no parent to attach to him!");
                }
                if(!n->right){
                    n->right = new Node<T>();
                }
                n->right->value = child;
                return *this;
            }


            //------Iterators-------
            class Iterator{
                private:
                    void fill_preorder(Node<T>* root){
                        if(root == nullptr){
                            return;
                        }
                        this->list_nodes.push_back(root);
                        fill_preorder(root->left);
                        fill_preorder(root->right);
                        
                    }

                    void fill_inorder(Node<T>* root){
                        if(root == nullptr){
                            return;
                        }
                        fill_inorder(root->left);
                        this->list_nodes.push_back(root);
                        fill_inorder(root->right);
                    }
                    void fill_postorder(Node<T>* root){

                        if(root == nullptr){
                            return;
                        }
                        fill_postorder(root->left);
                        fill_postorder(root->right);
                        this->list_nodes.push_back(root);
                    }

                public:
                    vector <Node<T>*> list_nodes;
                    Node<T>* current;

                    Iterator(Node<T>* root, int type){
                        if(type == 1){
                            fill_preorder(root);
                            current = list_nodes[0];
                        }else if(type == 2){
                            fill_inorder(root);
                            current = list_nodes[0];
                        }else if(type == 3){
                            fill_postorder(root);
                            current = list_nodes[0];
                        }
                    }

                    Iterator& operator++(){
                        if(list_nodes.size() > 1){
                            this->list_nodes.erase(list_nodes.begin());
                            this->current = list_nodes[0];
                        }else{
                            this->current = nullptr;
                        }
                        return *this;
                    }

                    bool operator!= (Iterator other){
                        return this->current != nullptr;
                    }

                    T& operator*(){
                        return this->current->value;
                    }
                    T* operator->(){
                        return &this->current->value;
                    }
            };

            Iterator begin_preorder(){
                return Iterator{this->root, 1};
            }
            Iterator end_preorder(){
                return Iterator{this->root, 1};
            }

            Iterator begin_inorder(){
                return Iterator{this->root, 2};
            }

            Iterator end_inorder(){
                return Iterator{this->root, 2};
            }

            Iterator begin_postorder(){
                return Iterator{this->root, 3};
            }

            Iterator end_postorder(){
                return Iterator{this->root, 3};
            }

            Iterator begin(){
                return Iterator{this->root, 2};
            }
            Iterator end(){
                return Iterator{this->root, 2};
            }

            //Print the tree
            static void printBT(const string& prefix, Node<T>* node, bool isLeft)
            {
                if( node != nullptr )
                {
                    cout << prefix;
                    cout << (isLeft ? "├──" : "└──" );

                    // print the value of the node
                    cout << node->value << endl;

                    // enter the next tree level - left and right branch
                    printBT( prefix + (isLeft ? "│   " : "    "), node->right, true);
                    printBT( prefix + (isLeft ? "│   " : "    "), node->left, false);
                }
            }

            friend ostream& operator<< (ostream& os,BinaryTree<T> const& b){
                BinaryTree<T>::printBT("", b.root, false);
                return os;
            }

    };
}


            //////////////////////////////////////////////////////////

            // BinaryTree<T>& add_root(T root_node){
            //     //if the tree is empty
            //     if(this->root == nullptr){
            //         this->root = new Node<T>;
            //     }
            //     this->root->value = root_node;
            //     return *this;
            // }

            // //Auxiliary function for adding nodes
            // Node<T>* search(Node<T>* node,T data){
        
            //     if(node == NULL) return NULL;
            //     if(node->value == data) return node; 

            //     Node<T>* n = search(node->left, data);
            //     if(n) return n;

            //     Node<T>* n2 = search(node->right, data);
                
            //     return n2;
            // }


            // BinaryTree<T>& add_left(T parent, T child){
            //     Node<T>* n = search((this->root), parent);
            //     if(!n){
            //         throw invalid_argument("Error!");
            //     }
            //     if(!n->left){
            //         n->left = new Node<T>();
            //     }
            //     n->left->value = child;

            //     return *this;
            // }

            // BinaryTree<T>& add_right(T parent, T child){
            //     Node<T>* n = search((this->root), parent);
            //     if(!n){
            //         throw invalid_argument("Error!");
            //     }
            //     if(!n->right){
            //         n->right = new Node<T>();
            //     }
            //     n->right->value = child;

            //     return *this;
            // }


             //------Iterators-------
            // class Iterator{
            //     private:
            //         // Node<T>  *m_pointer;
            //         // stack<Node<T>*> node_stk;

            //     public:

            //         vector <T> list;
            //         T current;

            //         Iterator(Node<T>* root, int type){
            //             //Preorder
            //             if(type == 1){
            //                 fill_preorder(root);
            //                 // current = list[0];
            //             }else if(type == 2){ //Inorder

            //             }else if(type == 3){ //Postorder

            //             }
            //             for(T in : list){
            //                 cout << in << "  ";
            //             }
            //         }
                    
            //         void fill_preorder(Node<T>* root){
            //             if(root != nullptr){
            //                 cout << root->value << " ";
            //                 // this->list.push_back(root->value);
            //                 fill_preorder(root->left);
            //                 fill_preorder(root->right);
            //             }
            //         }

            //         Iterator operator++(){
            //             if(list.size() > 0){
            //                 list.erase(list.begin());
            //                 current = list[0];
            //             }
            //             return *this;
            //             // Preorder_iterator &operator++() {
            //             //     if (!node_stk.empty()) {
            //             //         node_stk.pop();
            //             //         if (m_pointer->right != nullptr) {
            //             //             node_stk.push(m_pointer->right);
            //             //         }
            //             //         if (m_pointer->left != nullptr) {
            //             //             node_stk.push(m_pointer->left);
            //             //         }
            //             //         if (node_stk.empty()) {
            //             //             this->m_pointer = nullptr;
            //             //         } else {
            //             //             m_pointer = node_stk.top();
            //             //         }
            //             //     }
            //             //     if (node_stk.empty()) {
            //             //         this->m_pointer = nullptr;
            //             //     }
            //             //     return *this;
            //             // }
            //         }

            //         bool operator!= (Iterator other){
            //             return this->current != other.current;
            //         }

            //         T& operator*(){
            //             return this->current;
            //         }

            //         string* operator->(){
            //             string s = "5";
            //             string* size = &s;
            //             return size;
            //         }
            // };

            // class Preorder_iterator {
            //     private:
            //         Node<T>  *m_pointer;
            //         stack<Node<T>*> node_stk;
            //     public:
            //         explicit Preorder_iterator(Node<T>  *pNode = nullptr):m_pointer(pNode) {
            //             this->node_stk.push(pNode);
            //         };
            //         T &operator*() const {
            //             return this->m_pointer->value;
            //         }

            //         T *operator->() const {
            //             return &(this->m_pointer->value);
            //         }

            //         Preorder_iterator &operator++() {
            //             if (!node_stk.empty()) {
            //                 node_stk.pop();
            //                 if (m_pointer->right != nullptr) {
            //                     node_stk.push(m_pointer->right);
            //                 }
            //                 if (m_pointer->left != nullptr) {
            //                     node_stk.push(m_pointer->left);
            //                 }
            //                 if (node_stk.empty()) {
            //                     this->m_pointer = nullptr;
            //                 } else {
            //                     m_pointer = node_stk.top();
            //                 }
            //             }
            //             if (node_stk.empty()) {
            //                 this->m_pointer = nullptr;
            //             }
            //             return *this;
            //         }

            //         const Preorder_iterator operator++(int) {
            //             const Preorder_iterator tmp = *this;
            //             ++*this;
            //             return tmp;
            //         }

            //         bool operator==(const Preorder_iterator &rhs) const {
            //             return rhs.m_pointer==this->m_pointer;
            //         }

            //         bool operator!=(const Preorder_iterator &rhs) const {
            //             return rhs.m_pointer!=this->m_pointer;
            //         }

            //         friend std::ostream &operator<<(std::ostream &os, const Preorder_iterator &node) { return os; }
            // };

            // Preorder_iterator begin_preorder(){
            //     return Preorder_iterator(root);
            // }
            // Preorder_iterator end_preorder(){
            //     return  Preorder_iterator();
            // }

            // Iterator begin_preorder(){
            //     return Iterator(this->root, 1);
            // }
            // Iterator end_preorder(){
            //     return Iterator(this->root, 1);
            // }

            // Iterator<T>& begin_inorder();
            // Iterator<T>& end_inorder();
            // Iterator<T>& begin_postorder();
            // Iterator<T>& end_postorder();

            // Iterator<T>& begin();
            // Iterator<T>& end();

            // //Print the tree
            // static void printBT(const string& prefix, Node<T>* node, bool isLeft)
            // {
            //     if( node != nullptr )
            //     {
            //         cout << prefix;
            //         cout << (isLeft ? "├──" : "└──" );

            //         // print the value of the node
            //         cout << node->value << endl;

            //         // enter the next tree level - left and right branch
            //         printBT( prefix + (isLeft ? "│   " : "    "), node->right, true);
            //         printBT( prefix + (isLeft ? "│   " : "    "), node->left, false);
            //     }
            // }

            // friend ostream& operator<< (ostream& os,BinaryTree<T>& b){
            //     BinaryTree<T>::printBT("", b.root, false);
            //     return os;
            // }

    // };

    // template<typename T>
    // BinaryTree<T>::~BinaryTree(){
    //     delete_tree(this->root);
    // }


    // template<typename T>
    // void BinaryTree<T>::delete_tree(Node<T> *other) {
    //     if(other!= nullptr){
    //         delete_tree(other->right);
    //         delete_tree(other->left);
    //         delete other;
    //     }
    // }
