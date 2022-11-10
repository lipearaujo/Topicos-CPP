#if !defined __grafo_h
#define __grafo_h

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue> // queue e priority_queue

using namespace std;

const int TAMVERT = 50;

struct Aresta
{
    bool eAdj;
    int  peso;
};

typedef struct Aresta Aresta;

enum Cor {B, C, P};

struct Vertice
{
    int rotulo;
    Cor cor;
    int pred;     // predecessor
    int dist;
    int t_visita;
    int t_termino;
};

typedef struct Vertice Vertice;

vector<Vertice> vertices;

Aresta Grafo[TAMVERT][TAMVERT];

void inicVertice(Vertice &v, int rot);
void inicVertices(int numVertices);
void inicGrafo(int numVertices);

void Djikstra(int numVertices, int origem);

#endif

int main()
{
    int numV, numA;
    int v_origem, v_destino, peso;
    int C,V;

    cin >> C;
    cin >> V;
    
    for(int j = 0; j < V; j++){

        cin >> numV >> numA;    
        inicVertices(numV);
        inicGrafo(numV);

        for(int i = 0; i < numA; i++)
        {
            cin >> v_origem >> v_destino >> peso;
            Grafo[v_origem][v_destino].eAdj = true;
            Grafo[v_origem][v_destino].peso = peso;
            //Grafo[v_destino][v_origem].eAdj = true;
        }
    }
 
    Djikstra(numV, 0);

    return 0;
}

void inicVertice(Vertice& v, int rot)
{
    v.rotulo = rot;
    v.cor = B;
    v.pred = -1; // NULL
    v.dist = INT_MAX; // maior valor inteiro possível
    v.t_visita = -1, v.t_termino = -1;
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
            Grafo[i][j].peso = 0;
        }
}



// iPair -> é um par de inteiros.
typedef pair<int, int> iPair;

void Djikstra(int numVertices, int origem)
{
    priority_queue< iPair, vector<iPair>, greater<iPair> > Q;

    vertices[origem].dist = 0;
    Q.push(make_pair(0, origem));
    
    while( !Q.empty() )
    {
        int u = Q.top().second;
        Q.pop();

        for(int v = 0; v < numVertices; v++)
        {
            if(Grafo[u][v].eAdj)
            {
                int peso = Grafo[u][v].peso;
                if(vertices[v].dist > vertices[u].dist + peso)
                {
                    vertices[v].dist = vertices[u].dist + peso;
                    vertices[v].pred = u;
                    Q.push(make_pair(vertices[v].dist, v));
                }
            }
        }
    }
}

