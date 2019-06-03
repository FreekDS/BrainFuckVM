#include "BrainFuckVM.h"

using namespace bfm;

void BrainFuckVM::run(Program *program) {
    m_tape.clear();
    m_tape = tape(30000);
    program->setTape(&m_tape);
    program->run();
}

BrainFuckVM::BrainFuckVM()
        :m_tape(30000) { }
