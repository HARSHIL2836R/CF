#include <iostream>
using namespace std;
void PerfectShuffle(int arr[], int n)
{
    int a1[n/2];
    int a2[n-n/2];

    for (int i = 0; i < n; i++)
    {
        if(i<n/2){
            a1[i]=arr[i];
        }
        else{
            a2[i-n/2]=arr[i];
        }
    }
    for (int j = 0; j < n; j++)
    {
        if(j%2 == 0){
            arr[j]=a2[j/2];
        }
        else{
            arr[j]=a1[(j-1)/2];
        }
    }
    
}
int main(){
    int arr[5]={1,2,3,4,5};
    PerfectShuffle(arr,5);
    for (int i = 0; i < 5; i++)
        {
            cout<<arr[i]<<',';
        }
        cout<<endl;
}