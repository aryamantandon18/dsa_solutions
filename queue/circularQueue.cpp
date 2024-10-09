class MyCircularQueue {
    int* arr;
    int front;
    int rear;
    int size;

public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    // normally we push from front
    bool enQueue(int value) {
        //check if the queue if full or not 
        if((front == 0 && rear==size-1) || (rear == (front-1))){
            return false;
        }
        // check for empty
        else if( front==-1 ){
           front=rear=0;
           arr[rear] = value;
        }
        
        else if(rear == size-1 && front!=0){
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    // normally we pop from the rear
    bool deQueue() {
        //check for empty
        if(front == -1){
            return false;
        }
        //single element check
        else if(front == rear ){
        front  = rear = -1;
        }
        else if(front == size -1 ){
            front = 0;  // to maintain cyclic nature.
        }
        else{
            front ++;
        }
        return true;
    }
    
    int Front() {
        if(front == -1){
            return -1;
        }
        else return arr[front];
    }
    
    int Rear() {
      if(front == -1) return -1;
      else return arr[rear];  
    }
    
    bool isEmpty() {
        if(front == -1)  return true;
        else return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || (rear == (front-1)))   return true;
        else return false;
    }
};