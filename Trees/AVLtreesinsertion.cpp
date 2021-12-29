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

class AVLTree{
    public:
        Node *root;

    AVLTree(){
        root=NULL;
    }
};

int get_height(Node *root){
    if(root==NULL){
        return -1;
    }

    return 1+max(get_height(root->left), get_height(root->right));
}

int getBalanceFactor(Node *root){
    if(root==NULL){
        return -1;
    }
    else{
        return (get_height(root->left)-get_height(root->right));
    }
}

Node *leftRotate(Node *root){
    Node *temp1=root->right;
    Node *temp2=temp1->left;

    temp1->left=root;
    root->right=temp2;

    return temp1;
}

Node *rightRotate(Node *root){
    Node *temp1=root->left;
    Node *temp2=temp1->right;

    temp1->right=root;
    root->left=temp2;

    return temp1;
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

Node *insertAVL(Node *root, int data){
    Node *new_node= new Node(data);
    if(root==NULL){
        root=new_node;
        return root;
    }
    if(data>root->data){
        root->right=insertAVL(root->right,data);
    }
    else if(data<root->data){
        root->left=insertAVL(root->left,data);
    }
    else{
        cout<<"Duplicates are not allowed. ";
        return root;
    }

    int bf = getBalanceFactor(root);
    // Left Left Case  
    if (bf > 1 && new_node -> data < root -> left -> data)
      return rightRotate(root);

    // Right Right Case  
    if (bf < -1 && new_node -> data > root -> right -> data)
      return leftRotate(root);

    // Left Right Case  
    if (bf > 1 && new_node -> data > root -> left -> data) {
      root -> left = leftRotate(root -> left);
      return rightRotate(root);
    }

    // Right Left Case  
    if (bf < -1 && new_node -> data < root -> right -> data) {
      root -> right = rightRotate(root -> right);
      return leftRotate(root);
    }

    /* return the (unchanged) node pointer */
    return root;
}  

bool check_BT(Node *root){
    //checking if the tree is empty or not
    if(root==NULL){
        return 1;
    }

    //getting the height of the left and right subtree
    int leftheight=get_height(root->left);
    int rightheight=get_height(root->right);

    //calling recursive  function on the preceding nodes while checking the balance factor {-1,0,1} of all the subtrees
    if(abs(leftheight-rightheight)<=1 && check_BT(root->left) && check_BT(root->right)){
        return 1;
    }
    //return false if no condition works
    return 0;

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

void inorder(Node *root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    AVLTree b1;

    int arr[11]={55, 66, 77, 11, 33, 22, 35, 25, 44, 88,99 };
    for(int i=0;i<11;i++){
        b1.root=insertAVL(b1.root,arr[i]);
    }

    inorder(b1.root);

    if(check_BST(b1.root,INT_MIN, INT_MAX) && check_BT(b1.root)){
        cout<<"The tree is BBST"<<endl;
    }
    else{
        cout<<"The tree isn't a BBST"<<endl;
    }

    int height= get_height(b1.root);
    cout<<endl<<"Height of the tree is: "<<height;



    return 0;
}