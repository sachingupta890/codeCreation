#include<iostream>
using namespace std;
int main(){


    int arr[] = {2,4,1,7,3};
    int n = 5;

    // 1 indexing based


   // sorting in ascending order 

    for(int i = 0; i<n-1; i++){
        int minIndex = i;
        for(int j = i+1 ; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }


    //sorting in descending order

    // for(int i = n-1; i>0; i--){
    //     int minIndex = i;
    //     for(int j = i-1; j>=0; j--){
    //         if(arr[j] < arr[minIndex]){
    //             minIndex = j;
    //         }
    //     }
    //     swap(arr[minIndex],arr[i]);
    // }

    // cout<<"printing the array"<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}