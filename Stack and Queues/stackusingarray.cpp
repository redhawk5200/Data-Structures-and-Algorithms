#include<iostream>
using namespace std;

#define max 10

class Stack{
    private:
        int top;
    public:
        int a[max];

    Stack(){
        top=-1;
    }

    bool push(int data){
        if(top>=max-1){
            cout<<"Stack Overflow "<<endl;
            return false;
        }
        else{
            a[++top]=data;
            cout<<data<<" has been pushed into the stack."<<endl;
            return true;
        }
    }

    int pop(){
        if(top<0){
            cout<<"List is empty. "<<endl;
            return 0;
        }
        else{
            int x=a[top];
            top--;
            return x;
        }
    }

    int peek(){
        if(top<0){
            cout<<"List is empty. "<<endl;
            return 0;
        }
        else{
            int x=a[top];
            return x;
        }
    }

    bool isEmpty(){
        if(top<0){
            return true;
        }
    }

    void printstack(){
        if(top<0){
            cout<<"List is empty. "<<endl;
            return;
        }
        int temp=0;
        while(temp<=top){
            cout<<a[temp]<<" ";
            temp++;
        }
        cout<<endl;
    }

};

int main(){
    int element;
    Stack stack1;

    //Task 1(1.)
    cout<<"Enter your 10 elements: ";
    for(int i=0;i<max;i++){
        cin>>element;
        stack1.push(element);
    }

    stack1.printstack();

    //Task 1(2.)
    cout<<"Trying to insert 11th element, with the data 11: ";
    stack1.push(11);

    stack1.printstack();

    //Task 1(3.)
    for(int i=0;i<max;i++){
        stack1.pop();
    }

    stack1.printstack();

    return 0;
}
