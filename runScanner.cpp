#include <iostream>
#include <string>
#include <fstream>
#include "runScanner.h"
#include "token.h"
#include "scanner.h"
using namespace std;

int runScanner(string fileName){
    Scanner scanner;    // Create scanner object

    ifstream file(fileName.c_str());    // Open file
    unsigned int curLine = 1;  // Track what the current line number in file is
    Token tk;     // Token holder

    // Check if file can be opened
    if(file.is_open()){
        string line;    // Store line of file into this
        // While more lines to get in file
        while(getline(file, line)){
            // Invoke scanner until we've identifed every token in the current line
            while(scanner.scan(curLine, line, tk) == 0){
                scanner.printTK(tk);
            }
            curLine++;
        }
        
        // Check for comment takes
        scanner.isComMode();
    }
    // If we cant open the file throw error
    else{
        cout << "ERROR. The given file cannot be opened" << endl;
        return -1;
    }

    // After we've gone through the file display the end of file token
    if(file.eof()){
        // See if line we are at is the initial line
        if(curLine > 1){
            // If not reduce by 1
            curLine--;
        }

        // Display end of file token
        tk.lineNum = curLine;
        tk.id = EOFTK;
        tk.val = "EOF";
        scanner.printTK(tk);
    }

    file.close();
    return 0;

}