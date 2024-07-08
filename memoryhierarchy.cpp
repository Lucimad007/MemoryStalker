#include "memoryhierarchy.h"

MemoryHierarchy::MemoryHierarchy()
{

}

MemoryHierarchy::MemoryHierarchy(int size)
{
    hdd = new long long*[12];   //we consider max words/block because 2nd parameter of array can't be dynamic
    for(int i = 0; i < 12; i++)
        hdd[i] = new long long[size];
    totalAccess = 0;
    totalCycles = 0;
}

Cache MemoryHierarchy::getL1() const
{
    return L1;
}

void MemoryHierarchy::setL1(const Cache &value)
{
    L1 = value;
}

Cache MemoryHierarchy::getL2() const
{
    return L2;
}

void MemoryHierarchy::setL2(const Cache &value)
{
    L2 = value;
}

Cache MemoryHierarchy::getL3() const
{
    return L3;
}

void MemoryHierarchy::setL3(const Cache &value)
{
    L3 = value;
}

Cache MemoryHierarchy::getRAM() const
{
    return RAM;
}

void MemoryHierarchy::setRAM(const Cache &value)
{
    RAM = value;
}

int MemoryHierarchy::getLevel() const
{
    return level;
}

void MemoryHierarchy::setLevel(int value)
{
    level = value;
}

int MemoryHierarchy::getTotalAccess() const
{
    return totalAccess;
}

void MemoryHierarchy::setTotalAccess(int value)
{
    totalAccess = value;
}

int MemoryHierarchy::getTotalCycles() const
{
    return totalCycles;
}

void MemoryHierarchy::setTotalCycles(int value)
{
    totalCycles = value;
}

ReplacementPolicy MemoryHierarchy::getReplacementPolicy() const
{
    return replacementPolicy;
}

void MemoryHierarchy::setReplacementPolicy(const ReplacementPolicy &value)
{
    replacementPolicy = value;
}

long long **MemoryHierarchy::getHdd() const
{
    return hdd;
}

void MemoryHierarchy::setHdd(long long **value)
{
    hdd = value;
}
