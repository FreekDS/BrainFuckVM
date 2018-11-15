#ifndef BRAINFUCKVM_BRAINFUCKVM_H
#define BRAINFUCKVM_BRAINFUCKVM_H


#include "Program.h"
#include "Data.h"
#include <vector>

using namespace std;

namespace bfm {

    class BrainFuckVM {
    private:
        vector<Data *> m_tape;
    public:
        void run(Program *program);
    };

}

#endif //BRAINFUCKVM_BRAINFUCKVM_H
