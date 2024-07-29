#include <iostream>
using namespace std;

bool removeFirst(float a[], int &n, float x)
{//returns true if first occurence of x in a of size n is successfully removed
    for (int i = 0; i < n; i++)
    {
        if(a[i]==x){//first occurence found
            for (int j = i; j < n; j++)
            {
                a[j]=a[j+1];//move all elements down the index by 1
            }
            n--;//reduce n by 1
            
            //print array
            for (int i = 0; i < n; i++)
            {
                cout<<a[i]<<',';
            }
            return true;
        }
    }
    //if statement not entered => x not found in a
    return false;
    
}