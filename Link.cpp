/*
        Aaron Im
        CS1337.002
        Project 5
        FALL2016
*/
#include "Link.h"


Link::Link(){
    head = nullptr;
    tail = nullptr;
}

Link::~Link(){}

void Link::operator += (DerNode* right){

    if (!head){
        head = right;
        head->setPrev(nullptr);
        head->setNext(nullptr);
        return;
    }
    DerNode* cur = head;
    DerNode *prev = head;
    while(cur)   // 1 -> 2 -> 2 -> 4
    {
        prev = cur;
        cur = cur->getNext();
    }
    prev->setNext(right);
    right->setPrev(prev);
    right->setNext(nullptr);
    tail = right;
}

void Link::operator --(){        //prefix --LL
    head = head->getNext();
    head->setPrev(nullptr);
}

void Link::operator --(int){         //post-fix LL--
    tail = tail->getPrev();
    tail->setNext(nullptr);
}

void Link::printFile(){      //writes a list to a chosen file.
    bubbleSort();           //Call sort
    DerNode* cur;
    cur = head;
    int position;

    fstream output;
    output.open( "answers.txt" , ios::out | ios::trunc);
    output.seekg(0);

    if (head){
        if (cur->getNext()){

            while(cur->getNext()){

                position = output.tellg();
                output  << cur->getRoman();
                output.seekg( position);
                output.seekg(17 , ios::cur);
                output << cur->getArabic();
                output.seekg(position);
                output.seekg(22, ios::cur);
                output << '\n';
                cur = cur->getNext();
            }
            position = output.tellg();
            output  << cur->getRoman();
            output.seekg( position);
            output.seekg(17 , ios::cur);
            output << cur->getArabic();
            output.seekg(position);
            output.seekg(22, ios::cur);
        }
        else {
            position = output.tellg();
            output  << cur->getRoman();
            output.seekg( position);
            output.seekg(17 , ios::cur);
            output << cur->getArabic();
            output.seekg(position);
            output.seekg(22, ios::cur);
        }
    }
    else {return;}
}

void Link::bubbleSort(){
    DerNode* cur;
    cur = head;
    /////
    int length =0;              //captures size of list
    while ( cur->getNext()){
        cur = cur->getNext();
        length ++;
    }
    /////
    bool swap;
    DerNode* temp;

    do{
        swap = false;
        DerNode* prev;
        prev = head;

        if ( head->getArabic() > head->getNext()->getArabic()){    //compares first two nodes as the algorithm beneath skips the head.
            temp = head->getNext();
            head->setPrev(head->getNext());
            head->setNext(head->getNext()->getNext());
            temp->setNext(head);
            head = temp;
            head->setPrev(nullptr);
            swap = true;
        }
        else {
            for( int i=2 ; i<= length ; i++ ){
                     cur = prev->getNext();
                if (cur->getArabic() > cur->getNext()->getArabic() )  { //if value in front is lesser, then nodes will be rearranged.

                    temp = cur->getNext();
                    cur->setPrev(cur->getNext());
                    temp->setPrev(prev);
                    if (cur->getNext()->getNext()  ){
                    cur->getNext()->getNext()->setPrev(  cur );
                    }
                    cur->setNext(cur->getNext()->getNext());

                    temp->setNext(cur);
                    prev->setNext(temp);
                    swap = true;
                }
            prev = prev->getNext();
            }
        }
    } while (swap);
    /////////////////
                                //traverse to end and marks tail end
    cur = head;
    while ( cur->getNext()){
        cur = cur->getNext();
    }
    tail = cur;
    /////
}

int Link::getLength(DerNode* head){                         //captures size of list
    int length =0;
    DerNode* cur;
    cur = head;
    while ( cur->getNext()){            //traverses through and adds to a counter to keep track of length
        cur = cur->getNext();
        length ++;
    }
    return length;
}

int Link::binarySearch ( int x){           //returns 1 if 'int' is found in list. search for x
    Link headcopy;
    DerNode* cur;
    cur = head;
     /////
    int length =0;          //captures size of list
    while ( cur->getNext()){
        cur = cur->getNext();
        length ++;
    }
    /////
    cur = head;
    for( int i =0 ; i <= getLength(head); i++){     //Creates copy of current list so that it wont be altered after search.
        string y = cur->getRoman();
        DerNode * nodecopy = new DerNode(y);
        headcopy += nodecopy;
         cur = cur->getNext();
    }
    /////////////////////

    DerNode* head1;
    DerNode* head2;
    DerNode* temp;
    head1 = headcopy.getHead();
    head2 = headcopy.getHead();

    int found;
    found =0;

    for (int i =0; i <= length; i+=2 ){
        head2= head2->getNext();
    }
    if ( x == head1->getArabic() ){
        found = 1;
        return found;
    }
    else {
        do {
            if ( x == head2->getArabic()  ){                    // checks if new midpoint is equal to value in question
                found = 1;
                return found;
            }
            else if ( x > head2->getArabic()){                // if x is greater than midpoint, delete first half of list by moving front ptr to mid

                head1 = head2;
                for (int i =1; i <= getLength(head1); i +=2){
                    head2 = head2->getNext();
                }
            }
            else if ( x < head2->getArabic()){            //if x is less than midpoint, make midpoint point to nullptr set new midpoint
                head2->setNext(nullptr);
                head2 = head1;
                for (int i = 2; i <= getLength(head1) ; i+=2){
                    head2 = head2 ->getNext();
                }
            }
        }while (  (head2->getNext() != 0 )  );

    if ( x == head2->getArabic()){
                found = 1;
                return found;
            }
    }
    return found;
}



void Link::deleteAny (int x){

    if (binarySearch(x) == 1){
        //traverse and delete.
        DerNode* cur;
        cur = head;
        /////
        int length =0;              //captures size of list
        while ( cur->getNext()){
            cur = cur->getNext();
            length ++;
        }
        /////

        DerNode* prev;
            prev = head;
        do{
            if ( head->getArabic() == x){    //compares first  node to int X
                head = head->getNext();
                head->setPrev(nullptr);
                cout << x << " has been removed from the list." << endl << endl;
                return;
            }
            else {
                for( int i=2 ; i<= length ; i++ ){
                    cur = prev->getNext();
                        if (cur->getArabic() == x )  {

                            if (cur->getNext() == nullptr){
                                prev->setNext(nullptr);
                                tail = prev;
                                cout << x << " has been removed from the list." << endl << endl;
                                return;
                            }
                            prev->setNext(cur->getNext() ) ;
                            cur->getNext()->setPrev(prev);
                            cout << x << " has been removed from the list." << endl << endl;
                            return;
                        }
                    prev = prev->getNext();
                }
            }
        } while ( prev->getNext() != nullptr );
        /////////////////
                                    //traverse to end and marks tail end
        cur = head;
        while ( cur->getNext()){
            cur = cur->getNext();
        }
        tail = cur;
        /////
    }
    else{ cout << x << "Not found." << endl << endl; };
}
