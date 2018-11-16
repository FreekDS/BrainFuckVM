#ifndef BRAINFUCKVM_INSTRUCTION_H
#define BRAINFUCKVM_INSTRUCTION_H

#include "Data.h"
#include <vector>

using namespace std;

namespace bfm{

    class Instruction {
    private:
        char m_symbol;
    protected:
        unsigned int *m_dataPtr;
        unsigned int *m_instrPtr;
        tape *m_data;
    public:
        char getSymbol() const;
        explicit Instruction(char symbol);
        Instruction(char symbol, unsigned int *dataPtr, unsigned int* instPtr, tape* data);
        Instruction();
        virtual ~Instruction() = default;
        virtual void execute() = 0;
    };

    class InstructionRight: public Instruction{
    public:
        InstructionRight(unsigned int *dataPtr, unsigned int* instPtr, tape* data);

        ~InstructionRight() override = default;

        void execute() override;
    };

    class InstructionLeft: public Instruction{
    public:
        InstructionLeft(unsigned int *dataPtr, unsigned int* instPtr, tape* data);

        ~InstructionLeft() override = default;

        void execute() override;
    };

    class InstructionInc: public Instruction{
    public:
        InstructionInc(unsigned int *dataPtr, unsigned int* instPtr, tape* data);

        ~InstructionInc() override = default;

        void execute() override;
    };

    class InstructionDec: public Instruction{
    public:
        InstructionDec(unsigned int *dataPtr, unsigned int* instPtr, tape* data);

        ~InstructionDec() override = default;

        void execute() override;
    };

    class InstructionOut: public Instruction{
    public:
        InstructionOut(unsigned int *dataPtr, unsigned int* instPtr, tape* data);

        ~InstructionOut() override = default;

        void execute() override;
    };

    class InstructionIn: public Instruction{
    public:
        InstructionIn(unsigned int *dataPtr, unsigned int* instPtr, tape* data);

        ~InstructionIn() override = default;

        void execute() override;
    };

    class InstructionJumpFw: public Instruction{
    public:
        InstructionJumpFw(unsigned int *dataPtr, unsigned int* instPtr, tape* data);

        ~InstructionJumpFw() override = default;

        void execute() override;
    };

    class InstructionJumpBw: public Instruction{
    public:
        InstructionJumpBw(unsigned int *dataPtr, unsigned int* instPtr, tape* data);

        ~InstructionJumpBw() override = default;

        void execute() override;
    };

}

#endif //BRAINFUCKVM_INSTRUCTION_H
