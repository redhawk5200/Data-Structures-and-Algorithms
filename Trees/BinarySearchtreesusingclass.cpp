#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(){
            data=0;
            left=right=NULL;
        }

        Node(int n){
            data=n;
            left=right=NULL;
        }
};



class BinaryTree{
    public:
        Node* root;

        BinaryTree(){
            root=NULL;
        }

    Node* insert(Node* root, int data){
        Node* new_node= new Node(data);
        if(root==NULL){
            root=new_node;
        }
        else if(data<root->data){
            root->left=insert(root->left,data);
        }
        else if(data>root->data){
            root->right=insert(root->right,data);
        }
        else{
            cout<<"Same data cannnot be repeated. ";
        }
        return root;
    }

    bool check_BST(Node *root, int min, int max){
        if(root==NULL){
            return true;
        }

        if(root->data<min ||root->data>max){
            return false;
        }

        return check_BST(root->left,min,root->data) && check_BST(root->right,root->data,max);
    }

    bool search(Node* root, int key){
        if(root!=NULL){
            if(root->data==key){
                return true;
            }
            else if(key<root->data){
                return search(root->left,key);
            }
            else{
                return search(root->right,key);
            }
        }
        else{
            return false;
        }
    }

    Node* minValueNode(Node* root){
        Node* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    Node *delete_node(Node* root, int data){
        if(root==NULL){
            return root;
        }
        else if(data<root->data){
            root->left=delete_node(root->left,data);
        }
        else if(data>root->data){
            root->right=delete_node(root->right,data);
        }
        else{
            if(root->left==NULL){
                Node *temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                Node *temp=root->left;
                delete root;
                return temp;
            }
            else{
                Node *temp=minValueNode(root->right);
                root->data=temp->data;
                root->right=delete_node(root->right,root->data);
            }
        }
        return root;
    }

    int get_height(Node *root){
        if(root==NULL){
            return -1;
        }
        return 1+ max(get_height(root->left),get_height(root->right));
    }

    int get_depth(Node *root){
        if(root==NULL){
            return 0;
        }
        return 1+ max(get_depth(root->left),get_depth(root->right));
    }


    int total_nodes(Node *root){
        if(root==NULL){
            return 0;
        }
        return (total_nodes(root->left) +1+ total_nodes(root->right));
    }

    int find_completenodes(Node* node)
    {
        // If tree is empty
        if (!node)
            return 0;
        queue<Node *> q;
        
        // Do level order traversal starting from root
        int count = 0; // Initialize count of full nodes
        q.push(node);
        while (!q.empty())
        {
            struct Node *temp = q.front();
            q.pop();
    
            if (temp->left && temp->right)
                count++;
                
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        return count;
    }

    int find_leafnodes(Node* node)
    {
        // If tree is empty
        if (!node)
            return 0;
        queue<Node *> q;
        
        // Do level order traversal starting from root
        int count = 0; // Initialize count of full nodes
        q.push(node);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
    
            if (!temp->left && !temp->right)
                count++;
                
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        return count;
    }
        
    int find_non_leafnodes(Node* node)
    {
        return total_nodes(node)-find_leafnodes(node);
    }

    int find_descendants(Node *root,int key){
        if(root!=NULL){
            if(key<root->data){
                return find_descendants(root->left,key);
            }
            else if(key>root->data){
                return find_descendants(root->right,key);
            }
            else{
                queue<Node *> q;
        
                // Do level order traversal starting from root
                int count = -1; 
                q.push(root);
                while (!q.empty())
                {
                    Node *temp = q.front();
                    q.pop();
            
                    count++;
                        
                    if (temp->left != NULL)
                        q.push(temp->left);
                    if (temp->right != NULL)
                        q.push(temp->right);
                }
                return count;
            }
        }
        else{
            return 0;
        }
       
    }

    bool print_ancestors(Node *root, int key){
        if(root==NULL){
            return false;
        }
        if(root->data==key){
            return true;
        }

        if((print_ancestors(root->left,key)) || (print_ancestors(root->right,key))){
            cout<<root->data<<" ";
            return true;
        }

        return false;
    }

};

void postorder(Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    
    postorder(root->right);

    cout<<root->data<<" ";
}



void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    preorder(root->left);
    
    preorder(root->right);
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void BFS(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* current= q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
        q.pop();
    }
    cout<<endl;
}

void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
 
    } /* end of while */
}

void iterativePreorder(node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty stack and push root to it
    stack<node*> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        struct node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    // Create two stacks
    stack<Node *> s1, s2;
 
    // push root to first stack
    s1.push(root);
    Node* node;
 
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);
 
        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

int main(){
    BinaryTree B;
    int n;
    int data;
    cout<<"Enter the number of nodes you want to make: ";
    cin>>n;

    for(int i=0;i<n;i++){
        fflush(stdin);
        cout<<"Enter the data of node "<<i+1<<" :";
        cin>>data;
        B.root=B.insert(B.root,data);
    }

    //BFS
    BFS(B.root);

    //DFS
    inorder(B.root);
    cout<<endl;
    // preorder(B.root);
    // postorder(B.root);

    // //check binary search tree
    // if(B.check_BST(B.root,INT_MIN, INT_MAX)){
    //     cout<<"This tree is BST."<<endl;
    // }
    // else{
    //     cout<<"This tree isn't a BST."<<endl;
    // }

    // //searching of node with data 54
    // if(B.search(B.root,54)){
    //     cout<<"Found."<<endl;
    // }
    // else{
    //     cout<<"Not found"<<endl;
    // }

    // //deletion of node with data 2
    // B.delete_node(B.root,5);

    // //height of the tree
    // cout<<endl<<"Height of the tree is: "<<B.get_height(B.root)<<endl;

    // //get number of nodes
    // cout<<endl<<"Nodes of the tree are: "<<B.total_nodes(B.root)<<endl;

    // //get depth of any node
    // cout<<endl<<"Depth of this node is: "<<B.get_depth(B.root)<<endl;

    // //complete nodes in this tree
    // cout<<endl<<"Number of complete nodes in this tree are: "<<B.find_completenodes(B.root)<<endl;

    // //leaf nodes in this tree
    // cout<<endl<<"Number of leaf nodes in this tree are: "<<B.find_leafnodes(B.root)<<endl;

    // //neither nodes in this tree
    // cout<<endl<<"Number of non-leaf nodes in this tree are: "<<B.find_non_leafnodes(B.root)<<endl;

    //find descandants of a node
    cout<<"Descandants of this node: "<<B.find_descendants(B.root,5);

    //print ancestors of a node
    cout<<"Ancesters of node with data 1 are: ";
    B.print_ancestors(B.root,1);

    return 0;
}
