#include "doctest.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>
#include<time.h>
#include <fstream>
#include <sstream>

using namespace std;
#include "BinaryTree.hpp"
using namespace ariel;

string random_string(const int len) {
    
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    // srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve((unsigned long)len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[(unsigned long)rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
    
}

char random_char(){
    return 'a' + rand()%26;
}

int random_int(){
    srand(time(0));
    return rand();
}

bool random_bool(){
    int randomBit = rand() % 2;
    if(randomBit == 0) return false;
    return true;
}

double random_double()
{
    static default_random_engine generator(unsigned(time(nullptr)));
    uniform_real_distribution<double> distribution(0, 100000);

    return distribution(generator);
}

TEST_CASE("Empty trees & Trees with just root (varies)"){
    BinaryTree<int> int_tree;
    BinaryTree<double> double_tree;
    BinaryTree<string> string_tree;
    BinaryTree<bool> bool_tree;
    BinaryTree<char> char_tree;

    for(int i=0 ; i < 10 ; i++){
        string rnd_string1 = random_string(i);
        string rnd_string2 = random_string(i);
        char rnd_char1 = random_char();
        char rnd_char2 = random_char();

        CHECK_THROWS(int_tree.add_left(i,i));
        CHECK_THROWS(int_tree.add_right(i,i));
        CHECK_THROWS(string_tree.add_left(rnd_string1,rnd_string1));
        CHECK_THROWS(string_tree.add_right(rnd_string2,rnd_string2));
        CHECK_THROWS(bool_tree.add_left(true,false));
        CHECK_THROWS(bool_tree.add_right(false,true));
        CHECK_THROWS(char_tree.add_left(rnd_char1,rnd_char1));
        CHECK_THROWS(char_tree.add_right(rnd_char2,rnd_char2));

        //---------Add root--------------
        int_tree.add_root(i);
        string_tree.add_root(rnd_string1);
        bool_tree.add_root(true);
        char_tree.add_root(rnd_char1);

        CHECK_NOTHROW(int_tree.add_left(i,i));
        CHECK_NOTHROW(int_tree.add_right(i,i));
        CHECK_NOTHROW(string_tree.add_left(rnd_string1,rnd_string1));
        CHECK_NOTHROW(string_tree.add_right(rnd_string1,rnd_string2));
        CHECK_NOTHROW(bool_tree.add_left(true,false));
        CHECK_NOTHROW(bool_tree.add_right(true,true));
        CHECK_NOTHROW(char_tree.add_left(rnd_char1,rnd_char1));
        CHECK_NOTHROW(char_tree.add_right(rnd_char1,rnd_char2));
    }
}

TEST_CASE("Random addition to trees"){
    BinaryTree<int> int_tree;
    BinaryTree<double> double_tree;
    BinaryTree<string> string_tree;
    BinaryTree<bool> bool_tree;
    BinaryTree<char> char_tree;

    //Add root to int_tree
    int rand_number = random_int();
    int rand_number2, prev_int;
    int_tree.add_root(rand_number);

    //Add root to string_tree
    string rand_string = random_string(10);
    string rand_string2, prev_string;
    string_tree.add_root(rand_string);

    //Add root bool_tree
    bool rand_bool = random_bool();
    bool prev_bool, rand_bool2;
    bool_tree.add_root(rand_bool);

    //Add root char_tree
    char rand_char = random_char();
    char prev_char, rand_char2;
    char_tree.add_root(rand_char);


    for(int i=0 ; i < 10 ; i++){
        //----Random int leaf------
        prev_int = rand_number;
        rand_number = random_int();
        rand_number2 = random_int();
        CHECK_NOTHROW(int_tree.add_left(prev_int,rand_number));
        CHECK_NOTHROW(int_tree.add_right(prev_int,rand_number2));

        //----Random string leaf-------
        prev_string = rand_number;
        rand_string = random_string(i);
        rand_string2 = random_string(i);
        CHECK_NOTHROW(string_tree.add_left(prev_string,rand_string));
        CHECK_NOTHROW(string_tree.add_right(rand_string,rand_string2));

        //----Random bool leaf-------
        prev_bool = rand_bool;
        rand_bool = random_bool();
        rand_bool2 = random_bool();
        CHECK_NOTHROW(bool_tree.add_left(prev_bool,prev_bool));
        CHECK_NOTHROW(bool_tree.add_right(prev_bool,rand_bool2));

        //----Random char leaf-------
        prev_char = rand_char;
        rand_char = random_char();
        rand_char2 = random_char();
        CHECK_NOTHROW(char_tree.add_right(prev_char,rand_char));
        CHECK_NOTHROW(char_tree.add_left(rand_char,rand_char2));
    }

}

TEST_CASE("Pre-order prints"){
    ostringstream actual;
    string expected = "";

    for(int i= 0 ; i < 10 ; i++){
        BinaryTree<int> int_tree;
        int root = random_int();
        int root_left = random_int();
        int root_left_left = random_int();
        int root_left_right = random_int();
        int root_right = random_int();
        int root_right_left = random_int();
        int root_right_right = random_int();

        expected = to_string(root) + " " + to_string(root_left) + " " +
                   to_string(root_left_left) + " " + to_string(root_left_right) + " " +
                   to_string(root_right) + " " + to_string(root_right_left) + " " + to_string(root_right_right);

        int_tree.add_root(root);
        int_tree.add_left(root,root_left).add_left(root_left,root_left_left)
        .add_right(root_left,root_left_right).add_right(root, root_right)
        .add_left(root_right,root_right_left).add_right(root_right,root_right_right);
        
        //Stream to actual
        for (auto it=int_tree.begin_preorder(); it!=int_tree.end_preorder(); ++it) {
            actual << (*it) << " " ;
        }
        
        CHECK(expected == actual.str());
        //Change value of root
        root = random_int();
        int_tree.add_root(root);
        CHECK_FALSE(expected == actual.str());
        expected.replace(0,to_string(root).size(),to_string(root));
        CHECK(expected == actual.str());

        expected = "";
        actual.str("");

        //String
        BinaryTree<string> string_tree;
        string s_root = random_string(i);
        string s_root_left = random_string(i);
        string s_root_left_left = random_string(i);
        string s_root_left_right = random_string(i);
        string s_root_right = random_string(i);
        string s_root_right_left = random_string(i);
        string s_root_right_right = random_string(i);

        expected = s_root + ' ' + s_root_left + ' ' +
                   s_root_left_left + ' ' + s_root_left_right + ' ' +
                   s_root_right + ' ' + s_root_right_left + ' ' + s_root_right_right;

        string_tree.add_root(s_root);
        string_tree.add_left(s_root,s_root_left).add_left(s_root_left,s_root_left_left)
        .add_right(s_root_left,s_root_left_right).add_right(s_root, s_root_right)
        .add_left(s_root_right,s_root_right_left).add_right(s_root_right,s_root_right_right);

        //Stream to actual
        for (auto it=string_tree.begin_preorder(); it!=string_tree.end_preorder(); ++it) {
            actual << (*it) << " " ;
        }

        CHECK(expected == actual.str());
        //Change value of root
        s_root = random_string(i);
        string_tree.add_root(s_root);
        CHECK_FALSE(expected == actual.str());
        expected.replace(0,s_root.size(),s_root);
        CHECK(expected == actual.str());
    }

}

TEST_CASE("In-order prints"){
    ostringstream actual;
    string expected = "";

    for(int i= 0 ; i < 10 ; i++){
        BinaryTree<int> int_tree;
        int root = random_int();
        int root_left = random_int();
        int root_left_left = random_int();
        int root_left_right = random_int();
        int root_right = random_int();
        int root_right_left = random_int();
        int root_right_right = random_int();

        expected = to_string(root_left_left) + " " + to_string(root_left) + " " +
                   to_string(root_left_right) + " " + to_string(root) + " " +
                   to_string(root_right_left) + " " + to_string(root_right) + " " + to_string(root_right_right);

        int_tree.add_root(root);
        int_tree.add_left(root,root_left).add_left(root_left,root_left_left)
        .add_right(root_left,root_left_right).add_right(root, root_right)
        .add_left(root_right,root_right_left).add_right(root_right,root_right_right);

        for (auto it=int_tree.begin_inorder(); it!=int_tree.end_inorder(); ++it) {
          actual << (*it) << " " ;
        }  

        CHECK(expected == actual.str());
        //Change value of root
        root = random_int();
        int_tree.add_root(root);
        CHECK_FALSE(expected == actual.str());
        expected.replace(0,to_string(root).size(),to_string(root));
        CHECK(expected == actual.str());

        expected = "";
        actual.str("");

        //String
        BinaryTree<char> char_tree;
        char c_root = random_char();
        char c_root_left = random_char();
        char c_root_left_left = random_char();
        char c_root_left_right = random_char();
        char c_root_right = random_char();
        char c_root_right_left = random_char();
        char c_root_right_right = random_char();

        expected = c_root_left_left + ' ' + c_root_left + ' ' +
                   c_root_left_right + ' ' + c_root + ' ' +
                   c_root_right_left + ' ' + c_root_right + ' ' + c_root_right_right;

        char_tree.add_root(c_root);
        char_tree.add_left(c_root,c_root_left).add_left(c_root_left,c_root_left_left)
        .add_right(c_root_left,c_root_left_right).add_right(c_root, c_root_right)
        .add_left(c_root_right,c_root_right_left).add_right(c_root_right,c_root_right_right);

        for (auto it=char_tree.begin_inorder(); it!=char_tree.end_inorder(); ++it) {
          actual << (*it) << " " ;
        }
        
        CHECK(expected == actual.str());
        //Change value of root
        c_root = random_char();
        char_tree.add_root(c_root);
        CHECK_FALSE(expected == actual.str());
        string s_root = "";
        s_root += c_root;
        expected.replace(0,1,s_root);
        CHECK(expected == actual.str());
    }
}

TEST_CASE("Post-order prints"){
    ostringstream actual;
    string expected = "";

    for(int i= 0 ; i < 10 ; i++){
        BinaryTree<int> int_tree;
        int root = random_int();
        int root_left = random_int();
        int root_left_left = random_int();
        int root_left_right = random_int();
        int root_right = random_int();
        int root_right_left = random_int();
        int root_right_right = random_int();

        expected = to_string(root_left_left) + " " + to_string(root_left_right) + " " +
                   to_string(root_left) + " " + to_string(root_right_left) + " " +
                   to_string(root_right_right) + " " + to_string(root_right) + " " + to_string(root);

        int_tree.add_root(root);
        int_tree.add_left(root,root_left).add_left(root_left,root_left_left)
        .add_right(root_left,root_left_right).add_right(root, root_right)
        .add_left(root_right,root_right_left).add_right(root_right,root_right_right);

        for (auto it=int_tree.begin_postorder(); it != int_tree.end_postorder(); ++it) {
             actual << (*it) << " " ;
        }  

        CHECK(expected == actual.str());
        //Change value of root
        root = random_int();
        int_tree.add_root(root);
        CHECK_FALSE(expected == actual.str());
        expected.replace(0,to_string(root).size(),to_string(root));
        CHECK(expected == actual.str());

        expected = "";
        actual.str("");

        //String
        BinaryTree<string> string_tree;
        string s_root = random_string(i);
        string s_root_left = random_string(i);
        string s_root_left_left = random_string(i);
        string s_root_left_right = random_string(i);
        string s_root_right = random_string(i);
        string s_root_right_left = random_string(i);
        string s_root_right_right = random_string(i);

        expected = s_root_left_left + " " + s_root_left_right + " " +
                   s_root_left + " " + s_root_right_left + " " +
                   s_root_right_right + " " + s_root_right + " " + s_root;

        string_tree.add_root(s_root);
        string_tree.add_left(s_root,s_root_left).add_left(s_root_left,s_root_left_left)
        .add_right(s_root_left,s_root_left_right).add_right(s_root, s_root_right)
        .add_left(s_root_right,s_root_right_left).add_right(s_root_right,s_root_right_right);

        for (auto it=string_tree.begin_postorder(); it!=string_tree.end_postorder(); ++it) {
             actual << (*it) << " " ;
        }  

        CHECK(expected == actual.str());
        //Change value of root
        s_root = random_string(i);
        string_tree.add_root(s_root);
        CHECK_FALSE(expected == actual.str());
        expected.replace(0,s_root.size(),s_root);
        CHECK(expected == actual.str());
    }
}

TEST_CASE("Checks Foreach"){

    ostringstream actual;
    string expected = "";

    for(int i=0 ; i < 10 ; i++){
        
        //------Integer-----------
        BinaryTree<int> int_tree;
        int root = random_int();
        int root_left = random_int();
        int root_right = random_int();
        int_tree.add_root(root).add_left(root,root_left).add_right(root, root_right);
        //Change left and right
        int_tree.add_left(root,root_right).add_right(root, root_left);
        expected = to_string(root_right) + " " + to_string(root) + " " + to_string(root_left);
        for(int i_t : int_tree){
            actual << to_string(i_t) << " ";
        }
        CHECK(actual.str() == expected);
        
        expected = "";
        actual.str("");

        //-----------Double---------------
        BinaryTree<double> double_tree;
        double d_root = random_double();
        double d_root_left = random_double();
        double d_root_right = random_double();
        double_tree.add_root(d_root).add_left(d_root,d_root_left).add_right(d_root, d_root_right);
         //Change left and right
        int_tree.add_left(d_root,d_root_right).add_right(d_root, d_root_left);
        expected = to_string(d_root_right) + " " + to_string(d_root) + " " + to_string(d_root_left);

        for(double d_t : double_tree){
            actual << to_string(d_t) << " ";
        }
        CHECK(actual.str() == expected);

        expected = "";
        actual.str("");

        //-----------string---------------
        BinaryTree<string> string_tree;
        string s_root = random_string(i);
        string s_root_left = random_string(i);
        string s_root_right = random_string(i);
        string_tree.add_root(s_root).add_left(s_root,s_root_left).add_right(s_root,s_root_right);
        //Change left and right
        string_tree.add_left(s_root,s_root_right).add_right(s_root,s_root_left);
        expected = s_root_right + " " + s_root + " " + s_root_left;
    
        for(string s_t : string_tree){
            actual << s_t << " ";
        }
        CHECK(actual.str() == expected);
        
        expected = "";
        actual.str("");

        //-----------bool---------------
        BinaryTree<bool> bool_tree;
        bool b_root = random_int();
        bool b_root_left = random_int();
        bool b_root_right = random_int();
        bool_tree.add_root(b_root).add_left(b_root,b_root_left).add_right(b_root, b_root_right);
        //Change left and right
        bool_tree.add_left(b_root,b_root_right).add_right(b_root, b_root_left);
        expected = to_string(b_root_right) + " " + to_string(b_root) + " " + to_string(b_root_left);
        
        cout << boolalpha;
        for(bool b_t : bool_tree){
            actual << b_t << " ";
        }

        CHECK(actual.str() == expected);

        expected = "";
        actual.str("");

        //-----------char---------------
        BinaryTree<char> char_tree;
        char c_root = random_char();
        char c_root_left = random_char();
        char c_root_right = random_char();
        char_tree.add_root(root).add_left(root,root_left).add_right(root, root_right);
        //Change left and right
        char_tree.add_left(root,root_right).add_right(root, root_left);
        expected = c_root_right + ' ' + c_root + ' ' + c_root_left;
        for(int c_t : char_tree){
            actual << c_t << " ";
        }
        CHECK(actual.str() == expected);

    }
}

TEST_CASE("Prints the shape of the tree"){
    ostringstream actual;
    string expected = "";

    //String
    BinaryTree<string> string_tree;
    string_tree.add_root("A")
    .add_right("A","B")
    .add_left("A", "C")
    .add_right("C", "D")
    .add_left("C", "E");

    actual << string_tree;
    expected = "└──A\n    ├──B\n    └──C\n        ├──D\n        └──E";
    CHECK(actual.str() == expected);

    //Integer
    BinaryTree<int> int_tree;
    string_tree.add_root("1")
    .add_right("1","2")
    .add_left("1", "3")
    .add_right("3", "4")
    .add_left("3", "5");

    actual << string_tree;
    string ac = actual.str();
    expected = "└──1\n    ├──2\n    └──3\n        ├──4\n        └──5";
    CHECK(actual.str() == expected);
}

