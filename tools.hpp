
#ifndef tools_hpp
#define tools_hpp

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <limits.h>

using d_vector = std::vector<double>;

d_vector linspace(double min, double max, int nbr, bool endpoint = false);

void initLattice(std::vector<int> &S);

inline int randomChoice(const std::vector<int> &vec)
{
    assert(vec.size() != 0);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, INT_MAX);

    return vec[dis(gen) % vec.size()];
}

inline bool isInVector(const std::vector<int> &v, int elem)
{
    return std::find(v.cbegin(), v.cend(), elem) != v.cend();
}
#endif
