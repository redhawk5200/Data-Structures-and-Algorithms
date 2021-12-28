#include<bits/stdc++.h>

using namespace std;

#define MAX 50

class Queue{
    public:
        int rear;
        int front;
        string familyname[MAX];
        int familymembers[MAX];

    Queue(){
        rear=front=-1;
    }

    bool isempty(){
        if(rear==-1 && front==-1 || front>rear){
            return true;
        }
        return false;
    }

    bool isfull(){
        if(rear>MAX-1){
            return true;
        }
        return false;
    }

    void push(string s, int n){
        int i;
        if(front==-1 && rear==-1){
            front=rear=0;
            familymembers[front]=n;
            familyname[front]=s;
        }
        else{
            for(i=rear;i>=0;i--){
                if(n>familymembers[i]){
                    familymembers[i+1]=familymembers[i];
                    familyname[i+1]=familyname[i];
                }
                else{
                    break;
                }
            }
            familyname[i+1]=s;
            familymembers[i+1]=n;
            rear++;
        }
    }

    void pop()
		{
			front++;
		}
		string peek()
		{
			return familyname[front];
		}

};

int main(){

    Queue q;
	
	// q.push(5);
	// q.push(6);
	// q.push(8);
	
	q.push("fam1",1);
	q.push("fam2",8);
	q.push("fam3",10);
	q.push("fam4",13);
	q.push("fam5",5);
	
	
	while(!q.isempty())
	{
		cout<<q.peek()<<" ";
		q.pop();
	}

    return 0;
}