#ifndef ADDRESSCALCULATOR_H
#define ADDRESSCALCULATOR_H

#include "memoryhierarchy.h"

extern MemoryHierarchy *randMemory;

enum MemoryType {L1, L2, L3, RAM};

class AddressCalculator
{
public:
    AddressCalculator();
    AddressCalculator(int blockSize);

    int index(int address, MemoryType type);
    int tag(int address, MemoryType type);
    int offset(int address, MemoryType type);

    int getBlockSize() const;
    void setBlockSize(int value);

private:
    int blockSize = 1;
};

#endif // ADDRESSCALCULATOR_H
