#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

class UnionFind
{
public:
    UnionFind(int n);
    void createUnion(int p, int q);
    bool connected(int p, int q);
    void printArray();

private:
    std::vector<int> id;
    std::vector<int> sz;
    int root(int p);
};

#endif /*UNION_FIND_H*/
