#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)

bool isPrime(ll n){
    if (n <= 1){
        return false;
    }

    for (ll i = 2; i <= n / 2; i++){
        if (n % i == 0){
            return false;
            }
        }

    return true;
}

void solve(){
    in(r);
    loop(r){
        in(n);
        map<ll, vector< ll > > edges;
        for (ll i=1; i<n+1;i++){
            for(ll j = i+1;j<n+1;j++){
                ll c = i ^ j;
                if (isPrime(c)){
                    edges[i].push_back(j);
                }
            }
        }
        map<ll, ll > color;
        
        do{
            
        }
    }
}

int main(){
    solve();
}