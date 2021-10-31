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

void selectionsort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(min!=i){
            swap(&arr[min],&arr[i]);
        }
    }
}

void shellsort(int *arr, int n){
    for(int gap=n/2;gap>=1;gap/=2){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i-=gap){
                if(arr[i]<arr[i+gap]){
                    break;
                }
                else{
                    swap(&arr[i],&arr[i+gap]);
                }
            }
        }
    }
}

int partition (int *arr, int start, int end){
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

void merge(int *arr, int left, int mid, int right){
    int leftarrLength= (mid+1)-left;
    int rightarrLength= right-mid;

    int *leftarr= new int[leftarrLength];
    int *rightarr= new int[rightarrLength];

    for(int i=0;i<leftarrLength;i++){
        leftarr[i]=arr[i+left];
    }

    for(int i=0;i<rightarrLength;i++){
        rightarr[i]=arr[i+mid+1];
    }

    int l=0; int r=0; int sortposition=left;

    while(l<leftarrLength and r<rightarrLength){
        if(leftarr[l]<rightarr[r]){
            arr[sortposition]=leftarr[l];
            l++;
        }
        else{
            arr[sortposition]=rightarr[r];
            r++;
        }
        sortposition++;
    }

    while(l<leftarrLength){
        arr[sortposition]=leftarr[l];
        l++; sortposition++;
    }

    while(r<rightarrLength){
        arr[sortposition]=rightarr[r];
        r++; sortposition++;
    }
}

void mergesort(int *arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;

        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

int main(){
    int n, option;
    cout<<"Enter the numbers of elements to sort: ";
    cin>>n;

    int *arr=new int[n];

    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter 1 to use bubble sort to sort your unsorted array\n";
    cout<<"Enter 2 to use selection sort to sort your unsorted array\n";
    cout<<"Enter 3 to use insertion sort to sort your unsorted array\n";
    cout<<"Enter 4 to use shell sort to sort your unsorted array\n";
    cout<<"Enter 5 to use quick sort to sort your unsorted array\n";
    cout<<"Enter 6 to use merge sort to sort your unsorted array\n";
    cout<<"Enter 7 to use count distribution sort to sort your unsorted array\n";
    cout<<"Enter 8 to use radix sort to sort your unsorted array\n";
    cin>>option;

    switch (option)
    {
    case 1:
        bubblesort(arr,n);
        break;

    case 2:
        selectionsort(arr,n);
        break;

    case 3:
        insertionsort(arr,n);
        break;

    case 4:
        shellsort(arr,n);
        break;

    case 5:
        quicksort(arr,0,n-1);
        break;

    case 6:
        mergesort(arr,0,n-1);
        break;
        
    }
    

    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    delete [] arr;

    return 0;
}