#ifndef STACK_H
#define STACK_H
#include "palindromeNode.h"
#include <string>
using namespace std;

class stack{
    private:
        palindromeNode * top;
        string stringToCheck;
        int size;

    public:
        stack(string newString);
        ~stack();
        palindromeNode* getTop();
        void traverseStackRecursively(palindromeNode * nodeRunner);
        void checkIfPalindrome();
};

#endif