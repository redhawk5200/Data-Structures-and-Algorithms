#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void shellsort(int *arr, int n){
    //creating a loop for the gap between the two elements that will be compared
    for(int gap=n/2;gap>=1;gap/=2){
        //creating a loop for the element to be compared at the end of the gap
        for(int j=gap;j<n;j++){
            //creating a loop for the element to be compared at the start of the gap
            for(int i=j-gap;i>=0;i-=gap){
                if(arr[i+gap]>arr[i]){
                    break;
                }
                else{
                    swap(&arr[i],&arr[i+gap]);
                }
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

    shellsort(arr,n);

    for(int i=0;i<n;i++){cout<<*(arr+i)<<" ";}

    delete [] arr;

    return 0;
}