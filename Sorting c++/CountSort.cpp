#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[],int n){
    //step 1 find the max element in the array
    int maxi = arr[0];
    for(int i = 0; i<n; i++){
        maxi = max(maxi,arr[i]);
    }

    // create the count array of maxi size 
    int count[10] = {0};

    //fill the count array with the frequency of each index
    for(int i = 0; i<n; i++){
        count[arr[i]]++;
    }


    //update the count array by adding the previous index count 
    for(int i = 1; i<=maxi; i++){
        count[i] += count[i-1];
    }

    int newArray[n]; 
    // traverse the array from last 
    for(int i = n-1; i>=0; i--){
        newArray[--count[arr[i]]] = arr[i];
    }

    //copy to original array
    for(int i = 0; i<n; i++){
        arr[i] = newArray[i];
    }


}

int main(){


    int arr[] = {1,3,2,3,4,1,6,4,3};

    for(int i = 0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    countSort(arr,9);
     for(int i = 0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    return 0; 
}