#ifndef BRAINFUCKVM_DATA_H
#define BRAINFUCKVM_DATA_H

#include <vector>
#include <ostream>

typedef unsigned char byte;

class Data {
private:
    byte m_data;
public:
    explicit Data(byte data);
    virtual ~Data();

    friend std::ostream &operator<<(std::ostream &os, const Data &data);

    Data& operator--();
    Data& operator++();

    byte setData(byte data);
    byte getData() const;
};

typedef std::vector<Data> tape;

#endif //BRAINFUCKVM_DATA_H
