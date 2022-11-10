#include <bits/stdc++.h>

using namespace std;

const int TAMMAX = 1000;
int M[TAMMAX];

vector<int> pesos;
vector<int> valores;

int mochila_botom_up(int T, int N);

int main()
{

    int D, P, T, N, H = 0; 
    //N: Numero de livros
    //H: numero de casos de teste

    // Inicializando matriz com memset
    memset(M, 0, sizeof(M));

    while(cin >> N >> T){

        if(N == 0){
            break;
        }

        for(int i = 0; i < N; i++){
            // D: duraçao do brinquedo
            // P: pontuaçao do brinquedo

            cin >> D >> P;
            pesos.push_back(D);
            valores.push_back(P);

        }
       
        mochila_botom_up(T, N);
        
        H++;
        cout << "Instancia " << H << endl;
        cout << mochila_botom_up(T, N) << endl;
        cout << "\n";

        pesos.clear();
        valores.clear();
    }                                                                       
      
    return 0;
}

int mochila_botom_up(int T, int N)
{
    for(int cr = 0; cr <= T; cr++)
    {
        for(int i = 0; i < N; i++)
        {
             if(pesos[i] <= cr)
                M[cr] = max(M[cr], M[cr-pesos[i]] + valores[i]);         
        }
    }

    return M[T];
}