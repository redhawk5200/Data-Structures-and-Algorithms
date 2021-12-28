#include<bits/stdc++.h> 
using namespace std;

class Node{
	public:
	char data;
	Node* next;
	
	Node(){
		data='0';
		next = NULL;
	}
	Node(char d){
		data = d;
		next = NULL;
	}
};

class Stack{
	Node* root;
	
	public:
		Stack(){
			root = NULL;
		}
		
		void push(char d){
			Node* n = new Node(d);
			n->next = root;
			root = n;
		}
		
		bool isEmpty(){
			return !root;
		}
		
		char peek(){
			if(isEmpty())
				return numeric_limits<char>::min();
				
			return root->data;
		}
		
		char pop(){
			if(isEmpty())
				return numeric_limits<char>::min();
			
			Node* temp = root;
			char d = temp->data;
			root = root->next;
			delete temp;
			return d;
		}
		
		void display(){
			if(isEmpty())
				return;
			
			cout<< "displaying stack elements:" << endl;
			Node* t = root;
			while(t != NULL){
				cout<< t->data << endl;
				t = t->next;
			}
		}
};

bool balancedParenthesis(Stack s, string str){
	char c;
	
	for (int a = 0; a < str.length(); a++){
		if (str[a] == '(' || str[a] == '{' || str[a] == '['){
			s.push(str[a]);
		}
		
		else{
			// when there is a closing in str 
			// but no opening in stack
			if (s.isEmpty())
				return false;
			
			switch(str[a]){
				case ')':
					c = s.pop();
					if (c == '('){
						break;
					}
					else{
						return false;
					}
				case '}':
					c = s.pop();
					if (c == '{'){
						break;
					}
					else{
						return false;
					}
				case ']':
					c = s.pop();
					if (c == '['){
						break;
					}
					else{
						return false;
					}
			}
		}
	}
	
	if (!s.isEmpty())
		return false;
	return true;
}

int main(){
	Stack s;
	string str = "{()}[{}([])]";
 
    // Function call
    if (balancedParenthesis(s, str))
        cout << "Balanced";
    else
        cout << "Not Balanced";
	
	return 0;
}
