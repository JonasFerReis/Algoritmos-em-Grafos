#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> parDeInt;

void dijkstra(map<parDeInt, vector<pair<parDeInt, int>>> mapa, int origem, int destino, int capacidadeDoTanque, int n){

    map<parDeInt, int> x;
    map<parDeInt, bool> vizitados;
    int inf = 1000000;

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= capacidadeDoTanque; j++){
            x[make_pair(i, j)] = inf;
            vizitados[make_pair(i, j)] = false;
        }
    }

    x[make_pair(origem, 0)] = 0;

    priority_queue< pair<int, parDeInt>, vector<pair<int, parDeInt>>, greater<pair<int, parDeInt>> > heap;

    heap.push(make_pair(0, make_pair(origem, 0)));

    pair<int, parDeInt> vertice;
    parDeInt u;

    while(!heap.empty()){
        vertice = heap.top();
        heap.pop();

        u = vertice.second;

        if (vizitados[u]){
            continue;
        }
        
        vizitados[u] = true;
        
        int custo;
        for (auto it = mapa[u].begin(); it < mapa[u].end(); it++){
            pair<parDeInt, int> v = *it;
            parDeInt vizinho = v.first;
            int peso = v.second;

            custo = x[u] + peso;
            if (custo < x[vizinho]){
                x[vizinho] = custo;
                heap.push(make_pair(x[vizinho], vizinho));
            }
        }
    }

    int result = x[make_pair(destino, 0)];
    if (result != inf){
        cout << result << endl;
    }
    else {
        cout << "sem solucao" << endl;
    }
}

void gerarMapa(vector<parDeInt> *arestasPrincipais, int precoCombustivel[], int capacidadeDoTanque, int n, int origem, int destino){

    map<parDeInt, vector<pair<parDeInt, int>>> mapa;

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= capacidadeDoTanque; j++){
            mapa[make_pair(i, j)].push_back(make_pair(make_pair(i, j + 1), precoCombustivel[i]));
        }
    }

    for (int u = 0; u < n; u++){
        for (auto it = arestasPrincipais[u].begin(); it < arestasPrincipais[u].end(); it++){
            parDeInt v = *it;

            int combustivelAtual = v.second;
            while (combustivelAtual <= capacidadeDoTanque){
                mapa[make_pair(u, combustivelAtual)].push_back(make_pair(make_pair(v.first, combustivelAtual - v.second), 0));
                combustivelAtual++;
            }
        }
    }

    dijkstra(mapa, origem, destino, capacidadeDoTanque, n);
}

int main(){

    int n, m;
    cin >> n >> m;

    int precoCombustivel[n];
    for (int i = 0; i < n; i++){
        cin >> precoCombustivel[i];
    }

    vector<parDeInt> *arestasPrincipais = new vector<parDeInt>[n];
    int v1, v2, peso;
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2 >> peso;
        arestasPrincipais[v1].push_back(make_pair(v2, peso));
    }

    int origem, destino, capacidadeDoTanque, qtdeDeTestes;
    cin >> qtdeDeTestes;
    for (int i = 0; i < qtdeDeTestes; i++){
        cin >> capacidadeDoTanque >> origem >> destino;
        gerarMapa(arestasPrincipais, precoCombustivel, capacidadeDoTanque, n, origem, destino);
    }

    return 0;
}