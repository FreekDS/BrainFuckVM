#include <cstdlib>
#include <iostream>
#include "Instruction.h"
#include "Program.h"

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

void Instruction::setData(tape* data)
{
    Instruction::m_data = data;
}

InstructionRight::InstructionRight(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('>', dataPtr, instPtr, data) {}

void InstructionRight::execute() {
    if(*m_dataPtr >= 30000)
        throw runtime_error("Cannot shift data pointer to right, data pointer is already on max (30000)");
    (*m_dataPtr)++;
}

void InstructionRight::log()
{
    cout << "Shift right to " << *m_dataPtr << endl;
}

InstructionLeft::InstructionLeft(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('<', dataPtr, instPtr, data) {}

void InstructionLeft::execute() {
    if(*m_dataPtr <= 0)
        throw runtime_error("Cannot shift data pointer to left, data pointer already is on 0");
    (*m_dataPtr)--;
}

void InstructionLeft::log()
{
    cout << "Data pointer shift left to " << *m_dataPtr << endl;
}

InstructionInc::InstructionInc(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('+', dataPtr, instPtr, data) {}

void InstructionInc::execute() {
    Data& current = (*m_data)[*m_dataPtr];
    ++current;
}

void InstructionInc::log()
{
    cout << "Increased data on " << *m_dataPtr << " to " << static_cast<int>((*m_data)[*m_dataPtr].getData()) << endl;
}

InstructionDec::InstructionDec(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('-', dataPtr, instPtr, data) {}

void InstructionDec::execute() {
    Data& current = (*m_data)[*m_dataPtr];
    if(current.getData() <= 0)
        throw runtime_error("Cannot decrement data in cell" + std::to_string(*m_dataPtr) + ":\nValue is 0");
    --current;
}

void InstructionDec::log()
{
    cout << "Decreased data on " << *m_dataPtr << " to " << static_cast<int>((*m_data)[*m_dataPtr].getData()) << endl;
}

InstructionOut::InstructionOut(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('.', dataPtr, instPtr, data) {}

void InstructionOut::execute() {
    Data& data = (*m_data)[*m_dataPtr];
    cout << data;
}

void InstructionOut::log()
{
    cout << "Output of " << *m_dataPtr << endl;
}

InstructionIn::InstructionIn(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction(',', dataPtr, instPtr, data) {}

void InstructionIn::execute() {
    Data& data = (*m_data)[*m_dataPtr];
    byte b;
    cin >> b;
    data.setData(b);
}

void InstructionIn::log()
{
    cout << "Read input for " << *m_dataPtr << endl;
}

InstructionJumpFw::InstructionJumpFw(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction('[', dataPtr, instPtr, data) {}

void InstructionJumpFw::execute() {
    if((*m_data)[*m_dataPtr].getData() == 0){
        while(m_program->getInstructions()[*m_instrPtr]->getSymbol() != ']'){
            ++(*m_instrPtr);
            if(*m_instrPtr >= m_program->getInstructions().size()){
                throw runtime_error("Instruction pointer out of bounds!");
            }
        }
        if(m_program->getInstructions()[*m_instrPtr]->getSymbol() != ']'){
            ++(*m_instrPtr);
        }

    }
}

void InstructionJumpFw::setProgram(Program* program)
{
    m_program = program;
}

void InstructionJumpFw::log()
{
    cout << "Jumped forward to instruction " << *m_instrPtr << endl;
}

InstructionJumpBw::InstructionJumpBw(unsigned int *dataPtr, unsigned int* instPtr, tape* data) : Instruction(']', dataPtr, instPtr, data) {}

void InstructionJumpBw::execute() {
    if((*m_data)[*m_dataPtr].getData() != 0){
        while(m_program->getInstructions()[*m_instrPtr]->getSymbol() != '['){
            --(*m_instrPtr);
            if(*m_instrPtr < 0){
                throw runtime_error("Instruction pointer out of bounds!");
            }
        }
        if(m_program->getInstructions()[*m_instrPtr]->getSymbol() != ']'){
            --(*m_instrPtr);

        }
    }
}

void InstructionJumpBw::setProgram(Program* program)
{
    InstructionJumpBw::m_program = program;
}

void InstructionJumpBw::log()
{
    cout << "Jumped back to instruction " << *m_instrPtr << endl;
}
