#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix;
vector<bool> used (false);
bool cycle = false;

void dfs(int node, int parent) {
    used[node] = true;

    for (int otherNode : matrix[node]) {
        if (used[otherNode] == false) {
            dfs(otherNode, node);
        } else {
            if (otherNode != parent) cycle = true;
        }

    }
}

`
int main() {
    int size = 0;
    cin >> size;

    matrix.resize(size);
    used.resize(size, false);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int a; cin >> a;
            if (a == 1) {
                matrix[i].push_back(j);
            }
        }
    }

    dfs(0, 0);

    for (bool res : used) {
        if (!res) {
            cout << "NO\n";
            return 0;
        }
    }

    if (cycle == false) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
