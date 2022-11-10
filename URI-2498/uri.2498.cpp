#include <bits/stdc++.h>

using namespace std;

const int TAMMAX = 1000;
int M[TAMMAX][TAMMAX];

vector<int> pesos;
vector<int> valores;

int mochila_botom_up(int C, int N);

int main()
{

    int W, V, C, N, H = 0; // C: Capacidade da mochila
                         // N: Numero de livros
                         //H: numero de casos de teste

    // Inicializando matriz com memset
    memset(M, -1, sizeof(M));

    while(cin >> N >> C){

        if(N == 0 && C == 0){
            break;
        }

        for(int i = 0; i < N; i++){
            // W: peso de cada livro
            // V: grau de interesse

            cin >> W >> V;
            pesos.push_back(W);
            valores.push_back(V);

        }
        int M = mochila_botom_up(C, N);
        H++;
        cout << "Caso " << H << ": " << M << endl;

        pesos.clear();
        valores.clear();
    }                                                                       
      
    return 0;
}

int mochila_botom_up(int C, int N)
{

    for(int cr = 0; cr <= C; cr++)
    {
        for(int i = N; i >= 0; i--)
        {
            if(cr == 0 || i == N)
                M[i][cr] = 0;
            else if(pesos[i] > cr)
                M[i][cr] = M[i+1][cr];
            else
                M[i][cr] = max(valores[i] + M[i+1][cr-pesos[i]], M[i+1][cr]);            
        }
    }

    return M[0][C];
}