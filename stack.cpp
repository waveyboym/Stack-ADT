#include "stack.h"
#include "palindromeNode.h"
#include <iostream>
using namespace std;

stack::stack(string newString){
    this->size = 0;
    this->stringToCheck = newString;

    for(int i = 0; i < newString.length(); ++i){
        if(this->top == NULL){
            this->top = new palindromeNode(newString[i]);
            ++this->size;
        }
        else if(this->top != NULL){
            palindromeNode * nodePtr = new palindromeNode(newString[i]);
            nodePtr->below = this->top;
            this->top = nodePtr;
            ++this->size;
        }
    }
}

stack::~stack(){
    palindromeNode * nodePtr = this->top;
    while(nodePtr != NULL){
        this->top = this->top->below;
        delete nodePtr;
        nodePtr = NULL;
        nodePtr = this->top;
    }
}

palindromeNode* stack::getTop(){
    return this->top;
}

void stack::traverseStackRecursively_OutputfromBottom(palindromeNode * nodeRunner){
    if(nodeRunner->below != NULL){
        traverseStackRecursively_OutputfromBottom(nodeRunner->below);
    }

    cout << "from bottom to top recursive data output: " << nodeRunner->data << endl;
}

void stack::traverseStackRecursively_OutputfromTop(palindromeNode * nodeRunner){
    cout << "from top to down recursive data output: " << nodeRunner->data << endl;
    if(nodeRunner->below != NULL){
        traverseStackRecursively_OutputfromTop(nodeRunner->below);
    }
}

void stack::checkIfPalindrome(palindromeNode * nodeRunner, int indexAt){
    if(nodeRunner->data == stringToCheck[indexAt]){
        if(nodeRunner->below == NULL){
            cout << "the word is a palindrome" << endl;
        }
        else if(nodeRunner->below != NULL){
            checkIfPalindrome(nodeRunner->below, indexAt + 1);
        }
    }
    else if(nodeRunner->data != stringToCheck[indexAt]){
        cout << "the word is not a palindrome" << endl;
    }
}