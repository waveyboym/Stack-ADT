#ifndef PALINDROMENODE_H
#define PALINDROMENODE_H
#include <string>
using namespace std;

class palindromeNode{
    public:
        palindromeNode * below;
        char data;
        palindromeNode(char newChar);
        ~palindromeNode();
};

#endif