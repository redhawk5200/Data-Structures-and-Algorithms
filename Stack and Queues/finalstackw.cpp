#include<bits/stdc++.h>

using namespace std;

#define MAX 50

class Stack{
    public:
        int top;
        int arr[MAX];

    Stack(){
        top=-1;
    }
    
    void push(int x){
        if(top>=MAX-1){
            cout<<"Overflow"<<endl;
            return;
        }
        else{
            arr[++top]=x;
        }
    }

    int pop(){
        if(top<0){
            cout<<"Stack is empty."<<endl;
            return 0;
        }
        else{
            int x=arr[top--];
            return x;
        }
    }

    int peek(){
        if(top<0){
            cout<<"Stack is empty."<<endl;
            return 0;
        }
        else{
            return arr[top];
        }
    }

    bool isempty(){
        if(top<0){
            return true;
        }
        return false;
    }

    bool isfull(){
        if(top>MAX-1){
            return true;
        }
        return false;
    }

    void print(){
        if(!isempty()){
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
};

int compare(int x, int y){
    if(x>y){
        return -1;
    }
    else if(x<y){
        return 1;
    }
    return 0;
}

void Merge(Stack s1, Stack s2, Stack f, Stack c){
    while(!s1.isempty() && !s2.isempty()){
        if(compare(s1.peek(),s2.peek())==1){
            f.push(s1.pop());
        }
        else if(compare(s1.peek(),s2.peek())==-1){
            f.push(s2.pop());
        }
    }

    if(s1.isempty()){
        while(!s2.isempty()){
            f.push(s2.pop());
        }
    }

    if(s2.isempty()){
        while(!s1.isempty()){
            f.push(s1.pop());
        }
    }

    while(!f.isempty()){
        c.push(f.pop());
    }

    c.print();
}

int main(){
    Stack s1,s2;
	
	s1.push(8);  //stack: 2,4,6,8
	s1.push(6);
	s1.push(4);
	s1.push(2);	
	
	s2.push(9); //stack: 3,5,7,9
	s2.push(7);
	s2.push(5);
	s2.push(3);
    
    Stack f;
    Stack c;

    Merge(s1,s2,f,c);
    
    return 0;
}