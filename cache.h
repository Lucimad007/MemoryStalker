#ifndef CACHE_H
#define CACHE_H


class Cache
{
public:
    Cache();
    Cache(int cycles, int penalty, long long size, int blockSize);

    int getCycles() const;
    void setCycles(int value);

    int getPenalty() const;
    void setPenalty(int value);

    int getAccessNum() const;
    void setAccessNum(int value);

    int getHits() const;
    void setHits(int value);

    int getMisses() const;
    void setMisses(int value);

    long long getSize() const;
    void setSize(long long value);

    double getAMAT() const;
    void setAMAT(double value);

    bool *getValids() const;
    void setValids(bool *value);

    long long *getTags() const;
    void setTags(long long *value);

    long long **getValues() const;
    void setValues(long long **value);

    int getBlockSize() const;
    void setBlockSize(int value);

    int value(int index, int offset);
    int tag(int index);
    int valid(int index);

private:
    int cycles;     //speed of acces
    int penalty;    //speed of next layer !
    int accessNum = 0;  //how many times we have used it
    int hits = 0;
    int misses = 0;
    long long size;
    int blockSize = 12;
    double AMAT;    //average memory access time
    bool *valids;
    long long *tags;
    long long **values;
};

#endif // CACHE_H
