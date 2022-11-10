#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{
    int N;
    string mensagem;

    cin >> N;
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for(int i=0; i<N; i++){
        
        getline(cin, mensagem);
      
        int tam = 0;
        tam = (mensagem.size()/2);
        
        reverse(mensagem.begin(), mensagem.begin() + tam);
        reverse(mensagem.begin() + tam, mensagem.begin() + mensagem.size());
        
        cout << mensagem;
        cout << endl;
    }

    return 0;
}