#include <iostream>

#include "UnionFind.h"

/* @brief Initializes n components in the UnionFind class
 * @param {int} n - Determines the length of the id array
 */
UnionFind::UnionFind(int n) {
    for (int i = 0; i < n; i++) {
        id.push_back(i);
        sz.push_back(1);
    }
}

/* @brief Finds the root object of i
 * @param {int} i - Object whose root is being searched
 * @returns {int}
 */
int UnionFind::root(int i) {
    while(id[i] != i) {
        i = id[i];
    }

    return i;
}

/* @brief Joins the components in which p and q are located by its roots
 * @param {int} p - Object from some component
 * @param {int} q - Object from some component
 */
void UnionFind::createUnion(int p, int q) {
    int pRoot = this->root(p);
    int qRoot = this->root(q);

    if(this->id[pRoot] == this->id[qRoot]) {
        return;
    }

    if(this->sz[pRoot] < this->sz[qRoot]) {
        this->id[pRoot] = qRoot;
        this->sz[qRoot] += this->sz[pRoot];
    } else {
        this->id[qRoot] = pRoot;
        this->sz[pRoot] += this->sz[qRoot];
    }
}

/* @brief Determines if p and q are in the same component
 * @param {int} p - Object from some component
 * @param {int} q - Object from some component
 * @returns {bool}
 */
bool UnionFind::connected(int p, int q) {
    return this->root(p) == this->root(q);
}

/* @brief Prints the values of the array below its indexes
 */
void UnionFind::printArray() {
    for(size_t i = 0; i < this->id.size(); i++) std::cout << i << "|" ;
    std::cout << std::endl;

    for(size_t i = 0; i < this->id.size(); i++) std::cout << "--" ;
    std::cout << std::endl;

    for(size_t i = 0; i < this->id.size(); i++) std::cout << this->id[i] << "|";

    std::cout << std::endl << std::endl;
}



