#include<queue>>
#include<iostream>

using namespace std;

int main(){ 
    // priority_queue<int> maxHeap;   for max heap
    priority_queue<int ,vector<int>,greater<int> > minHeap;

    minHeap.push(6);
    minHeap.push(7);
    minHeap.push(2);
    minHeap.push(3);
    cout<<"Top element in min heap is -> "<<minHeap.top();

  
}