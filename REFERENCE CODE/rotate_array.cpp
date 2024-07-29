#include <iostream>
using namespace std;

void rotate(int a[], int n, int k)
{//shift elements of initial sub array of length n to right by k steps
    int b[n];//initialise new array b to store rotated array
    if (k>0) {
        for (int i = 0; i < n; i++)
        {
            b[(i+k)%n]=a[i];// i maps to (i+k)%n
        }

        //copy elements to a
        for (int i = 0; i < n; i++)
        {
            a[i]=b[i];
        }
        
        //print array
        for (int i = 0; i < n; i++)
        {
            cout<<a[i]<<',';
        }   
    }
    else if (k<0) rotate(a, n, (k+n*k)%n);
    //otherwise k=0, don't do anything
}