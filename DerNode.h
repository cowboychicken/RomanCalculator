/*
        Aaron Im
        CS1337.002
        Project 5
        FALL2016
*/
#ifndef DERNODE_H
#define DERNODE_H

#include "BaseNode.h"

using namespace std;

class DerNode : public BaseNode {

private:
    DerNode *next;
    DerNode *prev;

public:
    //Constructors
    DerNode();
    DerNode(string);

    ~DerNode();

    //Accessors
    DerNode* getNext() const {return next;};
    DerNode* getPrev() const {return prev;};

    //Mutators
    void setNext(DerNode*);
    void setPrev(DerNode*);
};

#endif // DERNODE_H
