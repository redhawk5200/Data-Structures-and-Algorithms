void inorder(Node *root,vector<int>&vect)
   {
       if(root==NULL)
           return;
       inorder(root->left,vect);
       vect.push_back(root->data);
       inorder(root->right,vect);
   }
   vector<int> merge(Node *root1, Node *root2)
   {
      //Your code here
      vector<int>v1,v2,vect;
      inorder(root1,v1);
      inorder(root2,v2);
      int n1=v1.size(),n2=v2.size(),i=0,j=0;
      while(i<n1 && j<n2)
      {
          if(v1[i]<v2[j])
              vect.push_back(v1[i++]);
          else
           vect.push_back(v2[j++]);
      }
      while(i<n1)
           vect.push_back(v1[i++]);
      while(j<n2)
           vect.push_back(v2[j++]);
      return vect;
   }
