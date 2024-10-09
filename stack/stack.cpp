#include<iostream> 
using namespace std;

class stack{
    public:
    int *arr;
    int top;
    int size;
    //constructor
    stack(int size){
        this->size = size;
        arr = new int[size];        //This dynamically allocates an array of integers on the heap.
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
     top++;
     arr[top] = element;}
     else{
        cout<<"Stack Overflow"<<endl;
     }
    }
    void pop(int element){
        if(top>=0){
         top--;
     }
     else{
        cout<<"Stack underflow"<<endl;

     }
    }
    int peek(){
        if(top>-1){
           return arr[top];
        }
        else{
            cout<<"Stack is empty" << endl;
            return -1;
        }
    }
    bool isempty(){
        if(top == -1) return true;
        else return false;
    }


   
};
main(){
stack st(3);
st.push(5);
st.push(6);
st.push(7);
cout<<st.peek();


}




























































































































































































































































































