#include "Data.h"

Data::Data(byte data) : m_data(data) {}

byte Data::getData() const {
    return m_data;
}

byte Data::setData(byte data) {
    return m_data;
}

Data &Data::operator--() {
    m_data--;
    return *this;
}

Data &Data::operator++() {
    m_data++;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
    os << data.m_data;
    return os;
}


Data::~Data() = default;
