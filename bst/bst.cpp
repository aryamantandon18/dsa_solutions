// Time complexity = O(logN)  same as binary search
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
Node *insertIntoBst(Node *root, int d)
{
  if (root == NULL)
  {
    root = new Node(d);
    return root;
  }
  if (d < root->data)
  {
    root->left = insertIntoBst(root->left, d);
  }
  else
  {
    root->right = insertIntoBst(root->right, d);
  }
  return root;
}
void takeInput(Node *&root)
{
  int data;
  cin >> data;
  while (data != -1)
  {
    root = insertIntoBst(root, data);
    cin >> data;
  }
}
Node *max(Node *root)
{
  Node *temp = root;
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp;
}
Node* min(Node *root){
  Node* temp = root;
  while(temp->left !=NULL){
    temp = temp->left;
  }
  return temp;
}
void levelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
}
Node* deletion(Node* root,int val){
  if(root==NULL) return root;
  if(root->data == val){
    //0 child
    if(root->left == NULL && root->right==NULL){
      delete root;
      return NULL;
    }

    //1 child
    //left 
    if(root->left!=NULL && root->right==NULL){
      Node* temp = root->left;
      delete root; 
      return temp;
    }
    //right
    if(root->left==NULL && root->right!=NULL){
      Node* temp = root->right;
      delete root;
      return temp;
    }

    //2 child
    if(root->left!=NULL && root->right!=NULL){
      int mini = min(root->right)->data;
      root->data = mini;
      root->right = deletion(root->right,mini);
      return root;
    }
  }
  if(root->data>val){
    root->left = deletion(root->left,val);
    return root;
  }  
  else{
    root->right = deletion(root->right,val);
    return root;
  }

  
}
int main()
{
  Node *root = NULL;
  cout << "Enter data :- " << endl;
  takeInput(root);
  cout << "here is out BST :- " << endl;
  levelOrderTraversal(root);
  cout<< "maximum value in bst is -> " <<max(root)->data<<endl;
  deletion(root,27);
  cout<<"BST after deletion "<<endl;
  levelOrderTraversal(root);
  return 0;
}
// 10 8 21 7 27 5 4 3 -1
// Binary Tree from preorder & inorder AND postorder & inorder
// BST from Preorder