#include<bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    if(c>=65 && c<=90 || c>=97 && c<=122){
        return 1;
    }
    return 0;
}

bool isOperator(char c){
    if(c=='*' || c=='/' || c=='+' || c=='-' || c=='^'){
        return 1;
    }
    return 0;
}

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

void reverse(string &arr){
    for(int i=0;i<arr.length()/2;i++){
        swap(arr[i],arr[arr.length()-i-1]);
    }
    
}

void changebrackets(string &arr, int n){
    for(int i=0;i<n;i++){
        if(arr[i]=='('){
            arr[i]=')';
        }
        else if(arr[i]==')'){
            arr[i]='(';
        }
    }
}

void infixtopostfix(string word){
    stack<char>s;

    for(int i=0;i<word.length();i++){
        //check 1 for operand
        if(isOperand(word[i])){
            cout<<word[i];
        }
        //check 2 for '(' brackets
        else if(word[i]=='('){
            s.push(word[i]);
        }
        //check 3 for ')' brackets
        else if(word[i]==')'){
            while(!s.empty() && s.top()!='('){
                cout<<s.top();
                s.pop();
            }
            if(s.top()=='('){
                s.pop();
            }
        }
        //check 4 for operators
        else if(isOperator(word[i])){
            if(s.empty()){
                s.push(word[i]);
            }
            else{
                if(prec(word[i])>prec(s.top())){
                    s.push(word[i]);
                }
                else if(prec(word[i])==prec(s.top()) && word[i]=='^'){
                    s.push(word[i]);
                }
                else{
                    while(!s.empty() && prec(word[i])<=prec(s.top())){
                        cout<<s.top();
                        s.pop();
                    }
                    s.push(word[i]);
                }
            }
        }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

}

void infixtoprefix(string word){
    reverse(word);
    changebrackets(word,word.length());
    stack<char>s;
    string prefix;

    for(int i=0;i<word.length();i++){
        //check 1 for operand
        if(isOperand(word[i])){
            prefix +=word[i];
        }
        //check 2 for '(' brackets
        else if(word[i]=='('){
            s.push(word[i]);
        }
        //check 3 for ')' brackets
        else if(word[i]==')'){
            while(!s.empty() && s.top()!='('){
                prefix +=s.top();
                s.pop();
            }
            if(s.top()=='('){
                s.pop();
            }
        }
        //check 4 for operators
        else if(isOperator(word[i])){
            if(s.empty()){
                s.push(word[i]);
            }
            else {
                if (prec(word[i]) > prec(s.top())) {
                    s.push(word[i]);
                }
                else if ((prec(word[i]) == prec(s.top())) && (word[i] == '^')) {
                    while ((prec(word[i]) == prec(s.top())) && (word[i] == '^')) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(word[i]);
                }
                else if (prec(word[i]) == prec(s.top())) {
                    s.push(word[i]);
                }
                else {
                    while ((!s.empty()) && (prec(word[i]) < prec(s.top()))) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(word[i]);
                }
            }
        }
    }

    reverse(prefix);

    for(int i=0;i<prefix.length();i++){
        cout<<prefix[i];
    }
}

int main(){
    string word;
    getline(cin,word);
    infixtopostfix(word);
    cout<<endl;
    infixtoprefix(word);


    return 0;
}