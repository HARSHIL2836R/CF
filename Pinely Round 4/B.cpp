#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)

void solve(){
    in(r);
    loop(r){
        in(n);
        ll b[n-1];
        for (int i=0;i<n-1;i++){
            cin>>b[i];
        }

        ll a[n];
        a[0]=b[0];
        for(int i=1;i<n;i++){
            a[i]=b[i-1]|b[i];
        }
        a[n-1]=b[n-2];

        bool verified = true;

        for(int i=0;i<n-1;i++){
            verified = verified & (b[i] == (a[i] & a[i+1]));
        }

        if (verified){
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}

int main(){
    solve();
}