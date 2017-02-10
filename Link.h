/*
        Aaron Im
        CS1337.002
        Project 5
        FALL2016
*/
#ifndef LINK_H
#define LINK_H
#include <DerNode.h>
#include <fstream>

using namespace std;

class Link{

private:
    DerNode *head;
    DerNode *tail;

public:
                                                                                                    //Constructors
    Link();

    ~Link();

                                                                                                    //Accessors
    DerNode* getHead() const {return head;};
    DerNode* getTail() const {return tail;};

                                                                                                    //Mutators
    void setHead(DerNode*);
    void setTail(DerNode*);

                                                                                                    //Overloaded operators
    void operator += (DerNode*);
    void operator -- ();
    void operator -- (int );

    void printFile();
    void bubbleSort();
    int binarySearch(int);
    int getLength(DerNode*);
    void deleteAny(int);
};





#endif /*__LINK_H__*/
