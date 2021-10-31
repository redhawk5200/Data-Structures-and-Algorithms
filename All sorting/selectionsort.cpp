#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionsort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(&arr[i],&arr[min]);
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

    selectionsort(arr,n);

    for(int i=0;i<n;i++){cout<<*(arr+i)<<" ";}

    delete [] arr;

    return 0;
}