#include <iostream>
#include <string>
#include <fstream>
#include "runScanner.h"
using namespace std;

int main(int argc, char *argv[]){
    string fileName;

    switch(argc){
        // We will read from keyboard if no file given
        case 1:{
            cout  << "Reading from keyboard" << endl;
            string keyboardInput;
            ofstream tempFile;

            // Open a file to store keyboard input
            fileName = "tempFile.dat";
            tempFile.open(fileName.c_str());

            cout << "Enter token(s) then return end of file (ctl-d) when finished: ";
            while(getline(cin, keyboardInput)){
                tempFile << keyboardInput << " ";
            }
            cout << endl << "Finished inputting tokens" << endl;

            tempFile.close();
            break;
        }
        
        // We are given a file extentsion or no extension
        case 2:{
            cout << "Now reading from a file" << endl;

            // Get file name
            fileName = argv[1];

            // Find out if theres an extension to this file but seeing if theres a .
            size_t extFinder = fileName.find(".");

            // If theres not an extenstion give it one
            if(extFinder == string::npos){
                fileName = fileName.append(".fs");
            }
            break;
        }

        default:{
            // If too many arguments given
        cout << "ERROR too many command line arguments given" << endl;
        }
    }

        runScanner(fileName);
        return 1;

}