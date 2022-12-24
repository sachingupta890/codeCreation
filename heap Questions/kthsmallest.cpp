#include<bits\stdc++.h>
using namespace std;
int kthSmallest(int arr[],int n,int k){
    //step 1 create a max heap for starting k elements
    priority_queue<int> pq;

    for(int i = 0; i<k; i++){
        pq.push(arr[i]);
    }

    //step 2 for rest of the element in array compare with the max.top() if smaller element encouter pop and push

    for(int i = k; i<n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){


    int arr[] = {1,2,3,4,5,6};
    int size = 6;
    int k = 5;
    int ans = kthSmallest(arr,size,k);
    cout<<"kth smallest element is "<<ans<<endl;
}