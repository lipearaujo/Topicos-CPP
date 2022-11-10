#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{
    int i, j, bau = 0, x = 0, y = 0, aux = 0;
    int visitado[100][100] = {{0}};
    cin >> x;
    cin >> y;

    char Mapa[y][x];
    for(i=0; i<y; i++){
        for(j=0; j<x; j++){
            cin >> Mapa[i][j];
        }
    }
      

    i = 0;
    j = 0;
    while(i<y && j<x && visitado[i][j] == 0){
        visitado[i][j] = 1;

        if(Mapa[i][j] == '*'){
            bau = 1;
            visitado[i][j] = 1;
            break;
        }else{
            if(Mapa[i][j] == '>'){
                aux = 1;
                j++;
            }else{
                if(Mapa[i][j] == '<'){
                    aux = 2;
                    j--;
                }else{
                    if(Mapa[i][j] == '^'){
                        aux = 3;
                        i--;
                    }else{
                        if(Mapa[i][j] == 'v'){
                            aux = 4;
                            i++;
                        }else{
                            if(Mapa[i][j] == '.'){
                                if(aux == 1){
                                    j++;
                                }else{
                                    if(aux == 2){
                                        j--;
                                    }else{
                                        if(aux == 3){
                                            i--;
                                        }else{
                                            if(aux == 4){
                                                i++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }

    if(bau == 1){
        cout << '*' << endl;
    }else{
        cout << '!' << endl;
    }

    return 0;
}