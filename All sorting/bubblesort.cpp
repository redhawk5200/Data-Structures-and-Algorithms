#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubblesort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int *arr= new int [n];

    cout<<"Enter your elements to sort: ";
    for(int i=0;i<n;i++){cin>>*(arr+i);}

    bubblesort(arr,n);

    for(int i=0;i<n;i++){cout<<*(arr+i)<<" ";}

    delete [] arr;

    return 0;
}
