#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int coefficient;
        int exponent;
        char variable;
        Node *next;
    
        Node(){
            coefficient=0;
            exponent=0;
            variable=' ';
            next=NULL;
        }

        Node(int coefficient, int expoenent, char variable, Node *temp){
            this->coefficient=coefficient;
            this->exponent=expoenent;
            this->variable=variable;
            next=temp;
        }
};

class SinglyLL{
    public:
        Node *head;

    SinglyLL(){
        head=NULL;
    }

    void push_back(int coefficient, int exponent, char variable){
        Node *new_node= new Node(coefficient,exponent,variable,NULL);

        if(head==NULL){
            head=new_node;
            return;
        }

        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=new_node;
    }

    void printList(){
        cout<<get_length()<<endl;;
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->coefficient<<" "<<temp->variable<<" "<<temp->exponent<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }

    int get_length(){
        Node *temp=head;
        int count=1;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    void sortList2() {  
            //Node current will point to head  
            Node *current = head, *index = NULL;  
            int temp;  
            
            if(head == NULL) {  
                return;  
            }  
            else {  
                while(current != NULL) {  
                    //Node index will point to node next to current  
                    index = current->next;  
                    
                    while(index != NULL) {  
                        //If current node's data is greater than index's node data, swap the data between them  
                        if(current->variable > index->variable) {    
                            swap(current->coefficient,index->coefficient);
                            swap(current->variable,index->variable);
                            swap(current->exponent,index->exponent);
                        }  
                        index = index->next;  
                    }  
                    current = current->next;  
                }      
            }  
        }
    

    void sortList() {  
            //Node current will point to head  
            Node *current = head, *index = NULL;  
            int temp;  
            
            if(head == NULL) {  
                return;  
            }  
            else {  
                while(current != NULL) {  
                    //Node index will point to node next to current  
                    index = current->next;  
                    
                    while(index != NULL) {  
                        //If current node's data is greater than index's node data, swap the data between them  
                        if(current->exponent > index->exponent) {    
                            swap(current->coefficient,index->coefficient);
                            swap(current->variable,index->variable);
                            swap(current->exponent,index->exponent);
                        }  
                        index = index->next;  
                    }  
                    current = current->next;  
                }      
            }  
        } 

};

void del(Node *head, Node *n){
    if(head == n){
        if(head->next == NULL){
            return;
        }
 
        /* Copy the data of next node to head */
        head->coefficient = head->next->coefficient;
        head->variable = head->next->variable;
        head->exponent = head->next->exponent;
 
        // store address of next node
        n = head->next;
 
        // Remove the link of next node
        head->next = head->next->next;
 
        // free memory
        free(n);
 
        return;
    }
    // When not first node, follow
    // the normal deletion process
 
    // find the previous node
    Node *prev = head;
    while(prev->next != NULL && prev->next != n)
        prev = prev->next;
 
    // Check if node really exists in Linked List
    if(prev->next == NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
 
    // Remove node from Linked List
    Node *temp=prev->next;
    prev->next=prev->next->next;
    delete(temp);
 
    // Free memory
    
 
    return;
}

void addingtwopolynomials(Node *head1, Node *head2){
    //case where the lists are empty
    if(head1==NULL){
        head1=head2;
    }
    //When the lists are not empty
    Node *temp1=head1;
    Node *temp2=head2;
    Node *temp3=NULL;
    Node *temp4=NULL;

    while(temp1!=NULL){
        while(temp2!=NULL){
            if(temp1->variable==temp2->variable && temp1->exponent==temp2->exponent){
                temp1->coefficient+=temp2->coefficient; 
                del(head2,temp2);  
                         
            }
            temp2=temp2->next;
        }
        temp2=head2;
        temp1=temp1->next;
    }
    //for remaining elements int h
    temp1=head1;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    if(head2!=NULL){
        temp3=head2;
        temp4=head1;
        while(temp3!=NULL){
            while(temp4!=NULL){
                if(temp3->variable!=temp4->variable && temp3->exponent!=temp4->exponent){
                    Node *new_node= new Node(temp3->coefficient,temp3->exponent,temp3->variable,NULL);
                    temp1->next=new_node;
                }
                temp4=temp4->next;
            }
            temp3=temp3->next;
        }
    }
}


/*Polynomial are abstract mathematical concept generally used in algebra. 
A polynomial comprises of terms and each term is defined as coefficent,
variable and exponents of the variable. For example: 3X^2 is a term in which 3 is a coefficieent, 
X is a variable and 2 is the exponent. A polynomial can be comprises of many terms. 
You will be entered the number of terms in first polynomial and after reading it, 
you will be reading each term of the polynomial as a triplet, for example 3 X 2.
After reading first polynimal, you can read the second polynomial in the similar fashion. 
These polynomial terms are not in sorted order of their exponents. 
You are required to create a linked list of your choice to process these two polynomails. 
After reading these polynomials you are required to perform addition of these polynomials,
after that you are required to write the resultant polynomial in increasing order of exponents for each variable. */

int main(){
    int n1=0, n2=0;

    int coeffcient;
    char variable;
    int exponent;

    cin>>n1;
    SinglyLL list1;
    for(int i=0;i<n1;i++){
        cin>>coeffcient>>variable>>exponent;
        list1.push_back(coeffcient,exponent,variable);
    }

    cin>>n2;
    SinglyLL list2;
    for(int i=0;i<n2;i++){
        cin>>coeffcient>>variable>>exponent;
        list2.push_back(coeffcient,exponent,variable);
    }
    cout<<endl;

    addingtwopolynomials(list1.head,list2.head);
    list1.sortList();
    list1.sortList2();
    list1.printList();


    return 0;
}
