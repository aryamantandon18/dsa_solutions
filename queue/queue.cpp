#include<iostream>
using namespace std;
#include<queue>
#include<stack>

queue<int> rev(queue<int> q){
stack<int> s;
while(!q.empty()){
    int element = q.front();
    q.pop();
    s.push(element);
}
while(!s.empty()){
    int e = s.top();
    s.pop();
    q.push(e);
}
return q;
}
int main(){
    queue<int> q;
    queue<int> p;
    p.push(89);
     q.push(1);
     q.push(2);
     q.push(5);
     q.push(7);
    //   q.pop();
     cout<< "Front is -> "<<q.front() <<endl;
     cout<<"Back is -> " <<q.back() <<endl;
    //  cout<<q.size();
    queue<int> s = rev(q);
    cout<<"after reverse"<<endl<<endl;
     cout<< "Front is -> "<<s.front() <<endl;
     cout<<"Back is -> " <<s.back() <<endl;

}