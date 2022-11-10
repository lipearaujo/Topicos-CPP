#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{
    int N, j=0, tam;
    string mensagem;
    
    cin >> N;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<=N; i++)
    {
        
        getline(cin, mensagem);
        if(i == 0)
        {   
            continue;
        }

        tam = 0;
        j = 0;

        for(char c:mensagem )
        {
            if(isalpha(c))
            {
                mensagem[j] = mensagem[j] + 3;     
            }
            j++;
        }

        reverse(mensagem.begin(), mensagem.end());

        tam = (mensagem.size())/2;
        
        for(int k = tam; k <= mensagem.length(); k++)
        {
            mensagem[k]--; 
        }
       
        cout << mensagem;
        cout << endl;
    }

    return 0;
}