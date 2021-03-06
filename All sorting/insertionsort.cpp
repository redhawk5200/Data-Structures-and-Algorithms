#include<iostream>
using namespace std;

void insertionsort(int *arr, int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}

int main(){
    int n; 
    cin>>n;
    int *arr= new int [n];

    cout<<"Enter your elements to sort: ";
    for(int i=0;i<n;i++){cin>>*(arr+i);}

    insertionsort(arr,n);

    for(int i=0;i<n;i++){cout<<*(arr+i)<<" ";}

    delete [] arr;

    return 0;
}