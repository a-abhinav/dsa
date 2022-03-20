#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
    
    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size++;
        int index =size;
        arr[index]=val;
        while(index>1){
            int parent =index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deletefromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1]=arr[size]; //last element to first position
        size--;

        int i=1;
        while(i<size){
            int leftIndex=2*1;
            int rightIndex=2*i+1;

            if(leftIndex<size && arr[leftIndex]>arr[i]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }else if(rightIndex<size && arr[rightIndex]>arr[i]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }else{
                return;
            }
        }
    }
};

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}

void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromHeap();
    h.print();

    int arr[6]={-1,54,53,55,53,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"using priority queue"<<endl;
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    //min heap
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(4);

    return 0;
}