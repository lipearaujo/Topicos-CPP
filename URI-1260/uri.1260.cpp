#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{
    int N;
    double cont = 0.0;
    string mensagem;
    map<string,double> mapa;
    map<string,double>::iterator it;
    
    cin >> N;
    cin.get();
    getline(cin, mensagem);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<=N; i++){

        if(i == 0){
            continue;
        }

        while (getline(cin, mensagem))
        {
            if(mensagem == "\0"){
               break;
            }
          
            mapa[mensagem]++;
            cont++;
        }
		
        for(it=mapa.begin(); it!=mapa.end(); it++){
            cout << it->first << " " << fixed << setprecision(4) << it->second/cont*100 << endl;
        }
        
        if(i != N){
            cout << endl;
        }

        cont = 0.0;
        mapa.clear();
        
    }

    return 0;
}