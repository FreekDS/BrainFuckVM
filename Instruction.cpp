#include <cstdlib>
#include <iostream>
#include "Instruction.h"

using namespace bfm;

Instruction::Instruction(char symbol) : m_symbol(symbol), m_instrPtr(nullptr), m_dataPtr(nullptr) {}

char Instruction::getSymbol() const {
    return m_symbol;
}

Instruction::Instruction(char symbol, unsigned int *dataPtr, unsigned int *instPtr, tape* data) : m_symbol(symbol),
                                                                                        m_dataPtr(dataPtr),
                                                                                        m_instrPtr(instPtr),
                                                                                        m_data(data) {}

Instruction::Instruction() : m_symbol(' '), m_instrPtr(nullptr), m_dataPtr(nullptr) {}

InstructionRight::InstructionRight(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('>', dataPtr, instPtr, data) {}

void InstructionRight::execute() {
    if(*m_dataPtr >= 30000)
        throw runtime_error("Cannot shift data pointer to right, data pointer is already on max (30000)");
    (*m_dataPtr)++;
}

InstructionLeft::InstructionLeft(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('<', dataPtr, instPtr, data) {}

void InstructionLeft::execute() {
    if(*m_dataPtr <= 0)
        throw runtime_error("Cannot shift data pointer to left, data pointer already is on 0");
    (*m_dataPtr)--;
}

InstructionInc::InstructionInc(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('+', dataPtr, instPtr, data) {}

void InstructionInc::execute() {
    Data* current = (*m_data)[*m_dataPtr];
    ++(*current);
}

InstructionDec::InstructionDec(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('-', dataPtr, instPtr, data) {}

void InstructionDec::execute() {
    Data* current = (*m_data)[*m_dataPtr];
    if(current->getData() <= 0)
        throw runtime_error("Cannot decrement data in cell" + std::to_string(*m_dataPtr) + ":\nValue is 0");
    --(*current);
}

InstructionOut::InstructionOut(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('.', dataPtr, instPtr, data) {}

void InstructionOut::execute() {
    Data* data = (*m_data)[*m_dataPtr];
    cout << data;
}

InstructionIn::InstructionIn(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction(',', dataPtr, instPtr, data) {}

void InstructionIn::execute() {
    Data* data = (*m_data)[*m_dataPtr];
    byte b;
    cin >> b;
    data->setData(b);
}

InstructionJumpFw::InstructionJumpFw(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('[', dataPtr, instPtr, data) {}

void InstructionJumpFw::execute() {

}

InstructionJumpBw::InstructionJumpBw(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction(']', dataPtr, instPtr, data) {}

void InstructionJumpBw::execute() {

}
