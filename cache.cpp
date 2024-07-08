#include "cache.h"

Cache::Cache()
{

}
Cache::Cache(int cycles, int penalty, long long size, int blockSize)
{
    this->cycles = cycles;
    this->penalty = penalty;
    accessNum = 0;
    hits = 0;
    misses = 0;
    this->size = size;
    AMAT = cycles;
    valids = new bool[size];
    for(int i = 0; i < size; i++)
        valids[i] = false;
    tags = new long long[size];
    values = new long long*[12];   //we consider max words/block because 2nd parameter of array can't be dynamic
    for(int i = 0; i < 12; i++)
        values[i] = new long long[size];
    this->blockSize = blockSize;
}

int Cache::getCycles() const
{
    return cycles;
}

void Cache::setCycles(int value)
{
    cycles = value;
}

int Cache::getPenalty() const
{
    return penalty;
}

void Cache::setPenalty(int value)
{
    penalty = value;
}

int Cache::getAccessNum() const
{
    return accessNum;
}

void Cache::setAccessNum(int value)
{
    accessNum = value;
}

int Cache::getHits() const
{
    return hits;
}

void Cache::setHits(int value)
{
    hits = value;
}

int Cache::getMisses() const
{
    return misses;
}

void Cache::setMisses(int value)
{
    misses = value;
}

long long Cache::getSize() const
{
    return size;
}

void Cache::setSize(long long value)
{
    size = value;
}

double Cache::getAMAT() const
{
    return AMAT;
}

void Cache::setAMAT(double value)
{
    AMAT = value;
}

bool *Cache::getValids() const
{
    return valids;
}

void Cache::setValids(bool *value)
{
    valids = value;
}

long long *Cache::getTags() const
{
    return tags;
}

void Cache::setTags(long long *value)
{
    tags = value;
}

long long **Cache::getValues() const
{
    return values;
}

void Cache::setValues(long long **value)
{
    values = value;
}

int Cache::getBlockSize() const
{
    return blockSize;
}

void Cache::setBlockSize(int value)
{
    blockSize = value;
}
