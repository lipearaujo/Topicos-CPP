#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{
    int N, maior=0, c=0;
    string texto;
    char frequenciaLetra;

    cin >> N;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<=N; i++)
    {
        getline(cin, texto);
        
        if(i == 0)
        {
            continue;
        }

        maior = 0;
        c = 0;
        int caractere[123] = {0};
        
        for(int k=0; k<texto.length(); k++)
        {
            if(isupper(texto[k]))
            {
                texto[k] = tolower(texto[k]);
            }

            if(islower(texto[k]))
            {
                c = texto[k];
                switch(c)
                {
                    case 'a': caractere[97]++;
                    break;

                    case 'b': caractere[98]++;
                    break;

                    case 'c': caractere[99]++;
                    break;

                    case 'd': caractere[100]++;
                    break;

                    case 'e': caractere[101]++;
                    break;

                    case 'f': caractere[102]++;
                    break;

                    case 'g': caractere[103]++;
                    break;

                    case 'h': caractere[104]++;
                    break;

                    case 'i': caractere[105]++;
                    break;

                    case 'j': caractere[106]++;
                    break;

                    case 'k': caractere[107]++;
                    break;

                    case 'l': caractere[108]++;
                    break;

                    case 'm': caractere[109]++;
                    break;

                    case 'n': caractere[110]++;
                    break;

                    case 'o': caractere[111]++;
                    break;

                    case 'p': caractere[112]++;
                    break;

                    case 'q': caractere[113]++;
                    break;

                    case 'r': caractere[114]++;
                    break;

                    case 's': caractere[115]++;
                    break;

                    case 't': caractere[116]++;
                    break;

                    case 'u': caractere[117]++;
                    break;

                    case 'v': caractere[118]++;
                    break;

                    case 'w': caractere[119]++;
                    break;

                    case 'x': caractere[120]++;
                    break;

                    case 'y': caractere[121]++;
                    break;

                    case 'z': caractere[122]++;
                    break;
                }
            }
            
            if(caractere[c] > maior)
            {
                maior = caractere[c];
            }
        }

        frequenciaLetra = ' ';
        
        for(int printaLetra = 97; printaLetra < 123; printaLetra++)
        {
            if(caractere[printaLetra] == maior && caractere[printaLetra] != 0)
            {
                frequenciaLetra = printaLetra;
                cout<<frequenciaLetra;
            }
        }
        cout<<endl;
    }
    return 0;
}