#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)
#define print_arr(arr,n) for(int i=0;i<n;i++){cout<<arr[i]<<" ";if(i==n-1){cout<<endl;}}

void solve(){
    in(r);
    loop(r){
        in(n);in(k);
        int max_pow = floor(log(n)/log(k));
        int ops = 0;
        while(n>0){
            if (pow(k,max_pow)>n){
                max_pow--;
                continue;
            }
            int num = pow(k,max_pow);
            ops += n/num;
            n = n % num;
        }
        cout<<ops<<endl;
    }
}

int main(){
    solve();
}