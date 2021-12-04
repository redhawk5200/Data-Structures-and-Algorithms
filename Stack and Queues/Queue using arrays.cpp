#include<bits/stdc++.h>
using namespace std;



class Queue{

    public:
        int front, rear;
        int unsigned capacity;
        int *array;
        
        bool isEmpty(){
            if(front==-1 && rear==-1 || front>rear){
                return true;
            }
            return false;
        }

        bool isFull(){
            if(rear==capacity-1){
                return true;
            }
            return false;
        }

        void enqueue(int data){
            if(isFull()){
                cout<<"Queue is full";
                return;
            }
            else if(isEmpty()){
                front=rear=0;
            }
            else{
                rear++;
            }
            array[rear]=data;
        }

        int peek(){
            return array[front];
        }

        int count(){
            return (rear-front+1);
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is already empty."<<endl;
                return; 
            }
            else if(front>rear){
                front=rear=-1;
            }
            else{
                array[front++]=0;
            }
        }

        void display() {
            cout << "All values in the Queue are: ";
            for (int i = 0; i < capacity; i++) {
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }

};

Queue* createQueue (int capacity){
    Queue* queue= new Queue();
    queue->capacity=capacity;
    queue->front=queue->rear=-1;
    queue->array= new int[capacity];

    return queue;
}

int main(){

    int size, n;
    cout<<"Enter the size of the queue you want to make: ";
    cin>>size;

    Queue *new_queue=createQueue(size);
    for(int i=0;i<size;i++){
        cin>>n;
        new_queue->enqueue(n);
    }
    new_queue->display();

    for(int i=0;i<size;i++){
        new_queue->dequeue();
    }
    new_queue->display();


    return 0;
}