#include<iostream>
#include<vector>
using namespace std;
void buildHeap(vector<int> &v){
    for(int i=2;i<v.size();i++){
        int idx = i;
        int parent = idx/2;
        while(v[idx] > v[parent] && idx > 1){
            swap(v[idx], v[parent]);
            idx = parent;
            parent/=2;
        }
    }
}
int main(){
    //Inplace conversion of the vector into max heap;
    vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    //Calling the function for building the heap..
    buildHeap(v);
    vector<int>::iterator it = v.begin();
    it++;
    for(;it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}