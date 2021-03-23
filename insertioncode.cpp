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
    return 0;
}