#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)

void solve(){
    in(r);
    loop(r){
        in(n);
        ll A[n];
        ll A_copy[n];
        int B[n];
        for(int i=0; i<n;i++){
            cin>>A[i];
            A_copy[i]=A[i];
            B[i]=i;
        }

        const ll N = sizeof(A_copy) / sizeof(ll);
        for (int x = 0; x < n; x++)
        {
            int maxIndex = distance(A_copy, max_element(A_copy, A_copy + N));

            B[x]=maxIndex;

            A_copy[maxIndex] = -1;

            /* cout<<"BB";
            for(int i=0;i<n;i++){
                cout<<B[i];
            }
            cout<<endl;
            cout<<"AC";
            for(int i=0;i<n;i++){
                cout<<A_copy[i];
            }
            cout<<endl; */
        }

        /* cout<<"B";
        for(int i=0;i<n;i++){
            cout<<B[i];
        }
        cout<<endl; */

        for(int i=0;i<n;i++){
            if (B[i]%2==0 && (n-B[i]-1)%2==0){
                cout<<A[B[i]]<<endl;
                break;
            }
        }
    }
}

int main(){
    solve();
}