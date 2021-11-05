#include<bits/stdc++.h>
using namespace std;

void bubblesort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int removingduplicates(int *arr, int n){
    
    if(n==0 || n==1){
        return arr[n];
    }

    bubblesort(arr,n);
    int temp[n];
    int j=0;

    for(int i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1]){
            temp[j++]=arr[i];
        }
    }

    temp[j++]=arr[n-1];

    for(int i=0;i<j;i++){
        arr[i]=temp[i];
    }

    return j;

}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int *arr= new int[n];

    cout<<"Enter your elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int p=removingduplicates(arr,n);
    for(int i=0;i<p;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}