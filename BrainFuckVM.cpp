#include "BrainFuckVM.h"

using namespace bfm;

void BrainFuckVM::run(Program *program) {
    program->setTape(&m_tape);
    program->run();
}

BrainFuckVM::BrainFuckVM()
        :m_tape(30000) { }
