#include <bits/stdc++.h>

using namespace std;

const int TAMMAX = 40;
int M[TAMMAX][TAMMAX];

vector<int> valores;
vector<int> pesos;

int mochila_botom_up(int C, int n);

int main()
{
    int C, // Capacidade da mochila
        n; // Número de itens

    // Inicializando matriz com memset
    memset(M, -1, sizeof(M));

    cin >> C >> n;
    for(int i = 0; i < n; i++)
    {
        int valor, peso;
        cin >> valor >> peso;
        valores.push_back(valor);
        pesos.push_back(peso);
    }

    cout << mochila_botom_up(C, n) << endl;
    return 0;
}

int mochila_botom_up(int C, int n)
{
    for(int cr = 0; cr <= C; cr++)
    {
        for(int i = n; i >= 0; i--)
        {
            if(cr == 0 || i == n)
                M[i][cr] = 0;
            else if(pesos[i] > cr)
                M[i][cr] = M[i+1][cr];
            else
                M[i][cr] = max(valores[i] + M[i+1][cr-pesos[i]], M[i+1][cr]);            
        }
    }

    return M[0][C];
}