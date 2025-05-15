#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N = 5, M = 7;
vector<vector<string>> soluciones;

void dfs(int x, int y, string path) {
    if (x == N - 1 && y == M - 1) {
        soluciones.push_back({path});
        return;
    }
    if (y + 3 < M)
        dfs(x, y + 3, path + "→→→ ");
    if (x + 2 < N)
        dfs(x + 2, y, path + "↓↓ ");
}

int main() {
    cout << "Ingresa valor para N" << endl;
    cin >> N;
    cout << "Ingresa valor para N" << endl;
    cin  >> M;

    if ((N - 1) % 2 == 0 && (M - 1) % 3 == 0) {
        cout << "Hay al menos un camino.\n";
    } else {
        cout << "No hay camino posible.\n";
        return 0;
    }

    dfs(0, 0, "");
    cout << "Total caminos encontrados: " << soluciones.size() << endl;
    int contador = 1;
    for (auto& s : soluciones) {
        cout  << contador++ << ") \t" << s[0] << endl;
    }

    return 0;
}
