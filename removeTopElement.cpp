#include<iostream>
#include<vector>
using namespace std;
class Heap{
    int size;
    bool minHeap;
    vector<int> v;
    public:
        Heap(int default_size = 10, bool answer = true){
            size = default_size;
            minHeap = answer;
            v.reserve(size);
            //So as to occupy the zeroth index..
            v.push_back(-1);
        }
        int sizeHeap(){
            return v.size();
        }
        bool compare(int a, int b){
            if(minHeap){
                return a < b;
            }
            return a > b;
        }
        void insert(int d){
            v.push_back(d);
            //Appended the item to the last of the array..
            //Upheapification...
            int idx = v.size()-1;
            //Always returns the floor value...
            int parent = idx/2;
            while(idx > 1 && compare(v[idx], v[parent])){
                swap(v[idx], v[parent]);
                idx = parent;
                parent/=2;
            }
        }
        void heapify(int idx){
            int left = 2*idx;
            int right = left + 1;
            int min_idx = idx;
            if(left < v.size()){
                if(compare(v[left], v[idx])){
                    min_idx = left;
                }
            }
            if(right < v.size()){
                if(compare(v[right], v[min_idx])){
                    min_idx = right;
                }
            }
            if(min_idx!=idx){
                swap(v[idx], v[min_idx]);
                heapify(min_idx);
            }
        }
        //removes min/max element from the heap...
        void pop(){
            //1.) swap the last and the first element so as the tree structure is not destroyed..
            int idx = v.size()-1;
            swap(v[1], v[idx]);
            //2.) delete the min/max element which is at the last from the tree structure...
            v.pop_back();
            //3.) Now, do the heapification..
            heapify(1);
        }
        void print(){
            for(int i=1;i<v.size();i++){
                cout<<v[i]<<" ";
            }
        }
};
int main(){
    //Instantiated the heap class..
    Heap h;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int d; cin>>d;
        h.insert(d);
    }
    h.print();
    cout<<endl;
    //Removes the minimum element..
    h.pop();
    //Printing the heap again...
    h.print();
    return 0;
}