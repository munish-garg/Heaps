#include<iostream>
#include<queue>
using namespace std;
void runningMedian(int *a, int n){
    priority_queue<int> leftHeap; //MaxHeap...
    priority_queue<int, vector<int>, greater<int>> rightHeap; //MinHeap...
    int median = a[0];
    cout<<median<<" ";
    leftHeap.push(a[0]);
    for(int i=1;i<n;i++){
        int ele = a[i];
        if(leftHeap.size() < rightHeap.size()){
            if(ele > median){
                //If the element is more than the current median, then..
                //It means the median will be influenced by the just larger element...
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(ele);
            }   
            else{
                leftHeap.push(ele);
            }
            median = (leftHeap.top() + rightHeap.top())/2;
        }
        else if(rightHeap.size() < leftHeap.size()){
            if(ele < median){
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(ele);
            }
            else{
                rightHeap.push(ele);
            }
            median = (leftHeap.top() + rightHeap.top())/2;
        }
        else{
            //It means that size of both the heaps is equal...
            if(ele < median){
                leftHeap.push(ele);
                median = leftHeap.top();
            }
            else{
                rightHeap.push(ele);
                median = rightHeap.top();
            }
        }
        cout<<median<<" ";
    }
    cout<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        runningMedian(a, n);
    }
    return 0;
}