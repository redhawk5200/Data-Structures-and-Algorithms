#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int length1=(mid+1)-left;
    int length2=right-mid;

    int leftArr[length1];
    int rightArr[length2];

    for(int i=0;i<length1;i++){
        leftArr[i]=arr[i+left];
    }

    for(int i=0;i<length2;i++){
        rightArr[i]=arr[i+mid+1];
    }

    int l=0, r=0, sort=left;

    while(l<length1 && r<length2){
        if(leftArr[l]<rightArr[r]){
            arr[sort]=leftArr[l];
            l++;
        }
        else{
            arr[sort]=rightArr[r];
            r++;
        }
        sort++;
    }

    while(l<length1){
        arr[sort]=leftArr[l];
        l++;
        sort++;
    }

    while(r<length2){
        arr[sort]=rightArr[r];
        r++;
        sort++;
    }
}

void mergesort(int arr[], int left, int right){
    if(left<right){
        int mid=(left+right)/2;

        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];

    cout<<"Enter your elements to sort: ";
    for(int i=0;i<n;i++){cin>>arr[i];}

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){cout<<*(arr+i)<<" ";}

    return 0;
}