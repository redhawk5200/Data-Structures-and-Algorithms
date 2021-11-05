#include<bits/stdc++.h> 
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node(){
        data=0;
        next=NULL;
    }

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class Stack{
    private:
        Node *root;  //this will always have the address of the top element of the stack
    public:
        Stack(){
            root=NULL;
        }

        void push(int data){
            Node *new_node= new Node(data);
            new_node->next=root;
            root=new_node;
        }

        int peek(){
            if(isEmpty()){
                return INT_MIN;
            }
            return root->data;
        }

        int pop(){
            Node *temp=root;
            int x= temp->data;
            root=root->next;
            delete temp;
            return x;
        }

        bool isEmpty(){
            return !root;
        }

        void display(){
            if(isEmpty()){
                cout<<"The list is empty. "<<endl;
                return;
            }
            Node *temp=root;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};

int main(){
	Stack s;
	cout << "Add 10, 20, and 30 to the Stack."<<endl;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	cout<<"Peek: "<<s.peek() << endl;
	cout<< "Pop: "<<s.pop() << endl;
	cout<< "Pop: "<<s.pop() << endl;
	s.display();
	cout<< "Pop: "<<s.pop() << endl;
	cout<< "isEmpty: "<<s.isEmpty() << endl;
	
	return 0;
}