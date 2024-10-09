#include<iostream>
using namespace std;

void insertion(int arr[],int n){
  for(int i=1;i<n;i++){
    int temp = arr[i];
    int j=i-1;
    while(j>=0 && temp<arr[j]){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
  }
}
int main(){
    int arr[] = {18,3,8,4,87};
    insertion(arr,5);
    cout<<"Result after swapping is : "<<endl;
    for(auto i:arr){
        cout<<i <<" ";
    }
    cout<<endl;

}