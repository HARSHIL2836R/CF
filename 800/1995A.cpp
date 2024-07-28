#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)

void solve(){
    in(r);
    loop(r){
        in(n);in(k);
        int count = 0;
        if(k>0){count++;k-=n;}
        for(ll i=1;k>0;i+=1){
            if(k>0){count++;k-=n-i;}
            if(k>0){count++;k-=n-i;}
        }
        cout<<count<<endl;
    }

}
int main(){
    solve();
}