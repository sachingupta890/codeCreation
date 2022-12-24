#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
    int largest = i;

    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
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

    // Heap h;
    // h.insert(55);
    // h.insert(53);
    // h.insert(45);
    // h.insert(64);

    // h.insert(61);
    // h.print();

    // h.deleteFromHeap();
    // h.print();


   int arr1[] = {76,57,81,74,83};
   //int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i = n/2-1; i>=0; i--){
        heapify(arr1,n,i);
    }
    cout<<"printing the array now "<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    
   int arr2[] = {36,47,29,24,21};
   //int arr[6] = {-1,54,53,55,52,50};
    int m = 5;

    for(int i = m/2-1; i>=0; i--){
        heapify(arr2,m,i);
    }
    cout<<"printing the array now "<<endl;
    for(int i = 0; i<m; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    // HeapSort(arr,n);

    // cout<<"printing the Sorted array "<<endl;
    // for(int i = 1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    int arr3[n+m];
    int k = 0;
    for(int i = 0; i<n; i++){
        arr3[k++] = arr1[i];
    }

    for(int i = 0; i<m; i++){
        arr3[k++] = arr2[i];
    }
    int size = n+m;
    //heapify merged array
    for(int i = size/2-1; i>=0; i--){
        heapify(arr3,size,i);
    }

    cout<<"printing the arr3 "<<endl;
    for(int i = 0; i<n+m; i++){
        cout<<arr3[i]<<" ";
    }


    return 0;
}