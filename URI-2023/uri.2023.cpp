#include <bits/stdc++.h>
#include <cctype>

using namespace std;

bool compare_nocase (const string& first, const string& second)
{
    unsigned int i=0;
    while((i<first.length()) && (i<second.length()))
    {
        if(tolower(first[i])<tolower(second[i]))
        {
            return true;
        }else
        {
            if(tolower(first[i])>tolower(second[i]))
            {
                return false;
            }
        }
        i++;
    }
    return (first.length() < second.length());
}

int main()
{
    list<string> lista;
    list<string>::iterator it;
    string nome;    

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /*lista.insert(lista.end(), "ana");
    lista.insert(lista.end(), "Julio");
    lista.insert(lista.end(), "gABRIEL");
    lista.insert(lista.end(), "VANESSA");
    lista.insert(lista.end(), "cArLoS");*/

    do
    {
        getline(cin, nome);
        lista.push_back(nome);

    } while (nome.length() != 0);
      
    lista.sort(compare_nocase);

    cout << lista.back() << endl;

    return 0;
}

