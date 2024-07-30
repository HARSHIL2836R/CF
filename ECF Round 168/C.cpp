#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define in(n) ll n;cin>>n
#define loop(r) for(int i=0;i<r;i++)
#define print_arr(arr,n) for(int i=0;i<n;i++){cout<<arr[i]<<" ";if(i==n-1){cout<<endl;}}

void solve(){
    in(r);
    loop(r){
        in(n);
        char a[n];
        ll open=0, close=0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if (a[i]=='('){open++;}
            else if (a[i]==')'){close++;}
        }
        ll left = open - close;
        a[0]='(';
        left++;
        for (int i = 2; i < n; i+=2)
        {
            if (left>0){
                if (a[i-1]==')'){a[i]='(';}
                else{a[i]=')';}
            }
            if (left<=0){
                if (a[i-1]=='('){a[i]=')';}
                else{a[i]='(';}
            }
        }
        //print_arr(a,n);
        ll score=0;
        for (int i = 0; i < n; i++)
        {
            if (a[i]=='('){
                for (int j = i+1; j < n; j++)
                {
                    if (a[j]==')'){
                        score+=j-i;
                        a[i]=0;
                        a[j]=0;
                        break;
                    }
                }
            }
        }
        cout<<score<<endl;
    }
}

int main(){
    solve();
}