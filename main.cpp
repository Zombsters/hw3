// hw3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "ArgumentManager.h"

using namespace std;
string ReturnSubstr(string line);


int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream fin(am.get("input"));
    ofstream fout(am.get("output"));

    string line; BST<int> iBST; BST<string> sBST;

    while (fin >> line) {
        cout << line << endl;
        if (line.find("Insert") != string::npos) {
            cout << "This is an insert ";
            string substr = ReturnSubstr(line);
            if (isdigit(substr[0])) {
                int subint = stoi(substr);
                cout << "found int: " << subint << endl;
                iBST.Insert(subint);
            }
            else {
                cout << "found string: " << substr << endl;
                sBST.Insert(substr);
            }
        }
        else if (line.find("PrintLR") != string::npos) {
            cout << "Tree traversal" << endl;
            if (iBST.returnRoot() != NULL) {
                iBST.leftRight(fout);
            }
            else {
                sBST.leftRight(fout);
            }
            fout << endl;
        }
        else if (line.find("PrintLevel") != string::npos) {
            cout << "Level print" << endl;
            string substr = ReturnSubstr(line); int subint = stoi(substr);
            if (iBST.returnRoot() != NULL) {
                iBST.PrintLevel(fout, subint);
                if (iBST.returnFound() == false) {
                    fout << "Does Not Exist!";
                }
            }
            else {
                sBST.PrintLevel(fout, subint);
                if (sBST.returnFound() == false) {
                    fout << "Does Not Exist!";
                }
            }
            fout << endl;
        }
        else if (line.find("Mirror") != string::npos) {
            cout << "Mirroring BST" << endl;
            if (iBST.returnRoot() != NULL) {
                iBST.setMirror();
                iBST.Mirror();
            }
            else {
                sBST.setMirror();
                sBST.Mirror();
            }
        }
    }

    return 0;
}

string ReturnSubstr(string line) {
    string substr;
    for (int i = line.find("(") + 1; i < line.size(); i++) {
        if (line.at(i) == ')') {
            break;
        }
        else {
            substr += line.at(i);
        }
    }
    return substr;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
