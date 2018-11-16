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
    tape* m_tape;
    unsigned int m_dataPtr;
    unsigned int m_instrPtr;
public:
    explicit Program(const string& fileName);

    void run();

    void setTape(tape* tape1);

    virtual ~Program();

};

}

#endif //BRAINFUCKVM_PROGRAM_H
