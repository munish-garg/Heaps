//build Heap optimised..
#include<iostream>
#include<vector>
using namespace std;
void heapify(int idx, vector<int>& v){
    int left = 2*idx;
    int right = left + 1;
    int max_idx = idx;
    if(left < v.size()){
        if(v[left] > v[max_idx]){
            max_idx = left;
        }
    }
    if(right < v.size()){
        if(v[right] > v[max_idx]){
            max_idx = right;
        }
    }
    if(max_idx!=idx){
        swap(v[max_idx], v[idx]);
        heapify(max_idx, v);
    }
}
void buildHeap(vector<int> &v){
    for(int i = (v.size()-1)/2;i>=1;i--){
        heapify(i,v);
    }
}
int main(){
    vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    vector<int>::iterator it = v.begin();
    it++;
    for(;it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //Calling the function for building the heap in an optimized way...
    buildHeap(v);
    //Printing the vector again to check the heap..
    it = v.begin();
    it++;
    while(it!=v.end()){
        cout<<*it<<" ";
        it++;
    }
    return 0;
}