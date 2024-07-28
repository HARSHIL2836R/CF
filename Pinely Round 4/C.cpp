#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)

ll mean(ll a[], ll n){
    ll s = accumulate(a, a+n, 0);
    s = (s+n-1)/n;
    return s;
}

void solve(){
    in(r);
    loop(r){
        in(n);
        ll a[n];
        bool all_zero = true;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            all_zero = all_zero && (not a[i]);
        }

        if (all_zero){
            cout<<0<<endl<<endl;
            continue;
        }

        int count = 0;
        bool verify = true;
        ll m[40];
        do{

            /* cout<<"A";
            for(int i =0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl; */

            m[count] = mean(a,n);
            verify = true;
            for (int i = 0; i < n; i++)
            {
                a[i] = llabs(a[i]-m[count]);
                verify = verify && (a[i] == 0);
            }
            count++;
        }
        while ((verify == false) && (count <= 40));

        if (verify){
            cout<<count<<endl;
            for (int i=0;i<count;i++){
                cout<<m[i]<<" ";
            }
            cout<<endl;
        }
        else{cout<<-1<<endl;}

    }
}

int main(){
    solve();
}