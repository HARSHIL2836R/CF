#include <iostream>
using namespace std;

//RECURSION
int max_num(int array[], int N){//N = length of array
    /*
    We're traversing the array from the end
    first we check max of N-1 nums and N but for that we need to iterate again and check
    max of N-2 nums and N-1 and so on until we check frist 2 nums and 2nd num
    If first is bigger it is returned to previus function call (stacked until now) and compare 
    1 and 3 and so on
    */
    if (N==1) {return array[N];}
    else {return (max_num(array, N-1)>array[N])? max_num(array, N-1):array[N];}
}