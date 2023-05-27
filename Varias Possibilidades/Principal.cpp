#include <iostream>
#include <vector>
using namespace std;

void DFS(int u, int &cont, vector<int> *listaAdj){

    if (listaAdj[u].empty() == false){
        for (auto it = listaAdj[u].begin(); it != listaAdj[u].end(); it++){
            int v = *it;

            DFS(v, cont, listaAdj);
        }
    }
    else {
        cont++;
    }
}
 
int main(){

    int n;
    cin >> n;

    vector<int> *listaAdj = new vector<int>[n + 1];

    int i, j;
    cin >> i >> j;
    while ((i != -1) and (j != -1)){
        listaAdj[i].push_back(j);
        cin >> i >> j;
    }

    int cont = 0;
    DFS(1, cont, listaAdj);

    cout << cont << endl;

    return 0;
}