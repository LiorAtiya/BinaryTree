// #include "BinaryTree.hpp"
// using namespace std;

// namespace ariel {


//     //----------Iterator---------------
//     // template<typename T> 
//     // void Iterator<T>::fill_preorder(Node<T>* root){
//     //     if(root != nullptr){
//     //         cout << root->value << " ";
//     //         this->list.push_back(5);
//     //         fill_preorder(root->left);
//     //         fill_preorder(root->right);
//     //     }
//     //     // // set_nodes_queue(root.value);
//     //     // if(root->left != nullptr){
//     //     //     fill_preorder(root->left);
//     //     // }else if(root->right != nullptr){
//     //     //     return fill_preorder(root->right);
//     //     // }
        
//     // }

//     // template<typename T> 
//     // void Iterator<T>::fill_inorder(Node<T>* root){
        
//     // }
//     // template<typename T> 
//     // void Iterator<T>::fill_postorder(Node<T>* root){

//     // }

//     // template<typename T> 
//     // Iterator<T>& Iterator<T>::operator++ (){
//     //     this->p = this->nodes_queue.pop();
//     //     return *this;
//     // }

//     // template<typename T>
//     // bool Iterator<T>::operator!= (Iterator const& other){
//     //     return other.p != this->p;
//     // }

//     // template<typename T>
//     // T& Iterator<T>::operator*(){

//     // }


//     // //---------------Binary tree---------------------

//     // template<typename T>
//     // Node<T>* search(Node<T>* node,T data){
        
//     //     if(node == NULL) return NULL;
//     //     if(node->value == data) return node; 

//     //     Node<T>* n = search(node->left, data);
//     //     if(n) return n;

//     //     Node<T>* n2 = search(node->right, data);
        
//     //     return n2;
//     // }
    
//     // template<typename T>
//     // BinaryTree<T>& BinaryTree<T>::add_root(T root){
//     //     //if the tree is empty
//     //     if(this->root == nullptr){
//     //         this->root = new Node<T>;
//     //     }
//     //     this->root->value = root;
//     //     return *this;
//     // }

//     // template<typename T>
//     // BinaryTree<T>& BinaryTree<T>::add_left(T exist, T value){
//     //     Node<T>* n = search((this->root), exist);
//     //     if(!n){
//     //         throw invalid_argument("Error!");
//     //     }
//     //     if(!n->left){
//     //         n->left = new Node<T>();
//     //     }
//     //     n->left->value = value;

//     //     return *this;
//     // }

//     // template<typename T>
//     // BinaryTree<T>& BinaryTree<T>::add_right(T exist, T value){
//     //     Node<T>* n = search((this->root), exist);
//     //     if(!n){
//     //         throw invalid_argument("Error!");
//     //     }
//     //     if(!n->right){
//     //         n->right = new Node<T>();
//     //     }
//     //     n->right->value = value;

//     //     return *this;
//     // }

//     // template<typename T>
//     // void printBT(const string& prefix, Node<T>* node, bool isLeft)
//     // {
//     //     if( node != nullptr )
//     //     {
//     //         cout << prefix;
//     //         cout << (isLeft ? "├──" : "└──" );

//     //         // print the value of the node
//     //         cout << node->value << endl;

//     //         // enter the next tree level - left and right branch
//     //         printBT( prefix + (isLeft ? "│   " : "    "), node->right, true);
//     //         printBT( prefix + (isLeft ? "│   " : "    "), node->left, false);
//     //     }
//     // }

//     // template<typename T>
//     // ostream& operator<< (ostream& os,BinaryTree<T>& b){
//     //     printBT("", b.root, false);
//     //     return os;
//     // }

//     // template<typename T>
//     // Iterator<T>& BinaryTree<T>::begin_preorder(){
//     //     Iterator<T>* pre(this->root);
//     //     // pre->fill_preorder(&this->root);
//     //     return *pre;
//     // }
    
//     // template<typename T>
//     // Iterator<T>& BinaryTree<T>::end_preorder(){
//     //     Iterator<T>* pre;
//     //     return *pre;
//     // }

//     // template<typename T>
//     // Iterator<T>& BinaryTree<T>::begin_inorder(){
//     //     Iterator<T>* pre;
//     //     return *pre;
//     // }

//     // template<typename T>
//     // Iterator<T>& BinaryTree<T>::end_inorder(){
//     //     Iterator<T>* pre;
//     //     return *pre;
//     // }

//     // template<typename T>
//     // Iterator<T>& BinaryTree<T>::begin_postorder(){
//     //     Iterator<T>* pre;
//     //     return *pre;
//     // }

//     // template<typename T>
//     // Iterator<T>& BinaryTree<T>::end_postorder(){
//     //     Iterator<T>* pre;
//     //     return *pre;
//     // }

//     // template<typename T>
//     // Iterator<T>& BinaryTree<T>::begin(){
//     //     Iterator<T>* pre;
//     //     return *pre;
//     // }

//     // template<typename T>
//     // Iterator<T>& BinaryTree<T>::end(){
//     //     Iterator<T>* pre;
//     //     return *pre;
//     // }

//     // template ostream& operator<< (ostream& os,BinaryTree<int>& b);
//     // template ostream& operator<< (ostream& os,BinaryTree<string>& b);
//     // template ostream& operator<< (ostream& os,BinaryTree<char>& b);
//     // template ostream& operator<< (ostream& os,BinaryTree<bool>& b);
//     // template ostream& operator<< (ostream& os,BinaryTree<double>& b);
//     // template class BinaryTree<string>;
//     // template class BinaryTree<int>;
//     // template class BinaryTree<double>;
//     // template class BinaryTree<bool>;
//     // template class BinaryTree<char>;

// }

