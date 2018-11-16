#include "Program.h"
#include <fstream>

using namespace bfm;

Program::Program(const string& fileName) : m_tape(tape(30000)){
    ifstream file(fileName);
    if(!file.is_open())
        throw runtime_error("Cannot open file" + fileName);
    string line;
    while(getline(file, line)){
        for(char& ch : line){
            if(ch == '<')
                m_instructions.emplace_back(new InstructionLeft())
        }
    }
    file.close();
}
