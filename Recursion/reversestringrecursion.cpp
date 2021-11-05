#include<bits/stdc++.h> 
using namespace std;

void reversestring(string &word, int i){
    int n=word.length();
    if(i==n/2){
        return;
    }
    swap(word[i],word[n-i-1]);
    reversestring(word,i+1);
}

int main(){
    string word="welcome";
    reversestring(word,0);
    cout<<word;
    return 0;
}