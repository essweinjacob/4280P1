#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>     // cin & cout
#include <string>       // string > char arrays
#include <cstring>      // cool c string things
#include <cctype>       // isalpha/isdigit/etc
#include <cstdlib>      
#include <sstream>      // String stream classes
#include "token.h"
#include<stdio.h>
using namespace std;

class Scanner: public Language{
    private:
        unsigned int currentScannerPtr = 0; //Keeps track of scanner finished last input, initially set to 0
        bool isComment = false;     // Is the scanner currently in a comment?
        string lastComPos = "";     // Log when the last time we were in a comment

        enum{
            ERROR_UNK = -2,     // Error Unkown State     
            ERROR_INT = -1,     // Error Integer State
            STATE_0 = 0,        // Initial State
            STATE_1 = 1,        // Operator State
            STATE_2 = 2,        // Identifier State
            STATE_3 = 3,        // Integeter State
            STATE_F = 1000,     // Final State
            STATE_ID = 1001,    // Indetifier Final State
            STATE_INT = 1003,   // Int final state
            STATE_OP = 1004,    // Op Final State
            STATE_EOF = 1005    // End of File Final State
        };

        // FSA Table
        const int TABLE_FSA[4][6] = {
            {STATE_2, STATE_3, STATE_0, STATE_EOF, STATE_1, ERROR_UNK}, {STATE_OP, STATE_OP, STATE_OP, STATE_OP, STATE_OP, STATE_OP},
            {STATE_2, STATE_2, STATE_ID, STATE_ID, STATE_ID, ERROR_UNK}, {ERROR_INT, STATE_3, STATE_INT, STATE_INT, STATE_INT, ERROR_UNK}
        };

        // Delimiter for scanner
        const char SCAN_DELIM = ' ';

        int getCat(char ch);
        void getError(int curLine, int state, char ch);
        char checkCom(int curLine, char ch);
    
    public:
        Scanner();
        int scan(int curLine, string &input, Token &tk);
        void isComMode();
};

#endif