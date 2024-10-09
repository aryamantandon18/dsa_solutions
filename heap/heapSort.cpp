#include<iostream>
#include<algorithm>   //for sort function
using namespace std;

void heapify(int arr[],int n,int i){
   int largest  = i;
   int left = 2*i+1;
   int right = 2*i+2;

   if(left<n && arr[largest]<arr[left]){
    largest = left;
   }
   if(right<n && arr[largest] < arr[right]){
    largest = right;
   }
   if(largest != i){
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
   }
}
void heapSort(int arr[],int n){
    int size = n-1;
    while(size>0){
        swap(arr[size],arr[0]);
        size--;
        heapify(arr,size,0);
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int arr[]={1,5,2,6,3,7};
    int n = (sizeof(arr)/sizeof(arr[0]));

    for(int i= n/2-1 ; i>=0 ; i--){
        heapify(arr,n,i);
    }
    cout<<"Heapified array is -> "<<endl;
    print(arr,n);

    cout<<"Sorted arrya is ->" << endl;
    heapSort(arr,n);
    print(arr,n);
 
}