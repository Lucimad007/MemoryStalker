#include "addresscalculator.h"
#include <cmath>

enum MemoryType;


AddressCalculator::AddressCalculator()
{
    blockSize = 1;
}

AddressCalculator::AddressCalculator(int blockSize)
{
    this->blockSize = blockSize;
}

int AddressCalculator::getBlockSize() const
{
    return blockSize;
}

void AddressCalculator::setBlockSize(int value)
{
    blockSize = value;
}


int AddressCalculator::index(int address, MemoryType type)
{
    switch (type) {
    case L1:
        address /= std::log2(randMemory->getL1().getBlockSize());
        address %= randMemory->getL2().getSize();
        break;
    case L2:
        address /= std::log2(randMemory->getL2().getBlockSize());
        address %= randMemory->getL3().getSize();
        break;
    case L3:
        address /= std::log2(randMemory->getL3().getBlockSize());
        address %= randMemory->getRAM().getSize();
        break;
    case RAM:
        address = 0;    //fully associative
        break;
    }

    return  address;

}
int AddressCalculator::tag(int address, MemoryType type)
{
    int index = 0;
    int higherIndex = 0;
    switch (type) {
    case L1:
        address /= std::log2(randMemory->getL1().getBlockSize());
        index %= randMemory->getL2().getSize();
        address = randMemory->getL2().getSize() / randMemory->getL1().getBlockSize() - index;
        break;
    case L2:
        address /= std::log2(randMemory->getL2().getBlockSize());
        index %= randMemory->getL3().getSize();
        address = randMemory->getL3().getSize() / randMemory->getL2().getBlockSize() - index;
        break;
    case L3:
        address /= std::log2(randMemory->getL3().getBlockSize());
        index %= randMemory->getRAM().getSize();
        address = randMemory->getRAM().getSize() / randMemory->getL3().getBlockSize() - index;
        break;
    case RAM:
        address /= 4;    //fully associative
        break;
    }

    return  address;
}
int AddressCalculator::offset(int address, MemoryType type)
{
    switch (type) {
    case L1:
        address %= randMemory->getL1().getBlockSize();
        break;
    case L2:
        address %= randMemory->getL2().getBlockSize();
        break;
    case L3:
        address %= randMemory->getL3().getBlockSize();
        break;
    case RAM:
        address %= randMemory->getRAM().getBlockSize();
        break;
    default:
        address %= randMemory->getRAM().getBlockSize();    //also for HDD
    }

    return  address;
}
