#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int k = 3;

    //approach 1

    // vector<int> sumArray;

    // for(int i = 0; i<n; i++){
    //     int sum = 0;
    //     for(int j = i; j<n; j++){
    //         sum += arr[j];
    //         cout<<sum<<endl;
    //         sumArray.push_back(sum);
    //     }
    // }

    // sort(sumArray.begin(),sumArray.end());

    // cout<<"kth largest sum is "<<sumArray[sumArray.size()-k]<<endl;

    //Approach 2 

    priority_queue<int,vector<int>,greater<int> > pq;

    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            if(pq.size() < k){
                pq.push(sum);
            }
            else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    cout<<"kth largest sum subArray is "<<pq.top()<<endl;
}