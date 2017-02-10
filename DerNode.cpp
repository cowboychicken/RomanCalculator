/*
        Aaron Im
        CS1337.002
        Project 5
        FALL2016
*/
#include "DerNode.h"

DerNode::DerNode():BaseNode() {                                                             //Default constructor sets both ptrs to null
    next = nullptr;
    prev = nullptr;
}

DerNode::DerNode(string letters) : BaseNode(letters) {                                      //Calls basenode default constructor and passes string
    next = nullptr;
    prev = nullptr;
}

DerNode::~DerNode(){
    delete next;
    delete prev;
}

void DerNode::setNext(DerNode* x){
    next = x;
}

void DerNode::setPrev(DerNode* y){
    prev = y;
}
