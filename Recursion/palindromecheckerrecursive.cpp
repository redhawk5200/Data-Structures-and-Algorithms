#include<bits/stdc++.h>
using namespace std;

int palindromechecker(string word, int start, int end){
    if(end-start==1 || end==start){
        if(word[start]==word[end]){
            return 1;
        }
    }
    else if(word[start]==word[end]){
        return palindromechecker(word,start+1,end-1);
    }
    else{
        return 0;
    }
}

int main(){
    string s;
    cin>>s;
    int n=s.length();
    if(palindromechecker(s,0,n-1)){
        cout<<"The string entered is a palindrome. ";
    }
    else{
        cout<<"The string entered is not a palindrome. ";
    }

    return 0;
}
