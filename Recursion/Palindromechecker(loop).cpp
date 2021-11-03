#include<bits/stdc++.h> 
using namespace std;

bool checkforPalindrome(int word[], int n){
    for(int i=0;i<n;i++){
        if(word[i]!=word[n-i-1]){
            return false;
        }
    }
}

int main(){
    int word1[]={1,2,1};
    int word2[]={1,4,4};

    int length1= 3;
    int length2= 3;

    if(checkforPalindrome(word1,length1)){
        cout<<"word1 is a palindrome."<<endl;
    }
    else{
        cout<<"word1 is not a palindrome."<<endl;
    }

    if(checkforPalindrome(word2,length2)){
        cout<<"word2 is a palindrome."<<endl;
    }
    else{
        cout<<"word2 is not a palindrome."<<endl;
    }

    return 0;
}