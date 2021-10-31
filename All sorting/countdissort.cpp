#include<iostream>
using namespace std;

void countdistributionsort(int *arr, int n){
    //finding the maximum value in the array
    int maxVal=arr[0];
    for(int i=0;i<n;i++){
        maxVal=max(maxVal,arr[0]);
    }

    //creating an array to keep count of all the values in the original array
    int *countarr= new int[maxVal+1];
    
    //initializing it with zeros
    for(int i=0;i<maxVal+1;i++){
        countarr[i]=0;
    }

    //increasing the count in the count array of the numbers in the original array  
    for(int i=0;i<n;i++){
        countarr[arr[i]]++;
    }

    //adding the previous element to the next element in the count array
    for(int i=1;i<=maxVal+1;i++){
        countarr[i]+=countarr[i-1];
    }

    //creating an array to put in the sorted values
    int *output= new int[n];

    //filling it in with the proper sorted values
    for(int i=n-1;i>=0;i--){
        output[--countarr[arr[i]]]=arr[i];
    }

    //copying the sorted array (output array) to the original array
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }

    //deleting the dynamically allocated arrays
    delete [] countarr;
    delete [] output;
}

int main(){
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int *arr= new int [n];

    cout<<"Enter your elements to sort: ";
    for(int i=0;i<n;i++){cin>>*(arr+i);}

    countdistributionsort(arr,n);

    for(int i=0;i<n;i++){cout<<*(arr+i)<<" ";}

    delete [] arr;

    return 0;
}