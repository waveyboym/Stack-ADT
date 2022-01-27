#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    stack * NewStack = new stack("hello");
    cout << NewStack->getTop() << endl;
    NewStack->traverseStackRecursively_OutputfromTop(NewStack->getTop());
    NewStack->checkIfPalindrome(NewStack->getTop(), 0);
    cout << NewStack->getTop() << endl;
    delete NewStack;
    return 0;
}