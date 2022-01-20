#include "stack.h"

int main(){
    stack * NewStack = new stack("rotorr");
    NewStack->traverseStackRecursively(NewStack->getTop());
    NewStack->checkIfPalindrome();
    delete NewStack;
    return 0;
}