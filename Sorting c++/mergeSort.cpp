#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    //now creatin the array 
    int *first = new int[len1];
    int *second = new int[len2];

    //copying the value two the array
    int i= 0;
    for(int index = s; index<=mid; index++){
        first[i++] = arr[index];
    }

    int j = 0;
    for(int index = mid+1; index<=e; index++){
        second[j++] = arr[index];
    }


    //merge two arrays sortedly

    int mainIndex = s;

    int index1 = 0;
    int index2 = 0;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainIndex++] = first[index1++];
        }
        else{
            arr[mainIndex++] = second[index2++];
        }
    }

    while(index1<len1){
        arr[mainIndex++] = first[index1++];
    }

    while(index2<len2){
        arr[mainIndex++] = second[index2++];
    }


    delete []first;
    delete []second;

    

}
void mergeSort(int arr[],int s,int e){
    //base case 
    if(s>=e){
        return;
    }

    int mid = (s+e)/2;
    //recursively call for left part

    mergeSort(arr,s,mid);
    // recursively call for right part
    mergeSort(arr,mid+1,e);


    //now merge
    merge(arr,s,e);

    
}
int main(){

    int arr[] = {1,14,3,42,5};

    int n = 5;

    mergeSort(arr,0,n-1);



    cout<<"printing the sorted array"<<endl;

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}