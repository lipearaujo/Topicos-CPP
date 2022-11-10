#if !defined __grafo_h
#define __grafo_h

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue> 

using namespace std;

int cont = 0;

const int TAMVERT = 50;

struct Aresta
{
    bool eAdj;
    
};

typedef struct Aresta Aresta;

enum Cor {B, C, P};

struct Vertice
{
    int rotulo;
    Cor cor;
    int pred;     
};

typedef struct Vertice Vertice;

vector<Vertice> vertices;

Aresta Grafo[TAMVERT][TAMVERT];

void inicVertice(Vertice &v, int rot);
void inicVertices(int numVertices);
void inicGrafo(int numVertices);
void DFS(int inicio, int numVertices);
void DFS_Visit(int numVertices, int u);

#endif

int main()
{
    int numV, numA, T, inicio;
    int v_origem, v_destino;

    cin >> T;
    for(int casos = 0; casos<T; casos++){
        cin >> inicio;
        cin >> numV >> numA;

        inicVertices(numV);
        inicGrafo(numV);

        for(int i = 0; i < numA; i++){
        
            cin >> v_origem >> v_destino;
            Grafo[v_origem][v_destino].eAdj = true;
            Grafo[v_destino][v_origem].eAdj = true;
        }

        DFS(inicio, numV);

        cont = cont * 2;
        cout << cont << endl;

        vertices.clear();
        inicio = 0;
        cont = 0;
    }
    
    return 0;
}

void inicVertice(Vertice& v, int rot)
{
    v.rotulo = rot;
    v.cor = B;
    v.pred = -1; // NULL
}

void inicVertices(int numVertices)
{
    for(int i = 0; i < numVertices; i++)
    {
        Vertice v;
        inicVertice(v, i);
        vertices.push_back(v);
    }
}

void inicGrafo(int numVertices)
{
    for(int i = 0; i < numVertices; i++)
        for(int j = 0; j < numVertices; j++)
        {
            Grafo[i][j].eAdj = false;
            
        }
}

void DFS(int inicio, int numVertices)
{
    for(int u = inicio; u < numVertices; u++){
        if(vertices[u].cor == B){
            DFS_Visit(numVertices, u);
        }
    }
}

void DFS_Visit(int numVertices, int u)
{
    vertices[u].cor = C;
   
    for(int v = 0; v < numVertices; v++)
    {
        if(Grafo[u][v].eAdj && vertices[v].cor == B)
        {
            cont++;
            vertices[v].pred = u;
            DFS_Visit(numVertices, v);

        }
    }

    vertices[u].cor = P;

}
