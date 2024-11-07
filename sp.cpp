#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)
#define print_arr(arr,n) for(int i=0;i<n;i++){cout<<arr[i]<<" ";if(i==n-1){cout<<endl;}}

#define NMAX 100001

vector<vector<int>> M{vector<int>{-1,NMAX}};
bool visited[NMAX];

struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
};

void Dijkstra(int n){
    vector<int> SP(n,INT_MAX);

    using PII = pair<int,int>;
    priority_queue<PII,vector<PII>,compare> pq;
    SP[0] = 0;

    memset(visited,0,sizeof(visited));
    for (int i = 0; i<NMAX; i++){
        pq.push({i, INT_MAX});
    }
    
}

void solve(){
    in(n);in(m);
    memset(&M,-1,sizeof(M));
    loop(m){
        in(a);in(b);in(w);
        M[a][b] = w;
        M[b][a] = w;
    }
    Dijkstra(n);
}

int main(){
    solve();
}