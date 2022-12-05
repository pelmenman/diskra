#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> enemies;
vector<bool> visited;
vector<int> mark;
int numPeople;
bool can = true;


void dfs(int node){
    visited[node] = true;

    for (int i : enemies[node]) {
        if (mark[node] == mark[i]) {
            can = false;
        } else {
            if ()
        }
    }
}

int main() {
    int numEnemies;
    cin >> numPeople >> numEnemies;
    enemies.resize(numPeople);
    visited.resize(numPeople, false);
    mark.resize(numPeople);

    for (int i = 0; i < numEnemies; i++) {
        int a, b; cin >> a >> b; a--; b--;
        enemies[a].push_back(b);
        enemies[b].push_back(a);
    }

    dfs(0);

    return 0;
}
