#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot = arr[s];
   int cnt=0;
   for(int i=0;i<e;i++){
    if(arr[i]< pivot) cnt++;
   }
   int pivotIndex = s+cnt;
   swap(arr[pivotIndex],arr[s]);

   int i=s,j=e;
   while(i<pivotIndex && j>pivotIndex){
    if(arr[i]<pivot) i++;
    if(arr[j]>pivot) j--;
      if(i<pivotIndex && j>pivotIndex){
        swap(arr[i],arr[j]);
      }
   }

   return pivotIndex;
}
void QuickSort(int arr[],int s,int e){
  if(s>=e) return;

  int p = partition(arr,s,e);
  QuickSort(arr,s,p-1);
  QuickSort(arr,p+1,s);

}

int main(){
    int arr[] = {18,3,8,4,87};
    QuickSort(arr,0,5);
    cout<<"Result after swapping is : "<<endl;
    for(auto i:arr){
        cout<<i <<" ";
    }
    cout<<endl;
}