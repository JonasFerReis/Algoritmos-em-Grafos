#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> parDeInt;

class UFDS{
    private:
        vector<int> rank;
        vector<int> pai;

    public:
        UFDS(int n){
            rank.assign(n, 0);
            pai.assign(n, 0);
            for (int i = 1; i <= n; i++){
                pai[i] = i;
            }
        }

        int buscarComponente(int i){
            if (pai[i] == i){
                return i;
            }
            else {
                pai[i] = buscarComponente(pai[i]);
                return pai[i];
            }    
        }

        bool mesmoComponente(int u, int v){
            if (buscarComponente(u) == buscarComponente(v)){
                return true;
            }
            else {
                return false;
            } 
        }
  
        void unirComponentes(int u, int v){
            if (mesmoComponente(u, v) == false){
                int c1 = buscarComponente(u), c2 = buscarComponente(v);

                if (rank[c1] > rank[c2]){
                    pai[c2] = c1;
                }
                else {
                    pai[c1] = c2;
                    if (rank[c1] == rank[c2]){
                        rank[c2]++;
                    }
                }
            }
        }
};

int kruskall(vector<pair<int, parDeInt>> &arestas, int n){

    UFDS ufds(n);

    int arestasExistentes, v1, v2;
    cin >> arestasExistentes;
    for (int i = 0; i < arestasExistentes; i++){
        cin >> v1 >> v2;
        ufds.unirComponentes(v1, v2);
    }

    sort(arestas.begin(), arestas.end());

    int qtdeArestas = n * (n-1) / 2;
    int custoTotal = 0, nroArestas = 0, u, v;

    pair<int, parDeInt> aux;

    for (int i = 0; i < qtdeArestas; i++){
        aux = arestas[i];
        u = aux.second.first;
        v = aux.second.second;

        if (ufds.mesmoComponente(u, v) == false){
            custoTotal += aux.first;
            nroArestas++;
            if (nroArestas == n - 1){
                break;
            }
            ufds.unirComponentes(u, v);
        }
    }
    return custoTotal;
}

void calcularPesoArestas(vector<pair<int, parDeInt>> &arestas, parDeInt coordenadas[], int n){
    double peso;

    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            peso = sqrt(pow((coordenadas[i].first - coordenadas[j].first), 2) + pow((coordenadas[i].second - coordenadas[j].second), 2));
            peso = round(peso);
            arestas.push_back(make_pair(peso, parDeInt(i, j)));
        }
    }
}

int main(){

    vector<pair<int, parDeInt>> arestas;
    parDeInt *coordenadas;

    int nroVertices, x, y;
    cin >> nroVertices;

    coordenadas = new parDeInt[nroVertices + 1];
    for (int i = 1; i <= nroVertices; i++){
        cin >> x >> y;
        coordenadas[i].first = x;
        coordenadas[i].second = y;
    }

    calcularPesoArestas(arestas, coordenadas, nroVertices);

    cout << kruskall(arestas, nroVertices) << endl;

    return 0;
}