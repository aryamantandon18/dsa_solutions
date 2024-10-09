#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(node* &head,int d){
    node *temp =new node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(node* &tail,int d){
    node *temp =new node(d);
    tail->next = temp;
    tail = temp;
    
}
void Print(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtPosition(node *&head,node *&tail,int position,int d){
    if(position == 1 ){
     insertAtHead(head,d);
     return ;
    }   
    node *temp = head;
    int count = 1;
    while(count < position-1 ){
        temp = temp-> next;
        count++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}

void deleteNode(node *&head,int position){
    if(position == 1){
        node *temp =head;
        head=head->next;
        delete temp;
    }
    else{
        node *curr = head;
        node *prev = NULL;
        int count=1;
        while(count<position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev -> next =curr-> next;
        delete curr;
        
    }
}
void bubbleSort(node* &head) {
    if (head == NULL || head->next == NULL) {
        // Empty or single-element list is already sorted
        return;
    }

    bool swapped;
    node* current;
    node* lastSorted = NULL;

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Swap the nodes' data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }

        lastSorted = current;
    } while (swapped);
}
int main(){
node *node1= new node(7);
node *head = node1;
node *tail = node1;
Print(head);
insertAtHead(head , 12);
Print(head);
insertAtPosition(head,tail,3,21);
Print(head);
insertAtPosition(head,tail,2,11);
Print(head);
deleteNode(head,3);
Print(head);
bubbleSort(head);
Print(head);
return 0;
}