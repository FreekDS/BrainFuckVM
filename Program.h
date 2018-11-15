#ifndef BRAINFUCKVM_PROGRAM_H
#define BRAINFUCKVM_PROGRAM_H

#include <iostream>
#include <vector>
#include "Instruction.h"

using namespace std;

namespace bfm{

class Program {
private:
    vector<Instruction*> m_instructions{};
    tape m_tape;
public:
    explicit Program(const string& fileName);

};

}

#endif //BRAINFUCKVM_PROGRAM_H