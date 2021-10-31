#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
 
int partition(int *arr, int start, int end){
    int pivot=arr[end];
    int pindex=start;
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            swap(&arr[i],&arr[pindex]);
            pindex++;
        }
    }
    swap(&arr[pindex],&arr[end]);
    return pindex;
}

void quicksort(int *arr, int start, int end){
    if(start<end){
        int p=partition(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int *arr= new int [n];

    cout<<"Enter your elements to sort: ";
    for(int i=0;i<n;i++){cin>>*(arr+i);}

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){cout<<*(arr+i)<<" ";}

    delete [] arr;

    return 0;
}