#include<iostream>
#include<algorithm>
using namespace std;


void selection(int arr[],int n){
   
    for(int i=0;i<n-1;i++){
         int mini = i;
  for(int j=i;j<n;j++){
   if(arr[j]<arr[mini]) mini = j;
  }
  swap(arr[i],arr[mini]);
 }
}
int main(){
    int arr[] = {18,3,8,4,87};
    selection(arr,5);
    for(auto i:arr){
        cout<<i <<" ";
    }
    cout<<endl;

}