#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> matrix;
int n = 0;


int BFS(int start, int end) {
    vector<int> visited(n, -1);
    queue<int> orderToVisit;

    orderToVisit.push(start);
    visited[start] = 0;

    while (!orderToVisit.empty()) {
        int currentNode = orderToVisit.front();
        orderToVisit.pop();
        for (int i : matrix[currentNode]) {
            if (visited[i] == -1) {
                visited[i] = visited[currentNode] + 1;
                orderToVisit.push(i);
            }
        }
    }

    return visited[end];
}


int main() {
    cin >> n;
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;

            if (a == 1) matrix[i].push_back(j);
        }
    }

    int start; cin >> start;
    int end; cin >> end;

    cout << BFS(start - 1 , end - 1) << endl;

    return 0;
}
