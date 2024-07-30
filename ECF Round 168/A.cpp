#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)
#define print_arr(arr,n) for(int i=0;i<n;i++){cout<<arr[i]<<" ";if(i==n-1){cout<<endl;}}

void solve(){
    in(r);
    loop(r){
        string a;
        bool verify = false;
        getline(cin, a);
        int n = a.length();
        for (int i = 0; i < n; i++)
        {
            if (a[i]==a[i+1] && !verify){
                if (a[i]=='a'){
                    a.append(1,a[n-1]);
                    for (int j = n-1;j>i;j--){
                        a[j]=a[j-1];
                    }
                    a[i+1]='b';
                }
                else{
                    a.append(1,a[n-1]);
                    for (int j = n-1;j>i;j--){
                        a[j]=a[j-1];
                    }
                    a[i+1]='a';
                }
                verify = true;
            }
            if (i==n-1 && !verify){
                a.append(1,a[i]+1);
                verify = true;
            }
        }
        cout<<a<<endl;
    }
}

int main(){
    solve();
}