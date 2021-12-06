#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }

};

Node *insert(Node *root, int data){
    Node *new_node= new Node(data);

    if(root==NULL){
        root=new_node;
    }
    else if(data>root->data){
        root->right= insert(root->right, data);
    }
    else{
        root->left= insert(root->left, data);
    }

    return root;
}

bool check_BST(Node *root, int min, int max){
    //this is to check if we have reached to the end of the tree or not
    if(root==NULL){
        return true;
    }
    //now this is to check if the key given is in the range considering the key of the parent
    if(root->data<min || root->data>max){
        return false;
    }
    //then checking all the nodes to the trees to follow the rules of the BST
    return check_BST(root->left,min,root->data) && check_BST(root->right,root->data,max);
}

int main(){
    //creating a tree with a single root node
    Node *root= new Node(40);
    root->left= new Node(20);
    root->right=new Node(50);
    root->left->left=new Node(10);
    root->left->right=new Node(30);
    root->right->left=new Node(45);
    root->right->right=new Node(60);

    // int n, data;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>data;
    //     root=insert(root,data);
    // }


    if(check_BST(root,INT_MIN, INT_MAX)){
        cout<<"The tree is BST";
    }
    else{
        cout<<"The tree isn't a BST";
    }

    return 0;
}
