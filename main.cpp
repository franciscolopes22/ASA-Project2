#include <iostream>
#include <vector>
#include <queue>
#include <map>

#include <unordered_map>

using namespace std;

void solve(int v1, int v2, int n, map<int, vector<int> >& parents){
    vector <int> vector1(n+1,0);
    vector <int> vector2(n+1,0);
    unordered_map<int,int> possible;
    unordered_map<int,int> res;
    queue<tuple<int,int> > q;
    q.push({v1,1});
    q.push({v2,2});
    tuple<int,int> temp;
    int parent,origin;
    while (!q.empty()) {
        temp = q.front();
        tie( parent,  origin) = temp;
        q.pop();
        if (origin==1 && vector2[parent]==1) {
            possible[parent];
            res[parent];
            continue;
        }
        if (origin==2 && vector1[parent]==1) {
            possible[parent];
            res[parent];
            continue;
        }
        if (origin==1){
            vector1[parent]=1;
        }
        if (origin==2){
            vector2[parent]=1;
        }
        for (int el: parents[parent]) {
            if (origin==1 && vector1[el]==0){
                q.push({el,origin});
            }
            if (origin==2 && vector2[el]==0) {
                q.push({el,origin});
            }
        }
    }

    for (auto& el: possible) {
        for (auto& p: parents[el.first]){
            if (possible.find(p) != possible.end()) {
                res.erase(p);
            }
        }
    }
    vector<int> final;
    for (int i=1; i<n+1; i++) {
        if (res.find(i)!=res.end()){
            final.push_back(i);
        }
    }
    if (res.empty()){
        cout << "-";
    } else {
        for (int el: final){
            cout << el << " ";
        }
    }
    cout << '\n';

}

int main(){
    std::ios::sync_with_stdio(false);
    int v1,v2,n,m,x,y;
    cin >> v1 >> v2;
    cin >> n >> m;

    unordered_map<string,int> seen;
    map<int, vector<int> > parents;

    while (m>0) {
        cin >> x >> y;
        string a = to_string(y)+','+to_string(x);
        string b = to_string(x)+','+to_string(y);
        if (x == y || seen.find(a) != seen.end() || seen.find(b) != seen.end()) {
            cout << "0" << '\n';
            return 0;
        }
        seen[a];
        seen[b];
        parents[y].push_back(x);
        if (parents[y].size()>2) {
            cout << "0" << '\n';
            return 0;
        }
        m -= 1;
    }

    solve(v1,v2,n,parents);

    return 0;
}
