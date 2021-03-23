//heap sort...
#include<iostream>
#include<vector>
using namespace std;
void heapify(int idx, int effectiveSize, vector<int> &v){
    int left = 2*idx;
    int right = left + 1;
    int max_idx = idx;
    if(left < effectiveSize){
        if(v[left] > v[idx]){
            max_idx = left;
        }
    }
    if(right < effectiveSize){
        if(v[right] > v[max_idx]){
            max_idx = right;
        }
    }
    if(max_idx!=idx){
        swap(v[idx], v[max_idx]);
        heapify(max_idx, effectiveSize, v);
    }
    return ;
}
void heapSort(vector<int> &v){
    for(int i = (v.size()-1)/2; i>=1;i--){
        heapify(i, v.size(), v);
    }
    //max heap created...
    int idx = v.size()-1;
    while(idx!=1){
        swap(v[1], v[idx]);
        idx--;
        heapify(1, idx+1, v);
    }
}
int main(){
    vector<int> v;
    v.push_back(-1);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    heapSort(v);
    vector<int>::iterator it = v.begin();
    it++;
    for(;it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}