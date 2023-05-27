#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> parDeInt;

void dijsktra(vector<parDeInt> *listaAdj, int origem, int n, int d){

    vector<int> x;
    vector<bool> vizitados;
    int inf = 1000000;

    x.assign(n + 1, inf);
    vizitados.assign(n + 1, false);

    x[origem] = 0;

    priority_queue< parDeInt, vector<parDeInt>, greater<parDeInt> > heap;

    heap.push(make_pair(0, origem));

    parDeInt vertice;
    int u;

    while (!heap.empty()){
        vertice = heap.top();
        heap.pop();

        u = vertice.second;

        if (vizitados[u]){
            continue;
        }

        vizitados[u] = true;

        int custo;
        for (auto it = listaAdj[u].begin(); it < listaAdj[u].end(); it++){
            parDeInt v = *it;
            int vizinho = v.first;
            int peso = v.second;

            custo = x[u] + peso;
            if (custo < x[vizinho]){
                x[vizinho] = custo;
                heap.push(make_pair(x[vizinho], vizinho));
            }
        }
    }

    int result = x[n];
    cout << result * d << endl << endl;
}

int main(){

    vector<parDeInt> *listaAdj;

    int cont = 1;
    while (!cin.eof()){
        int n, m;
        cin >> n >> m;
        
        listaAdj = new vector<parDeInt>[n + 1];

        int v1, v2, peso;
        for (int i = 1; i <= m; i++){
            cin >> v1 >> v2 >> peso;
            listaAdj[v1].push_back(make_pair(v2, peso));
            listaAdj[v2].push_back(make_pair(v1, peso));
        }

        int d, k;
        cin >> d >> k;
        if (k >= d){
            cout << "Instancia " << cont << endl;
            dijsktra(listaAdj, 1, n, d);
        }
        else {
            cout << "impossivel" << endl << endl;
        }
        cont++;
    }
    return 0;
}