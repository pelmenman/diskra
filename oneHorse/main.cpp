#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<pair<int, int>, int> path;
vector<pair<int, int>> movements = { {1,2}, {2, 1}, {-1, 2}, {-2, 1},{-1, -2}, {-2, -1}, {1, -2}, {2, -1}};

int bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> toVisit;
    path[start] = 0;
    toVisit.push(start);

    while(path[end] == 0) {
        pair<int, int> temp = toVisit.front();
        toVisit.pop();

        for (pair<int, int> mv : movements) {
            pair<int, int> nextStep(temp.first + mv.first, temp.second + mv.second);

            if(path[nextStep] == 0) {
                path[nextStep]  = path[temp] + 1;
                toVisit.push(nextStep);
            }
        }
    }

    return path[end];
}


int main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;

    cout << bfs( make_pair(x1, y1), make_pair(x2, y2));
    return 0;
}
