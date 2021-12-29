int getCount(Node root,int l, int h)
   {
       //Your code here
       int c=0;
       if(root==null)
        return c;
       Queue<Node> q = new LinkedList<>();
       q.add(root);
       while(!q.isEmpty()){
           for(int i=0;i<q.size();i++)
           {
               Node curr=q.poll();
               if(curr.data>=l && curr.data<=h)
                c++;
               if(curr.left!=null)
                 q.add(curr.left);
               if(curr.right!=null)
                 q.add(curr.right);
           }
       }
       return c;
   }
}

