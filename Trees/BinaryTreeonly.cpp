#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
 public:
    int key;
    TreeNode* left; 
    TreeNode* right;
 
    TreeNode(int item)
    {
        key = item;
        left = right = NULL;
    }
};

class BinaryTree{
	TreeNode* root;
	
	public:
	BinaryTree(){
		root = NULL;
	}
	
	void insertNode(int data)
	{
	    // If the tree is empty, assign new node address to root
	    if (root == NULL) {
	        root = new TreeNode(data);
	        return;
	    }
	 
	    // Else, do level order traversal until we find an empty
	    // place, i.e. either left child or right child of some
	    // node is pointing to NULL.
	    queue<TreeNode*> q;
	    q.push(root);
	 
	    while (!q.empty()) {
	        TreeNode* temp = q.front();
	        q.pop();
	 
	        if (temp->left != NULL)
	            q.push(temp->left);
	        else {
	            temp->left = new TreeNode(data);
	            return;
	        }
	 
	        if (temp->right != NULL)
	            q.push(temp->right);
	        else {
	            temp->right = new TreeNode(data);
	            return;
	        }
	    }
	}
  
  bool findPath(Node *root, vector<int> &path, int k)
  {
      // base case
      if (root == NULL) return false;

      // Store this node in path vector. The node will be removed if
      // not in path from root to k
      path.push_back(root->key);

      // See if the k is same as root's key
      if (root->key == k)
          return true;

      // Check if k is found in left or right sub-tree
      if ( (root->left && findPath(root->left, path, k)) ||
           (root->right && findPath(root->right, path, k)) )
          return true;

      // If not present in subtree rooted with root, remove root from
      // path[] and return false
      path.pop_back();
      return false;
  }

  // Returns LCA if node n1, n2 are present in the given binary tree,
  // otherwise return -1
  int findLCA(Node *root, int n1, int n2)
  {
      // to store paths to n1 and n2 from the root
      vector<int> path1, path2;

      // Find paths from root to n1 and root to n1. If either n1 or n2
      // is not present, return -1
      if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
            return -1;

      /* Compare the paths to get the first different value */
      int i;
      for (i = 0; i < path1.size() && i < path2.size() ; i++)
          if (path1[i] != path2[i])
              break;
      return path1[i-1];
  }
	
	void printBT(){
		if (root == NULL) {
			cout << "Empty Tree" << endl;
			return;
		}
		queue<TreeNode*> q;
	    q.push(root);
		
		while (!q.empty()){
			TreeNode* temp = q.front();
	        q.pop();
	        cout << "\t\tp: " << temp->key << " \n";
	        if (temp->left != NULL){
	        	q.push(temp->left);
	        	cout << "\tl: " << temp->left->key;
			}
			else
	            cout << "\tl: NULL";
	        if (temp->right != NULL){
	            q.push(temp->right);
	            cout << "\t\tr: " << temp->right->key << endl;
	        }
			else
	            cout << "\tr: NULL" << endl;
		}
	}	
	
	int getHeight(){
		if(root == NULL) 
			return -1 ;
      	else 
	  		return getHeightRec(root)-1;
  	}
  	
  	int getHeightRec(TreeNode* tn){
  		if (tn == NULL)
  			return 0;
  		else
  			return 1 + max(getHeightRec(tn->left), getHeightRec(tn->right));
	}
  
  Node* lowest_common_ancestor(Node *node1,Node *node2){

    vector<Node*> node1_ancestors;// Initialize a vector to store information in
    Node* curr = node1;

    while(curr!=NULL){
      curr = curr -> parent;
      if(curr!=NULL){
        node1_ancestors.push_back(curr);// Store the ancestors of node1
      }
    }

    Node* lowest_ancestor = NULL;
    curr = node2;
    while(curr!=NULL){
      curr = curr->parent;
      for(int i=0;i<node1_ancestors.size();i++){
        if(node1_ancestors[i]==curr){ // Find the first ancestor common to both node1 and node2
          lowest_ancestor = curr;
          return lowest_ancestor;// Return THE lowest common ancestor
        }
      }    

    }

  return lowest_ancestor;// Otherwise return null
}
};

int main()
{
	/* Create the following tree

               1
            /     \
           2       3
          / \     / \
         4  NULL NULL NULL
        / \
     NULL NULL

    */
 
	BinaryTree bt;
	bt.insertNode(1);
	bt.insertNode(2);
	bt.insertNode(3);
	bt.insertNode(4);
//	bt.insertNode(5);
//	bt.insertNode(6);
//	bt.insertNode(7);
//	bt.insertNode(8);
	bt.printBT();
	cout << bt.getHeight();
    
    return 0;
}
