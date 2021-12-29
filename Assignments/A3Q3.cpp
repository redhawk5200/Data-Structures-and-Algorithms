#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int data){
        this->data=data;//
        left=right=NULL;
    }
};

class BinaryTree{
    public:
        Node *root;

    BinaryTree(){
        root=NULL;
    }

    Node *insertNode(Node *root, int data){
        Node *new_node= new Node(data);
        if(root==NULL){
            root=new_node;
        }
        else if(data>root->data){
            root->right=insertNode(root->right,data);
        }
        else{
            root->left=insertNode(root->left,data);
        }

        return root;
    }
};




void maxhelper(vector<int>& Max, Node* root, int index)
{
    if(root==NULL){
        return;
    }
    if (index == Max.size()){
        Max.push_back(root->data);
    }
    else{
        Max[index]=max(Max[index],root->data);
    }

    maxhelper(Max,root->left,index+1);
    maxhelper(Max,root->right,index+1);
}

void minhelper(vector<int>& Min, Node* root, int index)
{
    if(root==NULL){
        return;
    }
    if (index == Min.size()){
        Min.push_back(root->data);
    }
    else{
        Min[index]=min(Min[index],root->data);
    }
 
    minhelper(Min,root->left,index+1);
    minhelper(Min,root->right,index+1);
}
 
vector<int> findMax(Node* root){
    vector<int> res;
    maxhelper(res, root, 0);
    return res;
}

vector<int> findMin(Node* root){
    vector<int> res;
    minhelper(res, root, 0);
    return res;
}
int main(){
    BinaryTree b1;
    int n, element;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>element;
        b1.root=b1.insertNode(b1.root,element);
    }

    vector<int> Max = findMax(b1.root);
    vector<int> Min = findMin(b1.root);
    
    cout<<endl;
    for (int i = 0; i < Max.size(); i++){
        cout << Min[i] << " "<<Max[i]<<endl;
    }

    return 0;
}
