#include<iostream>
using namespace std;
int main(){


    int arr[] = {6,5,4,3,2,1};
    int n = 6;

    for(int i = 1; i<n; i++){
        bool isSwapped = false;
        for(int j = 0; j<n-i; j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j],arr[j+1]);
                isSwapped = true;
            }
        }
        if(isSwapped == false){
            break;
        }
    }

    cout<<"printing the array"<<endl;

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}