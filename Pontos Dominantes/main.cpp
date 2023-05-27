#include <iostream>
#include <list>
using namespace std;

const int origem = 0;

void DFS(int raiz, int valorApagado, int **MA, int n, bool visitado[]){
    
    visitado[raiz] = true;

    for (int i = 0; i < n; i++){
        if (MA[raiz][i] == true){
            if ((visitado[i] == false) and (i != valorApagado)){
                DFS (i, valorApagado, MA, n, visitado);
            }
        }
    }
}

void pontoDominante(int valorApagado, int n, int **W, int **MA, list<int> *dominancia){
    
    bool visitado[n];
    for (int i = 0; i < n; i++)
        visitado[i] = false;

    DFS(origem, valorApagado, MA, n, visitado);

    for (int i = 0; i < n; i++){
        if (W[valorApagado][i] == true){
            if (visitado[i] == false){
                dominancia[valorApagado].push_back(i);
            }
        }
    }
}

int main(){

    int n;
    cin >> n;

    // Alocando matrizes de adjacência
    int **MA = new int*[n];
    int **W = new int*[n];

    for (int i = 0; i < n; i++)
    {
        MA[i] = new int[n];
        W[i] = new int[n];
    }

    for (int u = 0; u < n; u++){
        for (int v = 0; v < n; v++){
            cin >> MA[u][v];
            W[u][v] = MA[u][v];
        }
    }

    // Algoritmo de Warshall
    for (int k = 0; k < n; k++){
        for (int u = 0; u < n; u++){
            for (int v = 0; v < n; v++){
                W[u][v] = W[u][v] or (W[u][k] and W[k][v]);
            }
        }
    }

    // Lista das linhas com seus pontos de dominio
    list<int> *dominancia = new list<int>[n];

    // Zero (origem) sempre dominará vertices que ele conseguir alcançar
    for (int i = 0; i < n; i++){
        if (W[origem][i] == true){
            dominancia[origem].push_back(i);
        }
    }

    for (int i = 1; i < n; i++){
        if (W[origem][i] == true){
            pontoDominante(i, n, W, MA, dominancia);
        }
    }

    // Cada elemento domina ele mesmo
    bool encontrado = false;
    for (int i = 0; i < n; i++){
        if ((W[origem][i] == true) or (i == 0)){
            for (auto it = dominancia[i].begin(); it != dominancia[i].end(); it++){
                if (*it == i){
                    encontrado = true;
                }
            }
            if (encontrado == false){
                dominancia[i].push_front(i);
            }
        }
    }

    // Imprimindo
    for (int i = 0; i < n; i++){
        if (dominancia[i].empty() == true)
            cout << "-" << endl;
        else {
            for (auto it = dominancia[i].begin(); it != dominancia[i].end(); it++){
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < n; i++){
        delete[] MA[i];
        delete[] W[i];
    }
    delete[] MA;
    delete[] W;
    
    return 0;
}