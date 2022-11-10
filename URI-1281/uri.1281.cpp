#include <iostream> // cin, cout
#include <iomanip>  // setprecision, fixed
#include <string>
#include <map> // tipo map da STL

using namespace std;

int main()
{
    int N, M, P, 
        qtde; // quantidade de um determinado produto
              // que D. Parcinova deseja comprar.
    string nome_Produto;
    double valor_Produto, total_Gasto;
    // Nome do produto, valor do produto.
    map<string, double> produtos;

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        produtos.clear();
        cin >> M;
        for(int j = 0; j < M; j++)
        {
            cin >> nome_Produto;
            cin >> valor_Produto;
            produtos.insert(pair<string, double>(nome_Produto, valor_Produto));
        }
        cin >> P;
        total_Gasto = 0.0;
        for(int j = 0; j < P; j++)
        {
            cin >> nome_Produto;
            cin >> qtde;

            /*for(map<string, double>::iterator it = produtos.begin(); 
                it != produtos.end(); ++it)
            {
                if(nome_Produto == it->first)
                    total_Gasto += it->second * qtde;
            }*/

            auto result = produtos.find(nome_Produto);
            if(result != produtos.end())
                total_Gasto += result->second * qtde;

        }
        cout << "R$ " << fixed << setprecision(2) << total_Gasto << endl;
    }


    return 0;
}