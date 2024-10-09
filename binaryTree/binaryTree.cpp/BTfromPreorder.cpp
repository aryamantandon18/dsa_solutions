struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int val){
      This->data = val;
      This->right = NULL;
      This->left = NULL;
  }
};

class Solution{
    private:
    int findPos(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element) return i;
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &i,int n,int inOrderStart,int inOrderEnd){
        if(i>=n || inOrderStart>inOrderEnd) return NULL;
        
        int element = pre[i++];
        Node* root = new Node(element);
       int pos = findPos(in,element,n);
       //recursive calls
        root->left = solve(in,pre,i,n,inOrderStart,pos-1);
        root->right = solve(in,pre,i,n,pos+1,inOrderEnd);
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int i=0;
       Node* ans= solve(in,pre,i,n,0,n-1);
       return ans;
        
    }
};