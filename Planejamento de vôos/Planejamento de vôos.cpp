#include <iostream>
#include <vector>
#include <map>
using namespace std;

void DFS(int u, map<int, vector<int>> listaAdj, bool explorado[], vector<int> &verticesFinais){

    explorado[u] = true;

    for (auto it = listaAdj[u].begin(); it < listaAdj[u].end(); it++){
        int v = *it;

        if (explorado[v] == false){
            verticesFinais.push_back(v);
            DFS(v, listaAdj, explorado, verticesFinais);
        }
    }
}

int compararGrafos(map<int, vector<int>> listaAdj_1, map<int, vector<int>> listaAdj_2, int nroDeVoos_1, int nroDeVoos_2){
    bool explorado_1[nroDeVoos_1];
    bool explorado_2[nroDeVoos_2];
    vector<int> verticesFinais_1;
    vector<int> verticesFinais_2;

    for (int i = 0; i < nroDeVoos_1; i++){
        explorado_1[i] = false;
    }
    for (int i = 0; i < nroDeVoos_1; i++){
        if (explorado_1[i] == false){
            DFS(i, listaAdj_1, explorado_1, verticesFinais_1);
        }
    }

    for (int i = 0; i < nroDeVoos_2; i++){
        explorado_2[i] = false;
    }
    for (int i = 0; i < nroDeVoos_2; i++){
        if (explorado_2[i] == false){
            DFS(0, listaAdj_2, explorado_2, verticesFinais_2);
        }
    }

    int cont = 0;
    for (auto i = verticesFinais_1.begin(); i < verticesFinais_1.end(); i++){
        for (auto j = verticesFinais_2.begin(); j < verticesFinais_2.end(); j++){
            if (*i == *j){
                cont++;
                break;
            }
        }
    }
    if ((cont == (int)verticesFinais_1.size()) and (cont == (int)verticesFinais_2.size())){
        return 1;
    }
    return 0;
}

int main(){

    int qtdeDeTestes;
    cin >> qtdeDeTestes;

    map<int, vector<int>> listaAdj_1, listaAdj_2;

    int nroDeVoos_1, nroDeVoos_2, u, v;
    for (int i = 0; i < qtdeDeTestes; i++){
        cin >> nroDeVoos_1;
        for (int j = 0; j < nroDeVoos_1; j++){
            cin >> u >> v;
            listaAdj_1[u].push_back(v);
        }
        cin >> nroDeVoos_2;
        for (int j = 0; j < nroDeVoos_2; j++){
            cin >> u >> v;
            listaAdj_2[u].push_back(v);
        }
        cout << compararGrafos(listaAdj_1, listaAdj_2, nroDeVoos_1, nroDeVoos_2) << endl;
        listaAdj_1.clear();
        listaAdj_2.clear();
    }
    return 0;
}