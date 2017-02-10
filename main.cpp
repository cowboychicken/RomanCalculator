//Roman Numeral Calculator
/*
        Aaron Im
        CS1337.002
        Project 5
        FALL2016
*/
#include <iostream>
#include <fstream>
#include <BaseNode.h>
#include <DerNode.h>
#include <Link.h>

using namespace std;

void capture (fstream& , Link& linkobj);

int main(){
    fstream input;
    Link linkobj;

    input.open("numbers.txt" , ios::in | ios::binary);
    capture(input,linkobj);                                                                     //Calls function to capture entire list.

    while (2>1){
        int answer=0;

        cout << "Hi, please choose from the following:"<<endl<<endl;
        cout << "(1) Search" << endl;
        cout << "(2) Add (+ sort)" << endl;
        cout << "(3) Delete first" << endl;
        cout << "(4) Delete last" << endl;
        cout << "(5) Delete any" << endl;
        cout << "(6) Exit" << endl<<endl;
        cin >> answer;cout<<endl<<endl;

        if (answer == 1){                                                                       //Search for value.
            string stringinput;

            cout << "Enter value to search for: ";
            cin>>stringinput;

            DerNode nodeobj(stringinput);                                                       //Use constructor to convert to arabic.
            linkobj.bubbleSort();                                                               //Sort before search.
            if (linkobj.binarySearch(nodeobj.getArabic() ) == 1   ){
                cout << endl << stringinput << " found." << endl << endl;
            }
            else { cout << endl << stringinput << " not found." << endl << endl;}
        }
        if (answer == 2){                                                                       //Add new value to end of list.
            string stringinput;

            cout << "Enter value to add: ";
            cin>>stringinput;

            DerNode *nodeobj = new DerNode(stringinput);
            linkobj+=nodeobj;

            cout << endl << stringinput << " has been added to the list." << endl << endl;
        }
        if (answer == 3){                                                                       //Delete first node.
            --linkobj;
            cout << endl << "The first node has been deleted." << endl << endl;
        }
        if (answer == 4){                                                                       //Delete last node.
             linkobj--;
            cout << endl << "The last node has been deleted." << endl << endl;
        }
        if (answer == 5){
            string stringinput;

            cout << "Enter value to delete: ";
            cin>>stringinput;

            DerNode *nodeobj = new DerNode(stringinput);

            linkobj.bubbleSort();
            linkobj.deleteAny(nodeobj->getArabic());
        }
        if (answer == 6){                                                                       //Print current state of list and exit.
            linkobj.printFile();
            return 0;
        }
    }
}

void capture (fstream& input,Link& linkobj){                                                    //Captures valid numbers from "numbers.txt"

    while(input.tellg() != EOF){
        string stringinput;
        char ch;
        int position;

        position = input.tellg();                                                               //Saves the current position as a reference point for the beginning of the line.
        ch = input.peek();                                                                      //Peek will report back the value in front of the pointer w/o moving it.

        if (ch == ' '){
            input.seekg(16, ios::cur);                                                          //moves pointer 16 bytes forward from current position
            input >> stringinput;
                                                                                                //build node, if not 9999, link
            DerNode *node = new DerNode(stringinput);
            if (node->getArabic() != 9999 &&  node->getArabic() != 0){
                linkobj+=node;
            }
        }
        else{                                                                                   // build node, if not 9999, link
            input >> stringinput;

            DerNode *node = new DerNode(stringinput);
            if(node->getArabic() != 9999 &&  node->getArabic() != 0){
               linkobj+=node;
            }
        }
        input.seekg(position);
        input.seekg(22, ios::cur);                                                              //Skip to beginning of next line
    }
}
