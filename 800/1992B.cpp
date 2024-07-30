//TIMELIMIT EXCEEDED
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int h=0;h<r;h++)
#define print_arr(arr,n) for(int i=0;i<n;i++){cout<<arr[i]<<" ";if(i==n-1){cout<<endl;}}

void solve(){
    in(r);
    loop(r){
        in(n);in(k);
        ll arr[k];
        for (int i=0;i<k;i++){
            cin>>arr[i];
        }
        sort(arr,arr+k);
        //cout<<"SORTED";
        //print_arr(arr,k);

        ll step = 2*(n-arr[k-1])-k+1;
        cout<<step<<endl;
    }
}

int main(){
    solve();
}