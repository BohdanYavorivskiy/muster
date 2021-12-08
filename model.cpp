#include "model.hpp"

static int power(int N,int P){ return (P==0)? 1: N*power(N,P-1); }
static int mod(int a, int b){return a %b;}

void model::init()
{   
    
    std::vector<std::vector<int>> neigh1(power(L,D-1));
    int u=0;
    for (unsigned int k = 0; k < power(L,D-1);k++){
        for (unsigned int p = 0; p<L;p++){
            neigh1[k].push_back(u);
            u++;
        }
    }
    nbr.resize(N);
    u = 0;
    for (unsigned int a = 0; a < power(L,D-1); a++){
        for (unsigned int b = 0; b<L;b++){
            for (unsigned int j = 0; j<D;j++){
                unsigned int ne2 = neigh1[a][b]+power(L,j); 
                unsigned int ne1 = neigh1[a][b]-power(L,j);                 
            if (j==0){
                if (b==0){ 
                nbr[u].push_back(ne2);
                std::cout << ">>>>>>>>i =" << u << "   "
                   << "n2 " << ne2 << std::endl;
                }
                else if (b==L-1){
                nbr[u].push_back(ne1);
                std::cout << ">>>>>>>>i =" << u << "   "
                   << "n1 " << ne1 << std::endl;
                }
                else {
                nbr[u].push_back(ne1);
                nbr[u].push_back(ne2);
                std::cout << ">>>>>>>>i =" << u << "   "
                   << "n1 " << ne1 << std::endl;
                std::cout << ">>>>>>>>i =" << u << "   "
                   << "n2 " << ne2 << std::endl;
                }
            }
            else {
                if (mod(a,power(L,j))<power(L,j-1)) {
                nbr[u].push_back(ne2);
                std::cout << ">>>>>>>>i =" << u << "   "
                   << "n2 " << ne2 <<  std::endl;
                }
                else if (mod(a,power (L,j)) >= power(L,j-1)*(L-1)) {
                nbr[u].push_back(ne1);
                std::cout << ">>>>>>>>i =" << u << "   "
                   << "n1 " << ne1 << std::endl;
                }
                else {
                nbr[u].push_back(ne1);
                nbr[u].push_back(ne2);
                std::cout << ">>>>>>>>i =" << u << "   "
                   << "n1 " << ne1 << std::endl;
                std::cout << ">>>>>>>>i =" << u << "   "
                   << "n2 " << ne2 << std::endl;
                }
            }
            }
        std::cout << nbrCountForNode(u)<< std::endl;    
        u++;
        }
    }
    
    }



