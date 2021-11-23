#include "model.hpp"

void model::init()
{
    nbr.resize(N);
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned j = 0; j < D; j++)
        {
            unsigned n1 = pow(L, j + 1) * (i / ((unsigned)pow(L, j + 1)))
                          + fmod(i + pow(L, j), pow(L, j + 1));
            unsigned n2 = pow(L, j + 1) * (i / ((unsigned)pow(L, j + 1)))
                          + fmod(pow(L, j + 1) + i - pow(L, j), pow(L, j + 1));

            nbr[i].push_back(n1);
            nbr[i].push_back(n2);

            std::cout << ">>>>>>>>i =" << i << "   "
                      << "n1/n2" << n1 << " " << n2;
        }

        //        row = std::get<0>(x_y_dic[i]);
        //        column = std::get<1>(x_y_dic[i]);
        //        up = site_dic[std::make_tuple((row-1+L)%L, column)];
        //        right = site_dic[std::make_tuple(row, (column+1)%L)];
        //        dn = site_dic[std::make_tuple((row+1)%L, column)];
        //        left = site_dic[std::make_tuple(row, (column-1+L)%L)];
        //        nbr[i] = std::make_tuple(right, up, left,dn);
    }
}

int model::get_nbr(const int i, const int number)
{
    return nbr[i][number];
    //    switch(number)
    //    {
    //        case 0:
    //            return std::get<0>(nbr[i]);
    //        case 1:
    //            return std::get<1>(nbr[i]);
    //        case 2:
    //            return std::get<2>(nbr[i]);
    //        case 3:
    //            return std::get<3>(nbr[i]);
    //    }
}
