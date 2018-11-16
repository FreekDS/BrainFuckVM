#ifndef BRAINFUCKVM_BRAINFUCKVM_H
#define BRAINFUCKVM_BRAINFUCKVM_H


#include "Program.h"
#include "Data.h"
#include <vector>

using namespace std;

namespace bfm {

    class BrainFuckVM {
    private:
        tape m_tape;
    public:
        BrainFuckVM();

        void run(Program *program);
    };

}

#endif //BRAINFUCKVM_BRAINFUCKVM_H
