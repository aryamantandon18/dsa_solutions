#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
    this -> data = d;
    this->left = NULL;
    this->right = NULL;        
    }
};

node* buildTree(node* root){
    cout<< "Enter the data" <<endl;
    int data ;
    cin>>data;
    root = new node(data);
    
    if(data == -1) return NULL;

    cout<<"Enter the data for the left of node " <<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter the data for the right of node " <<data<<endl;
    root->right = buildTree(root->right);
    return root ;
}
void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
    node* temp = q.front();
    q.pop();

    if(temp==NULL){
      cout<<endl;
      if(!q.empty()) q.push(NULL);
    }
    else{
    cout<<temp->data<<" ";
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
    }

    }
}

void inorderTraversal(node* root){
  if(root == NULL) return;
  inorderTraversal(root->left);
  cout<<root->data<<" ";
  inorderTraversal(root->right);
}

void preorderTraversal(node* root){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
  }

void postorderTraversal(node* root){
  if(root==NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout<<root->data<<" ";
} 

void buildTreeFromLevelOder(node* &root){
  queue<node*> q;
  cout<<"Enter data for root : "<<endl;
  int data;
  cin>>data;
  root = new node(data); 
  q.push(root);

  while(!q.empty()){
    node* temp = q.front();
    q.pop();

    cout<<"enter data for the left of the node "<<temp->data <<endl;
    int leftData;
    cin>>leftData;
    if(leftData!=-1){
      temp->left = new node(leftData);
      q.push(temp->left);
    }
  cout<<"enter data for the right of the node "<<temp->data <<endl;
    int rightData;
    cin>>rightData;
    if(rightData!=-1){
      temp->right = new node(rightData);
      q.push(temp->right);
    }
    
  }
}
main(){
    cout<<"Here we start to create Binay Tree"<<endl;
    node* root = NULL;
    // root = buildTree(root);
    buildTreeFromLevelOder(root);
    cout<<"out binaryTree will be like :-"<<endl;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    levelOrderTraversal(root);
    // cout<<endl;
    // inorderTraversal(root);
    // preorderTraversal(root);
    // postorderTraversal(root);
    return 0;
}


    