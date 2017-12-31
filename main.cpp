#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("C:\\Users\\User\\Documents\\assembler\\sourcecode.txt");
    int x=111;
    int y=112;
    int z=113;
    int one=114;
    int n = 0;
    int value;
    string labels[15];
    cout << "Symbols" << "     " << "Value" << endl;

    for (string label, opcode, location;
        getline(infile, label, '\t') && getline(infile, opcode, '\t') && getline(infile, location); (n++)
    )
        {
            if (label == ""){
                label.erase();
            }
            else {
                if (label == ""){
                        return 0;}
                else {
                    value = n;

                    cout << label  << "          01" << hex << value << endl;
                }
        }}

    infile.close();

    infile.open("C:\\Users\\User\\Documents\\assembler\\sourcecode.txt");

    cout << endl << endl;
    cout << "Opcode" << "     " << "Location" << "     " << "Code" << endl;
    n = 0;
    int i = 0;
    int address;
    string num;

    for (string label, opcode, location;
        getline(infile, label, '\t') && getline(infile, opcode, '\t') && getline(infile, location);
    )
        {
            if (location == "x") {address = x;}
            if (location == "y") {address = y;}
            if (location == "z") {address = z;}
            if (location == "One") {address = one;}

            if (n == 16) {i = i + 1; n = 0;}
            if (i > 1) {i = 1;}
            if (opcode == "org") { cout << opcode << "         0000" << "        0000" << endl;}
            if (opcode == "Load") { cout << opcode << "        01" << i << hex << n  << "        1" << dec << address << endl; n = n+1;}
            if (opcode == "Store") { cout << opcode << "       01" << i << hex << n  << "        2" << dec << address << endl; n = n+1;}
            if (opcode == "Subt") { cout << opcode << "        01" << i << hex << n  << "        4" << dec << address << endl; n = n+1;}
            if (opcode == "Unused") { cout << opcode << "      01" << i << hex << n  << "        F" << dec << address << endl; n = n+1;}
            if (opcode == "AddI") { cout << opcode << "        01" << i << hex << n  << "        B" << dec << address << endl; n = n+1;}
            if (opcode == "Add") { cout << opcode << "         01" << i << hex << n  << "        3" << dec << address << endl; n = n+1;}
            if (opcode == "Skipcond") { cout << opcode << "    01" << i << hex << n  << "        8000" << endl; n = n+1;}
            if (opcode == "Jump") { cout << opcode << "        01" << i << hex << n  << "        9000" << endl; n = n+1;}
            if (opcode == "Jns") { cout << opcode << "         01" << i << hex << n  << "        0" << dec << address << endl; n = n+1;}
            if (opcode == "Input") { cout << opcode << "       01" << i << hex << n  << "        5000" << endl; n = n+1;}
            if (opcode == "Output") { cout << opcode << "      01" << i << hex << n  << "        6000" << endl; n = n+1;}
            if (opcode == "Clear") { cout << opcode << "       01" << i << hex << n  << "        A000" << endl; n = n+1;}
            if (opcode == "JumpI") { cout << opcode << "       01" << i << hex << n  << "        C000" << endl; n = n+1;}
            if (opcode == "LoadI") { cout << opcode << "       01" << i << hex << n  << "        D" << dec << address << endl; n = n+1;}
            if (opcode == "StoreI") { cout << opcode << "      01" << i << hex << n  << "        E" << dec << address << endl; n = n+1;}
            if (opcode == "Halt") { cout << opcode << "        01" << i << hex << n  << "        7000" << endl; n = n+1;}
            if (opcode == "Hex") { cout << opcode << "         01" << i << hex << n  << "        000" << location << endl; n = n+1;}
            if (opcode == "Dec") { cout << opcode << "         01" << i << hex << n  << "        000" << location << endl; n = n+1;}

        }


}
