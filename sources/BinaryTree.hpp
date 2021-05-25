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
            Node<T>* right;
            Node<T>* left;
            Node():right(nullptr),left(nullptr) {}
            ~Node() { delete left; delete right; }
    };  

    template<typename T> 
    class BinaryTree {
        
        private:
            Node<T>* root;
            // void delete_tree(Node<T> *other);
        public:

            BinaryTree():root(nullptr){}
            ~BinaryTree(){ delete root; } 

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
                    this->root = new Node<T>;
                }
                this->root->value = root_node;
                return *this;
            }

            BinaryTree<T>& add_left(T parent, T child){
                Node<T>* n = search((this->root), parent);
                if(!n){
                    throw invalid_argument("Error!");
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
                    throw invalid_argument("Error!");
                }
                if(!n->right){
                    n->right = new Node<T>();
                }
                n->right->value = child;

                return *this;
            }


            //------Iterators-------
            class Iterator{

                public:
                    vector <Node<T>*> list;
                    Node<T>* current;

                    Iterator(Node<T>* root = nullptr){}
                    
                    void fill_preorder(Node<T>* root);
                    void fill_inorder(Node<T>* root);
                    void fill_postorder(Node<T>* root);

                    Iterator& operator++(){
                        return *this;
                    }
                    bool operator!= (Iterator other){
                        return false;
                    }
                    T& operator*(){
                        return this->current->value;
                    }
                    T* operator->(){
                        return &this->current->value;
                    }
            };

            Iterator begin_preorder(){
                return Iterator{this->root};
            }
            Iterator end_preorder(){
                return Iterator{this->root};
            }
            Iterator begin_inorder(){
                return Iterator{this->root};
            }
            Iterator end_inorder(){
                return Iterator{this->root};
            }
            Iterator begin_postorder(){
                return Iterator{this->root};
            }
            Iterator end_postorder(){
                return Iterator{this->root};
            }

            Iterator begin(){
                return Iterator{this->root};
            }
            Iterator end(){
                return Iterator{this->root};
            }

            friend ostream& operator<< (ostream& os,BinaryTree<T>& b){
                cout << "test";
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

// }

// #pragma once
// #include <iostream>
// #include <sstream>
// #include <stack>

// using namespace std;

// namespace ariel {
//     template<typename T>
//     class Node{
//     public:
//         T value;
//         Node* right;
//         Node* left;
//         Node():right(nullptr),left(nullptr) {}
//         // ~Node() { delete left; delete right; }

//         // T value;
//         // Node *left= nullptr;
//         // Node *right= nullptr;
//         // Node *parent= nullptr;
//         // explicit Node(T val=0, Node* left = nullptr,Node* parent = nullptr,Node* right = nullptr):left(left),right(right),parent(parent){
//         //     value = val;
//         // };
//         // bool operator==(const Node &rhs) const {
//         //     return rhs.value==this->value&&rhs.left==this->left&&rhs.right==this->right&&this->parent==rhs.parent;
//         // }

//         // bool operator!=(const Node &rhs) const {
//         //     return rhs.value!=this->value&&rhs.left!=this->left&&rhs.right!=this->right&&this->parent!=rhs.parent;
//         // }
// //            friend std::ostream& operator<<(std::ostream& os,const Node& node){return os;};
//     };

//     template<typename T>
//     class BinaryTree {
//     private:
//         Node<T> * root;
//         Node<T>* copy_ctor(Node<T>* other);
//         void delete_tree(Node<T>* leaf);
//     public:
//         BinaryTree<T>();
//         // BinaryTree<T>(BinaryTree* bt);
//         ~BinaryTree();

        
//         BinaryTree<T>& add_root(T val) {
//             //if the tree is empty
//             if(this->root == nullptr){
//                 this->root = new Node<T>();
//             }
//             this->root->value = val;
//             return *this;
//         }

//         BinaryTree<T> &add_left(T parent_val, T child_val){
//             Node<T>* n = find_node_by_val(this->root,parent_val);
//                 if(!n){
//                     throw invalid_argument("Error!");
//                 }
//                 if(!n->left){
//                     n->left = new Node<T>();
//                 }
//                 n->left->value = child_val;

//                 return *this;
//         }
        
//         BinaryTree<T> &add_right(T parent_val, T child_val){
//             Node<T>* n = find_node_by_val(this->root,parent_val);
//             if(!n){
//                 throw invalid_argument("Error!");
//             }
//             if(!n->right){
//                 n->right = new Node<T>();
//             }
//             n->right->value = child_val;

//             return *this;
//         }

//         /************************************* Operator Functions *************************************/
//         friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T>& binaryTree){
//             os<<"bla";
//             return os;
//         };
//         /************************************* Iterators *************************************/
//         class Postorder_iterator {
//         private:
//             Node<T>  *m_pointer;
//             std::stack<Node<T>*> node_stk;
//         public:
//             explicit Postorder_iterator( Node <T> *pNode = nullptr){
//                 if(pNode!= nullptr) {
//                     std::stack<Node<T> *> temp;
//                     temp.push(pNode);
//                     while (!temp.empty()) {
//                         Node <T>*node = temp.top();
//                         temp.pop();
//                         node_stk.push(node);
//                         if (node->left)
//                             temp.push(node->left);
//                         if (node->right)
//                             temp.push(node->right);
//                     }
//                     this->m_pointer = node_stk.top();
//                 }else{
//                     this->m_pointer= nullptr;
//                 }
//             }
//             explicit Postorder_iterator( std::stack<Node<T>*> node_stk){
//                 this->node_stk = node_stk;
//                 this->m_pointer = node_stk.top();
//             }
//             T &operator*() const {
//                 return this->m_pointer->value;
//             }
//             T *operator->() const {
//                 return &(this->m_pointer->value);
//             }
//             Postorder_iterator &operator++(){
//                 if(!node_stk.empty()) {
//                     this->node_stk.pop();
//                 }
//                 if(!node_stk.empty()) {
//                     this->m_pointer=this->node_stk.top();
//                 }else{
//                     this->m_pointer= nullptr;
//                 }
//                 return *this;
//             }
//             const Postorder_iterator operator++(int) {
//                 const Postorder_iterator tmp{this->node_stk};
//                 ++*this;
//                 return tmp;
//             }
//             bool operator==(const Postorder_iterator &rhs) const {
//                 return rhs.m_pointer==this->m_pointer;
//             }
//             bool operator!=(const Postorder_iterator &rhs) const {
//                 return rhs.m_pointer!=this->m_pointer;
//             }
//             friend std::ostream &operator<<(std::ostream &os, const Postorder_iterator &node) { return os; }
//         };
//         class Preorder_iterator {
//         private:
//             Node<T>  *m_pointer;
//             std::stack<Node<T>*> node_stk;
//         public:
//             explicit Preorder_iterator(Node<T>  *pNode = nullptr):m_pointer(pNode) {
//                 this->node_stk.push(pNode);
//             };
//             T &operator*() const {
//                 return this->m_pointer->value;
//             }

//             T *operator->() const {
//                 return &(this->m_pointer->value);
//             }

//             Preorder_iterator &operator++() {
//                 if (!node_stk.empty()) {
//                     node_stk.pop();
//                     if (m_pointer->right != nullptr) {
//                         node_stk.push(m_pointer->right);
//                     }
//                     if (m_pointer->left != nullptr) {
//                         node_stk.push(m_pointer->left);
//                     }
//                     if (node_stk.empty()) {
//                         this->m_pointer = nullptr;
//                     } else {
//                         m_pointer = node_stk.top();
//                     }
//                 }
//                 if (node_stk.empty()) {
//                     this->m_pointer = nullptr;
//                 }
//                 return *this;
//             }

//             const Preorder_iterator operator++(int) {
//                 const Preorder_iterator tmp = *this;
//                 ++*this;
//                 return tmp;
//             }

//             bool operator==(const Preorder_iterator &rhs) const {
//                 return rhs.m_pointer==this->m_pointer;
//             }

//             bool operator!=(const Preorder_iterator &rhs) const {
//                 return rhs.m_pointer!=this->m_pointer;
//             }

//             friend std::ostream &operator<<(std::ostream &os, const Preorder_iterator &node) { return os; }
//         };
//         class Inorder_iterator {
//         private:
//             Node<T>  *m_pointer;
//             std::stack<Node<T>*> node_stk;
//         public:
//             explicit Inorder_iterator(Node<T>  *pNode = nullptr){
//                 Node<T> *curr = pNode;
//                 while(curr!= nullptr){
//                     this->node_stk.push(curr);
//                     curr = curr->left;
//                 }
//                 if(this->node_stk.empty()){
//                     this->m_pointer= nullptr;
//                 }else{
//                     this->m_pointer = node_stk.top();
//                 }
//             };
//             T &operator*() const {
//                 return this->m_pointer->value;
//             }

//             T *operator->() const {
//                 return &(this->m_pointer->value);
//             }

//             Inorder_iterator &operator++() {
//                 if(!this->node_stk.empty()) {
//                     Node <T>*temp = this->node_stk.top();
//                     this->node_stk.pop();
//                     if (temp->right != nullptr) {
//                         this->node_stk.push(temp->right);
//                         temp = temp->right->left;
//                         while (temp != nullptr) {
//                             this->node_stk.push(temp);
//                             temp = temp->left;
//                         }
//                     }
//                     if(this->node_stk.empty()){
//                         this->m_pointer = nullptr;
//                     }else{
//                         this->m_pointer = this->node_stk.top();
//                     }
//                 }else{
//                     this->m_pointer = nullptr;
//                 }
//                 return *this;
//             }

//             const Inorder_iterator operator++(int) {
//                 const Inorder_iterator tmp = *this;
//                 ++*this;
//                 return tmp;
//             }

//             bool operator==(const Inorder_iterator &rhs) const {
//                 return rhs.m_pointer==this->m_pointer;
//             }

//             bool operator!=(const Inorder_iterator &rhs) const {
//                 return rhs.m_pointer!=this->m_pointer;
//             }

//             friend std::ostream &operator<<(std::ostream &os, const Inorder_iterator &node) { return os; }
//         };


//         Inorder_iterator begin(){
//             return begin_inorder();
//         };
//         Inorder_iterator end(){
//             return end_inorder();
//         };
//         Preorder_iterator begin_preorder(){
//             return Preorder_iterator(root);
//         }
//         Preorder_iterator end_preorder(){
//             return  Preorder_iterator();
//         }
//         Inorder_iterator begin_inorder(){
//             return Inorder_iterator(root);
//         }
//         Inorder_iterator end_inorder(){
//             return Inorder_iterator();
//         }
//         Postorder_iterator begin_postorder(){
//             return Postorder_iterator(root);
//         }
//         Postorder_iterator end_postorder(){
//             return Postorder_iterator();
//         }
//         /************************************* For Testing Functions *************************************/
//         bool has_value(T val);
//         Node<T> * find_node_by_val(Node<T> * node,T val){
//             if(node == nullptr){
//                 return nullptr;
//             }
//             if(val==node->value){
//                 return node;
//             }
//             Node<T>* left= nullptr,*right= nullptr;
//             if(node->left!= nullptr){
//                 left = find_node_by_val(node->left,val);
//             }
//             if(node->right!= nullptr){
//                 right = find_node_by_val(node->right,val);
//             }
//             if(left!= nullptr){
//                 return left;
//             }else{
//                 return right;
//             }
//         };

//         Node<T> * find_node_by_val(T val){
//             if(val==root->value){
//                 return root;
//             }
//             return find_node_by_val(root,val);
//         };
//     };

//     template<typename T>
//     bool BinaryTree<T>::has_value(T val) {
//         Node<T>* node =find_node_by_val(root,val);
//         return node!= nullptr;
//     }

//     template<typename T>
//     BinaryTree<T>::BinaryTree():root(nullptr) {
//     }

//     // template<typename T>
//     // BinaryTree<T>::BinaryTree(BinaryTree* bt) {
//     //     this->root = copy_ctor(bt->root);
//     // }

//     template<typename T>
//     BinaryTree<T>::~BinaryTree(){
//         delete_tree(this->root);
//     }


//     template<typename T>
//     void BinaryTree<T>::delete_tree(Node<T> *other) {
//         if(other!= nullptr){
//             delete_tree(other->right);
//             delete_tree(other->left);
//             delete other;
//         }
//     }

// }
