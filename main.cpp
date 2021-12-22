//
//  main.cpp
//  Transport
//
//  Created by Shaheen Acheche on 29/09/2017.
//  Copyright © 2017 Shaheen Acheche. All rights reserved.
//

#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <tuple>
#include <vector>
#include <stdio.h>
#include <unordered_set>
// #include <boost/filesystem.hpp>
#include "config.hpp"
#include "model.hpp"
#include "tools.hpp"

using i_vector = std::vector<int>;


// This is probably not needed.
double deltaE(int S0, int Sn)
{
    double H;
    int J;
    J = 1;
    H = 0;
    // '''Energy difference for a spin flip'''

    return 2 * S0 * (H + J * Sn);
}

int main(int argc, const char *argv[])
{
    const parameters params = get_params();
    model mod(params.L, params.Ntrials, params.D);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, mod.get_N() - 1);
    std::uniform_real_distribution<> dis_real(0, 1);

    d_vector magnetization(mod.get_Ntrials());
    d_vector energy(mod.get_Ntrials());
    d_vector tNum = linspace(params.Tmin, params.Tmax, params.nT, true);
    d_vector meanMag(tNum.size());
    d_vector meanEne(tNum.size());
    i_vector pocket/*, cluster*/;
    std::unordered_set<int> cluster;
    i_vector S(mod.get_N());
    double beta;
    double p;
    int k, s;

    for (size_t i = 0; i < tNum.size(); i++)
    {
        std::ofstream txt;
        txt.open("D" + std::to_string(params.D) + "_L" + std::to_string(mod.get_L()) + "_Ntrials"
                 + std::to_string(mod.get_Ntrials()) + "_t" + std::to_string(i) + ".dat");

        std::cout << "Temperature =" << tNum[i] << std::endl;
        beta = 1. / tNum[i];
        p = 1. - std::exp(-2 * beta);
        initLattice(S);
        for (size_t j = 0; j < mod.get_Ntrials(); j++)
        {
            energy[j] = 0;
            k = dis(gen);
            pocket.push_back(k);
//            cluster.push_back(k);
            cluster.insert(k);
            while (pocket.size() != 0)
            {
                s = randomChoice(pocket);
                for (int kk = 0; kk < mod.nbrCountForNode(s); kk++)
                {
                    const int nbr = mod.get_nbr(s, kk);
                    if (S[nbr] == S[s])
                    {
                        // if (!isInVector(cluster, nbr))
                        const std::unordered_set<int>::const_iterator nbrI = cluster.find(nbr);
                        if (nbrI == cluster.cend())
                        {
                            if (dis_real(gen) < p)
                            {
                                pocket.push_back(nbr);
//                                cluster.push_back(nbr);
                                cluster.insert(nbr);

                            }
                        }
                    }
                }
                pocket.erase(std::remove(pocket.begin(), pocket.end(), s), pocket.end());
            }
            std::cout << "1"<< std::endl;
            //            for (size_t l = 0; l < cluster.size(); l++)
            //            {
            //                S[cluster[l]] = -S[cluster[l]];
            //            }
            for (std::unordered_set<int>::const_iterator nbrI = cluster.cbegin();
                 nbrI != cluster.cend(); ++nbrI)
            {
                S[*nbrI] = -S[*nbrI];
            }
            for (int a = 0; a < mod.get_N(); a++)
            {
                double nbrEnergy = 0;
                for (int b = 0; b < mod.nbrCountForNode(a); b++)
                {
                    nbrEnergy += S[a] * S[mod.get_nbr(a, b)];
                }
                energy[j] += (nbrEnergy / 2.0);
            }
            std::cout<<"e_ "<< energy[j]<<std::endl;
            cluster.clear();
            magnetization[j] = std::abs(std::accumulate(S.begin(), S.end(), 0.0));
            txt << params.D << "\t" << params.L << "\t" << tNum[i] << "\t" << magnetization[j]
                << "\t" << energy[j] << std::endl;
        }

        txt.close();
    }

    std::cout << "Done !" << std::endl;

    return 0;
}
