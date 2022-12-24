#include<bits/stdc++.h>
using namespace std;

int main(){

    //create min heap
    priority_queue<int,vector<int>,greater<int> > pq;

    int arr[] = {4,3,2,6};

    int n = 4;

    //push array element into heap
    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
    }

    int cost = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a+b;
        cost += sum;
        pq.push(sum);
    }

    cout<<"minumum cost to connect the given ropes is "<<cost<<endl;
}