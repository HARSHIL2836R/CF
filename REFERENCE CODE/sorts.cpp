#include <iostream>
using namespace std;
//PRINT NON-INCREASING ORDER OF MARKS AND ROLL NUMBER

int argmax(float marks[],int L){//L= length of array marks
    for (int i = 0; i < L; i++)
    {
        cout<<marks[i]<<' ';
    }
    cout<<endl;
    
    int maxIndex=0;//suppose first value is largest
    for(int j=1;j<L;j++){
        //if value at some other index is largest change index with largest number
        if (marks[maxIndex]<marks[j]){maxIndex=j;}
    }
    return maxIndex;
}

void SelectionSort(float marks[],float marks_dir[],int rollNo[],int n){//Non-Increasing, n! number of steps
    for (int x = 0; x < n; x++)
    {
        int maxIndex = x + argmax(marks+x, n-x);

        //swap in rollNo list the indices maxIndex and x
        rollNo[maxIndex]=x;
        rollNo[x]=maxIndex;

        //change the max marks in marks[] to smallest value, say -1
        marks[maxIndex] = -1;

        //Also swap marks along with roll numbers
        float temp = marks[x];
        marks[x]=marks[maxIndex];
        marks[maxIndex]=temp;
        cout<<"Roll number: \tMarks:"<<endl;
        for (int  m = 0; m < n; m++){cout<<rollNo[m]<<'\t'<<'\t'<<marks_dir[rollNo[m]]<<endl;}

    }
    
}

// INSERTION SORT
int insort(){
    int n;cin>>n;int arr[n];
    for (int i=0;i<n;i++){cin>>arr[i];}//initialising array with zeroes
    int sorted[n];
    for (int i=0;i<n;i++){sorted[i]=0;}//initialising array with zeroes
    for (int m=0;m<n;m++){
        for(int i=0;i<n;i++){cout<<sorted[i]<<" ";}
        cout<<'\n';
        int l= arr[m];
        if (l<sorted[0]){
            for (int a=n-2;a>=0;a--){sorted[a+1]=sorted[a];}
            sorted[0]=l;continue;
        }
        for (int j=0;j<n;j++){
            if (sorted[j]==0 && sorted[j+1]==0){sorted[j]=l;break;}
            else if (sorted[j+1]==0){
                if (sorted[j]<l){sorted[j+1]=l;break;}
                else {sorted[j+1]=sorted[j];sorted[j]=l;break;}
            }
            else {
                if (sorted[j]<=l && l<=sorted[j+1]){
                    for (int a=n-2;a>=j;a--){sorted[a+2]=sorted[a+1];}
                    sorted[j+1]=l;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++){cout<<sorted[i]<<" ";}
}

//Double Bubble Sort
bool isgreater(char a[],char b[]){
    int i=0;
    while (true)
    {
        if (a[i]>b[i]) return true;
        if (a[i]<b[i]) return false;
        if (a[i]=='\0' && b[i]=='\0') return false;
        i++;
    }
}
void doubleBubble(char* arr[], int n)
{
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {//iterating from the start, i, till n-i-2
            //replace with > symbol for numbers
            if (isgreater(arr[j+1],arr[j])) swap(arr[j],arr[j+1]);
        }// have the smallest element at the end
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<',';
        }
        cout<<endl;

        for(int j=n-i-2;j>i-1;j--)
        {//iterating from the end (n-i-2) to i
            //replace with > symbol for numbers
            if (isgreater(arr[j+1],arr[j])) swap(arr[j],arr[j+1]);
        }
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<',';
        }
        cout<<endl;
    }
}

//BINARY SORT
//Binary search searches a sorted array
bool BSearch(int x, int A[],int start, int size){
    //x:target value to search
    //range to search: A[start...start+size-1]
    //precondition: size >0 and the array must be sorted
    
    cout<<"Start\t"<<start<<endl<<"Size\t"<<size<<endl;

    if (size==1){return (A[start]==x);}
    int half=size/2;
    if (x<A[start+half]) 
        return BSearch(x,A,start,half);
    else
        return BSearch(x,A,start+half,size-half);
}

//MERGE SORT
void merge(int U[], int uLength, int V[], int vLength, int S[])
{
    for (int uFront = 0, vFront =0, sBack=0; sBack<uLength+vLength; sBack++)
    {//uFront is the cursor in sub-array U and similarly vFront
    //sBack is the cursor in array S where the sorted array is to be stored, incremented after each call
    //terminates after precisly uLength+vLength steps

        if (uFront<uLength && vFront<vLength)
        {//cursors inside both the arrays
            if (U[uFront]<V[vFront])
            {//Add smaller element from U to S and move the cursor ahead in U
                S[sBack]=U[uFront];
                uFront++;
            }
            else {
                S[sBack]=V[vFront];
                vFront++;
            }
        }

        else if(uFront<uLength)//sub-array V parsed completey
        {//add to S from U
            S[sBack] =U[uFront];
            uFront++;
        }
        else
        {//sub-array U parsed completely
        //add to S from V
            S[sBack] =V[vFront];
            vFront++;
        }
    }
    
}

void mergesort(int S[], int n){
    //Array S to be sorted and n=size of S
    if(n>1){
        //Splitting S into two arrays U and V
        int U[n/2], V[n-n/2];
        for (int i = 0; i < n/2; i++){U[i]=S[i];}
        for (int i = n/2; i < n; i++){V[i-n/2]=S[i];}
        
        //Sort the splitted arrays recursively
        mergesort(U,n/2);
        mergesort(V,n-n/2);

        //and finally merge the sorted array typically returning from step where n=2 to n=n/2
        merge(U,n/2,V,n-n/2,S);
    }
}