#ifndef CACHE_H
#define CACHE_H


class Cache
{
public:
    Cache();

private:
    int cycles;     //speed of acces
    int penalty;    //speed of next layer !
    int accessNum = 0;  //how many times we have used it
    int hits = 0;
    int misses = 0;
    int size;
    double AMAT;    //average memory access time
    bool *valids;
    long long *tags;
    long long **values;
};

#endif // CACHE_H
