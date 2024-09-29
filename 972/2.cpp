#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)
#define print_arr(arr,n) for(int i=0;i<n;i++){cout<<arr[i]<<" ";if(i==n-1){cout<<endl;}}

void compute( int maxn, int maxd, int* counts)
{  memset( counts, 0, maxn *sizeof *counts);
    for( int d=1; d<maxd; ++d)
    {   for( int n=d; n<maxn; n+=d)
        { counts[n] += 1;//counts[n] will hold the number of divisors less than maxd for each n 0,..maxn-1
        }
    }
}

void solve(){
    in(r);
    loop(r){
        
    }
}

int main(){
    solve();
}