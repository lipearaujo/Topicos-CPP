#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{   
    string digito;
    char d;
    int sz;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(getline(cin, digito))
    {
        if(digito.compare("0 0") == 0)
        {
            exit(0);
        }
           
        d = digito[0];
        digito.erase(0,2);
        sz = digito.size();
        digito.erase(remove(digito.begin(), digito.begin() + sz, d), digito.end()); 
        
        while(digito[0] == '0')

        {

            if(digito.size() == 1){
                break;
            }
 

            digito.erase(0,1);

        }
            
        if(digito.size() == 0){
            cout << 0 << endl;
        }else{
            cout << digito << endl;
        }
        
    }
    
    return 0;
}