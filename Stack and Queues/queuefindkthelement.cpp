#include <iostream>
using namespace std;

#define MAX 50

class queue{
	
	public:
		
		int front;
		int rear;
		int arr[MAX];
		queue()
		{
			front=rear=-1;
		}	
		bool isempty()
		{
			if(front==-1&&rear==-1)
			{
				return true;
			}
			if(front>rear)
				return true;
				
			return false;
		}
		bool isfull()
		{
			if(rear > MAX)
			{
				cout<<"queue etelaam";
			}
		}
		void push(int data)
		{
			if(front==-1&&rear==-1)
			{
				front=rear=0;
				arr[rear]=data;
			}
			else
			{
				int x;
				for(x=rear;x>=front;x--)
				{
					if(data<arr[x])
					{
						arr[x+1]=arr[x];
					}
					else
					{
						break;
					}
				}
				
				arr[x+1]=data;
				rear++;
			}
		}
		void pop()
		{
			front++;
		}
		int peek()
		{
			return arr[front];
		}
};

void findkth(int arr[],int k)
{
	queue q;
	
	for(int i=0;i<k;i++)
	{
		q.push(arr[i]);
	}
	for(int i=k;i<6;i++)
	{
		if(q.peek() < arr[i])
		{
			q.pop();
			q.push(arr[i]);	
		}	
	}	
	cout<<q.peek();		
}
int main()
{

	int arr[6]={20,10,60,30,50,40};
	findkth(arr,3);	
}
