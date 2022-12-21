#include<iostream>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;

    //constructor
    Heap(){
        arr[0] = -1;
        size = 0;
    }
    // max heap
    void insert(int data){
        //step 1 insert the node at last
        size = size + 1;
        arr[size] = data;
        
        int index = size;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap(){
        //step 1 put value of last index to root
        arr[1] = arr[size];

        //delete last element 
        size--;

        //step 3 propogate root to its right position
        int i = 1;
        while(i<size){
            int left = 2*i;
            int right = 2*i+1;

            if(left < size && arr[left] > arr[i]){
                swap(arr[left],arr[i]);
                i = left;
            }
            else if(right < size && arr[right] > arr[i]){
                swap(arr[right],arr[i]);
                i = right;
            }
            else{
                return;
            }
        }

    }
};

void heapify(int arr[],int n,int i){
    int largest = i;

    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    //if value changes then swap it
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }


}

void HeapSort(int arr[],int n){
    int size = n;

    while(size > 1){
        //step 1
        swap(arr[1],arr[size]);

        size--;

        //step 2
        heapify(arr,size,1);
    }
}
int main(){

    Heap h;
    h.insert(55);
    h.insert(53);
    h.insert(45);
    h.insert(64);

    h.insert(61);
    h.print();

    h.deleteFromHeap();
    h.print();


   int arr[6] = {-1,76,57,81,74,83};
   //int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i = n/2; i>0; i--){
        heapify(arr,n,i);
    }
    cout<<"printing the array now "<<endl;
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    HeapSort(arr,n);

    cout<<"printing the Sorted array "<<endl;
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}