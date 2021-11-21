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

bool simplesearch(int *arr, int n){
    for(int i=0;i<10;i++){
        if(arr[i]==n){
            return true;
        }
    }
    return false;
}

bool binarysearch(int *arr, int n){
    int start=0;
    int end=10-1;

    while(start<=end){
        int mid=(start+end)/2;

        if(arr[mid]==n){
            return true;
        }
        else if(n>arr[mid]){
            start=mid+1;
        }
        else if(n<arr[mid]){
            end=mid-1;
        }
    }

    return false;
}

bool jumpsearch(int *arr, int n){
    int m=sqrt(10);
    int low;
    for(int i=0;i<10;i+=m){
        if(arr[i]==n){
            return true;
        }
        if(arr[i]<n){
            low=i;
        }
        if(arr[i]>n){
            break;
        }
    }

    for(int i=low;i<10;i++){
        if(arr[i]==n){
            return true;
        }
    }

    return false;
}

int binaryrecursive(int *arr, int low, int high, int n){
    int mid=low+(high-low)/2;

    if(low>high){
        return -1;
    }

    if(arr[mid]==n){
        return n;
    }
    else if(n<arr[mid]){
        return binaryrecursive(arr,low,mid-1,n);
    }
    else{
        return binaryrecursive(arr,mid+1,high,n);
    }

}

bool exponentialsearch(int *arr, int n){
    if(arr[0]==n){
        return true;
    }

    int i=1;
    while(i<n && arr[i]<=n){
        i*=2;
    }

    int m=binaryrecursive(arr,i/2,min(i,n-1),n);
    if(m==n){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int *arr= new int [10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }

    bubblesort(arr,10);

    int n;
    cout<<"Enter a value to search for: ";
    cin>>n;

    if(exponentialsearch(arr,n)){
        cout<<"Value has been found. ";
    }

    return 0;
}
