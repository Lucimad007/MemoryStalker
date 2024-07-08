#ifndef MEMORYHIERARCHY_H
#define MEMORYHIERARCHY_H

#include "cache.h"

enum ReplacementPolicy {LRU, FIFO, RANDOM};

class MemoryHierarchy
{
public:
    MemoryHierarchy();
    MemoryHierarchy(int size);

    Cache getL1() const;
    void setL1(const Cache &value);

    Cache getL2() const;
    void setL2(const Cache &value);

    Cache getL3() const;
    void setL3(const Cache &value);

    Cache getRAM() const;
    void setRAM(const Cache &value);

    int getLevel() const;
    void setLevel(int value);

    int getTotalAccess() const;
    void setTotalAccess(int value);

    int getTotalCycles() const;
    void setTotalCycles(int value);

    ReplacementPolicy getReplacementPolicy() const;
    void setReplacementPolicy(const ReplacementPolicy &value);

    long long **getHdd() const;
    void setHdd(long long **value);

private:
    Cache L1, L2, L3, RAM;      //we see RAM as cache of the HDD
    int level = 3;  //1, 2, 3
    long long **hdd;     //hard drive disk
    int totalAccess = 0;
    int totalCycles = 0;
    ReplacementPolicy replacementPolicy = RANDOM;
};

#endif // MEMORYHIERARCHY_H
