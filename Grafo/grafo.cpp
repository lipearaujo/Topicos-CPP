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
void BFS(int numVertices, int origem);
void DFS(int numVertices);
void DFS_Visit(int numVertices, int u, int &tempo);

void Djikstra(int numVertices, int origem);

void listVertices(int numVertices);
void listGrafo(int numVertices);

#endif

int main()
{
    int numV, numA;
    int v_origem, v_destino, peso;

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

    //BFS(numV, 1);
    //DFS(numV);

    Djikstra(numV, 0);

    listVertices(numV);
    listGrafo(numV);
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

void BFS(int numVertices, int origem)
{
    queue<int> Q;
    // Inicializando todos os vértices.
    inicVertices(numVertices);

    // Inicializando vértice origem.
    vertices[origem].cor  = C;
    vertices[origem].dist = 0;
    vertices[origem].pred = -1;

    Q.push(origem);

    while(!Q.empty())
    {
        int u = Q.front(); // retorna o primeiro da fila
        Q.pop();           // retira o primeiro da fila

        for(int v = 0; v < numVertices; v++)
        {
            if(Grafo[u][v].eAdj && vertices[v].cor == B)
            {
                vertices[v].cor  = C; 
                vertices[v].dist = vertices[u].dist + 1;
                vertices[v].pred = u;
                Q.push(v);
            }
        }
        vertices[u].cor = P;
    }
}

void DFS(int numVertices)
{
    inicVertices(numVertices);
    int tempo = 0;
    for(int u = 0; u < numVertices; u++)
        if(vertices[u].cor == B)
            DFS_Visit(numVertices, u, tempo);
}

void DFS_Visit(int numVertices, int u, int &tempo)
{
    vertices[u].cor = C;
    tempo++;
    vertices[u].t_visita = tempo;

    for(int v = 0; v < numVertices; v++)
    {
        if(Grafo[u][v].eAdj && vertices[v].cor == B)
        {
            vertices[v].pred = u;
            DFS_Visit(numVertices, v, tempo);
        }
    }

    vertices[u].cor = P;
    tempo++;
    vertices[u].t_termino = tempo;
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

void listVertices(int numVertices)
{
    for(int i = 0; i < numVertices; i++)
    {
        cout << "Rotulo | Cor | Distancia | Predecessor | Visita | Termino \n";
        cout << setw(6) << vertices[i].rotulo 
             << setw(5) << vertices[i].cor 
             << setw(10) << vertices[i].dist 
             << setw(10) << vertices[i].pred 
             << setw(10) << vertices[i].t_visita
             << setw(10) << vertices[i].t_termino
             << endl;
    }
}

void listGrafo(int numVertices)
{
    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < numVertices; j++)
            cout << setw(4) << Grafo[i][j].eAdj;
        cout << endl;
    }
}