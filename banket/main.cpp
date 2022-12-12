#include <iostream>
#include <vector>
using namespace std;

void dfs(int g,bool &flag,vector <int> &color,vector <bool> &upd,vector <vector <int> > &spis){
    upd[g]=false;
    int clr =(color[g]-3)*(-1);
    for(int i = 0;i<spis[g].size();i++){
        if(color[spis[g][i]] == color[g]){
            flag = false;
        }
        else color[spis[g][i]] = clr;
    }
    for(int i = 0;i<spis[g].size();i++){
        if(upd[spis[g][i]]) dfs(spis[g][i],flag,color,upd,spis);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector <vector <int> > a(n);
    vector <bool> upd(n,true);
    for (int i = 0;i < m;i++){
        int p,q;
        cin >> p >> q;
        a[p-1].push_back(q-1);
        a[q-1].push_back(p-1);
    }
    bool flag = true;
    vector <int> color(n);
    for(int i = 0;i<n;i++){
        if(upd[i]){
            color[i] = 1;
            dfs(i,flag,color,upd,a);
        }
    }
    if (flag) cout << "YES";
    else cout << "NO";
}