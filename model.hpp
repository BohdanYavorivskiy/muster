
#ifndef model_hpp
#define model_hpp

#include <assert.h>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

class model
{
public:
    model(int _L, int _Ntrials, int _D)
    {
        this->L = _L;
        this->N = pow(_L, _D);
        D = _D;
        this->N_trials = _Ntrials;
        nbr.reserve(N);
        init();
    }
    void init();
    // void print_nbr(int i){std::cout<<std::get<0>(nbr[i])<<"    "<<std::get<1>(nbr[i])<<"
    // "<<std::get<2>(nbr[i])<<"    "<<std::get<3>(nbr[i])<<std::endl;}
    int get_L() { return L; }
    int get_N() { return N; }
    int get_Ntrials() { return N_trials; }
    inline int get_nbr(const int i, const int number) const { return nbr[i][number]; }

private:
    int L;
    int N;
    int D;
    int N_trials;
    std::vector<std::vector<int>> nbr;
};

#endif
