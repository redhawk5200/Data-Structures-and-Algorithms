#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    float sum=0.00, studentgpa=0.00;
    cout<<"Enter the number of students in the class: ";
    cin>>n;

    float **arr= new float*[n];
    int size[n];
    
    for(int i=0;i<n;i++){
        cout<<"How many subjects did student "<<i+1<<" appear in: ";
        cin>>size[i];
    }

    for(int i=0;i<n;i++){
        arr[i]= new float[size[i]];
    }

    for(int i=0;i<n;i++){
        cout<<"Enter the marks of student "<<i+1<<" who appeared in "<<size[i]<<" subjects: ";
        for(int j=0;j<size[i];j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<size[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //calculating the gpa of each student
    for(int i=0;i<n;i++){
        for(int j=0;j<size[i];j++){
            sum+=arr[i][j];
        }
        studentgpa=((sum*3)/(size[i]*3));
        cout<<"GPA of student "<<i+1<<" is: "<<studentgpa<<endl;
        sum=0; studentgpa=0;
    }

    return 0;
}
