#include "Program.h"
#include <fstream>

using namespace bfm;

Program::Program(const string& fileName) : m_tape(nullptr), m_instrPtr(0), m_dataPtr(0){
    ifstream file(fileName);
    if(!file.is_open())
        throw runtime_error("Cannot open file" + fileName);
    string line;
    while(getline(file, line)){
        for(char& ch : line){
            if(ch == '<')
                m_instructions.emplace_back(new InstructionLeft(&m_dataPtr, &m_instrPtr, m_tape));
            else if(ch == '>')
                m_instructions.emplace_back(new InstructionRight(&m_dataPtr, &m_instrPtr, m_tape));
            else if(ch == '+')
                m_instructions.emplace_back(new InstructionInc(&m_dataPtr, &m_instrPtr, m_tape));
            else if(ch == '-')
                m_instructions.emplace_back(new InstructionDec(&m_dataPtr, &m_instrPtr, m_tape));
            else if(ch == '.')
                m_instructions.emplace_back(new InstructionOut(&m_dataPtr, &m_instrPtr, m_tape));
            else if(ch == ',')
                m_instructions.emplace_back(new InstructionIn(&m_dataPtr, &m_instrPtr, m_tape));
            else if(ch == '['){
                auto* instr = new InstructionJumpFw(&m_dataPtr, &m_instrPtr, m_tape);
                instr->setProgram(this);
                m_instructions.emplace_back(instr);
            }
            else if(ch == ']'){
                auto* instr = new InstructionJumpBw(&m_dataPtr, &m_instrPtr, m_tape);
                instr->setProgram(this);
                m_instructions.emplace_back(instr);
            }
            else
                continue;
        }
    }
    file.close();
}

Program::~Program()
{
    for(Instruction* instr : m_instructions)
        delete instr;
}

void Program::run(bool debug)
{
    while(m_instrPtr < m_instructions.size() && m_instrPtr >= 0) {
        Instruction* current = m_instructions[m_instrPtr];
        current->execute();
        if(debug)
            current->log();
        m_instrPtr++;
    }
}

void Program::setTape(tape* tape1)
{
    Program::m_tape = tape1;
    for(Instruction* instr : m_instructions){
        instr->setData(tape1);
    }
}

const vector<Instruction*>& Program::getInstructions() const
{
    return m_instructions;
}
