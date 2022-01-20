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

void stack::traverseStackRecursively(palindromeNode * nodeRunner){
    if(nodeRunner->below != NULL){
        traverseStackRecursively(nodeRunner->below);
    }

    cout << "recursive data output: " << nodeRunner->data << endl;
}

void stack::checkIfPalindrome(){
    
    palindromeNode * nodePtr = this->top;
    int i = 0;
    while(nodePtr != NULL){
        if(nodePtr->data == this->stringToCheck[i]){
            nodePtr = nodePtr->below;
            ++i;
            continue;
        }
        else if(nodePtr->data != this->stringToCheck[i]){
            cout << "The string is not a palindrome" << endl;
            break;
        }
    }

    if(i == this->stringToCheck.length()){
        cout << "The string is a palindrome" << endl;
    }
}