#include<iostream>
using namespace std;

// Time Complexity = O(1); 
class Queue{
    int qfront;
    int qback;
    int* arr;
    int size;

    public:
    //constructor
    Queue(){
        size = 100001;
        arr = new int[size];
      qfront =0;
      qback = 0;
    }

    int empty(){
        if(qback==size){
            return 1;
        }
        else return 0;
    }
    void push(int data){
     if(qback == size){
      cout<< "queue is full";
     }
     else {
      arr[qback]= data;
      qback++;
     }
    }
   void pop(){
        if(qfront == qback){
            cout<< "queue is empty"<<endl;
        }
        else{
            arr[qfront] = -1;
            qfront++;
            if(qfront == qback){
                qfront  = 0;
                qback = 0;
            }
        }
    }
   int front(){
    if(qfront == qback) {   return -1;  }

    else{return arr[qfront];}
   }
   int back(){
    if(qfront == qback) return -1;
    else return arr[qback-1];
   }
    

};

int main(){
    Queue q;
    q.push(1);
    q.push(56);
    q.push(78);
    q.push(81);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.empty();
}