/*
        Aaron Im
        CS1337.002
        Project 5
        FALL2016
*/
#include "BaseNode.h"


using namespace std;

BaseNode::BaseNode(){       //Default constructor
    arabic = 9999;          //I am using 9999 to filter out nodes that are invalid.
    updateRoman();
}

BaseNode::BaseNode(string letters){      //if their is a possibility the string is an arabic numeral, string will be converted and stored.
                                                //sets arabic to 9999 if invalid
    if (isdigit(letters[0]) == 1 ){
        int digits;
        if ( testArabic ( letters ) ){      //tests if characters are all digits
            istringstream convert(letters);
            convert >> digits;
                if ( testArabicRange(digits)){           //tests if interger is in range 1-4999
                    setArabic(digits);
                }
                else { setArabic(9999);}
        }
        else { setArabic(9999);}
    }
    else{                                           //Else if a possible Roman numeral
      if (  testRoman(letters)){
        setRoman ( letters);                    //If valid Roman numeral, set roman and update arabic
        updateArabic(letters);
      }
      else { setArabic(9999);}              //If not valid roman, set to 9999 to be filtered out.
    }
}

BaseNode::~BaseNode(){}

void BaseNode::setArabic(int x){
    arabic = x;
    updateRoman();
}

void BaseNode::setRoman(string y){
    roman = y;
    updateArabic(y);
}

void BaseNode::updateArabic(string RomanLine){          //This function will convert a string of roman numerals to arabic.
    int sum = 0;
    for (int i=0; i< RomanLine.size() ; i++){       //This loop ensures that the entire of string of roman numerals gets scanned
        if (RomanLine[i] == 'M'){
            sum +=1000;
        }
        else if (RomanLine[i] == 'D'){
            sum +=500;
        }
        else if (RomanLine[i] == 'C' && (RomanLine[i+1] == 'M' || RomanLine[i+1] == 'D')){
            sum -=100;
        }
        else if (RomanLine[i] == 'C'){              //used AND and OR operators to build special cases.
            sum +=100;
        }
        else if (RomanLine[i] == 'L'){
            sum +=50;
        }
        else if (RomanLine[i] == 'X' && (RomanLine[i+1] == 'L' || RomanLine[i+1] == 'C')){
            sum -=10;
        }
        else if (RomanLine[i] == 'X'){
            sum +=10;
        }
        else if (RomanLine[i] == 'V'){
            sum +=5;
        }
        else if (RomanLine[i] == 'I' && (RomanLine[i+1] == 'V' || RomanLine[i+1] == 'X')){
            sum -=1;
        }
        else if (RomanLine[i] == 'I'){
            sum +=1;
        }
    }
    arabic = sum;
}

void BaseNode::updateRoman(){

    string newRoman="";     //ensure newRoman string is empty.

        int Thousands = arabic /1000;             //These equations are for figuring out how much is in each tens place.
        int Hundreds = (arabic - Thousands*1000 )/100;
        int Tens = (arabic - Thousands*1000 - Hundreds*100) /10;
        int Ones = (arabic - Thousands*1000 - Hundreds*100 - Tens*10) /1;

        if (Thousands >= 1 && Thousands <= 4){
            for(int i =1; i<=Thousands; i++){
                newRoman += 'M';
            }
        }
        if (Hundreds >=1 && Hundreds <4){
            for(int i=0; i<Hundreds; i++){
                newRoman += 'C';
            }
        }
        if (Hundreds==4){
                newRoman += "CD";
        }
        if (Hundreds>=5 && Hundreds <9){
            newRoman += 'D';
        }
        if (Hundreds >=6 && Hundreds <9){
            for(int i=6; i<=Hundreds; i++){
                newRoman += 'C';
            }
        }
        if (Hundreds ==9){
                newRoman += "CM";
        }

        if (Tens >=1 && Tens <4){
            for(int i=0; i<Tens; i++){
                newRoman += 'X';
            }
        }
        if (Tens==4){
                newRoman += "XL";
        }
        if (Tens>=5 && Tens < 9){
            newRoman += 'L';
        }
        if (Tens >=6 && Tens <9){
            for(int i=6; i<=Tens; i++){
                newRoman += 'X';
            }
        }
         if (Tens ==9){
                newRoman += "XC";
        }
        if (Ones >=1 && Ones <4){
            for(int i=0; i<Ones; i++){
                newRoman += 'I';
            }
        }
        if (Ones==4){
                newRoman += "IV";
        }
        if (Ones>=5 && Ones <9){
            newRoman += 'V';
        }
        if (Ones >=6 && Ones <9){
            for(int i=6; i<=Ones; i++){
                newRoman += 'I';
            }
        }
        if(Ones == 9){
            newRoman += "IX";
        }
        roman = newRoman;
}

bool BaseNode::testRoman (string input){              // returns 1 if valid roman numeral
    bool valid = true;
    int length = input.length() ;
    for ( int i =0 ; i <= (length-1); i++){
        if ( isupper(input[i]) ==0 ){
            valid = false;
        }
    }
    return valid;
}

bool BaseNode::testArabic (string input){       //returns 1 if valid arabic numeral entry

    bool valid = true;
    int length, i;

    length = input.length();
    for( i =0; i <= (length-1); i++){
        if ( isdigit(input[i])==0){
            valid = false;
        }
    }
    return valid;
}

bool BaseNode::testArabicRange (int input){      //returns 1 if in valid range

    bool valid = true;
    if ( !(input >= 1 && input <=4999)){
            valid = false;
    }
    return valid;
}

















