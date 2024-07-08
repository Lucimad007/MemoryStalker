#ifndef MEMORYHIERARCHY_H
#define MEMORYHIERARCHY_H

#include "cache.h"

enum ReplacementPolicy {LRU, FIFO, RANDOM};

class MemoryHierarchy
{
public:
    MemoryHierarchy();

private:
    Cache L1, L2, L3, RAM;      //we see RAM as cache of the HDD
    int level = 3;  //1, 2, 3
    long long *hdd;     //hard drive disk (we see it flat)
    int totalAccess = 0;
    int totalCycles = 0;
    ReplacementPolicy replacementPolicy = LRU;
};

#endif // MEMORYHIERARCHY_H
