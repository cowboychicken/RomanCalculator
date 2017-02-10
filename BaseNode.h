/*
        Aaron Im
        CS1337.002
        Project 5
        FALL2016
*/
#ifndef BASENODE_H
#define BASENODE_H
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class BaseNode {

protected:
    int arabic;
    string roman;

public:
                                                                                                //Constructors
    BaseNode();
    BaseNode(string);

    ~BaseNode();

                                                                                                //Accessors
    int getArabic() const {return arabic;};
    string getRoman() const {return roman;};

                                                                                                //Mutators
    void setArabic(int);
    void setRoman(string);

                                                                                                //Overloaded operators
    ostream operator << (ostream &strm);
    istream operator >> (istream &strm);

   virtual void updateArabic(string);

    void updateRoman();
    bool testRoman(string);                                                                     // returns 1 if valid roman numeral
    bool testArabic(string);                                                                    //returns 1 if valid arabic numeral entry
    bool testArabicRange(int);                                                                  //returns 1 if in valid range

};

#endif  /*__BASENODE_H__*/
