#include <iostream>
#include <stdexcept>
#include "BrainFuckVM.h"

// SFML 2.4.2

using namespace std;
using namespace bfm;

int main(int argc, char* argv[]) {
    try {

        if(argc < 2)
            throw runtime_error("Error: not enough parameters: use bfm <filename.bf>");

        string fileName(argv[1]);

        cout << "BrainFuckVM is ready for some serious action!" << endl;
        BrainFuckVM bfm;
        Program prog(fileName);
        bfm.run(&prog);
    }catch (exception& e){
        cerr << "Fatal exception occurred: " << e.what() << endl;
    }
    return 0;
}