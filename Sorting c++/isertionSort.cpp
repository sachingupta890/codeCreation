#include<iostream>
using namespace std;
int main(){

    int arr[] = {1,4,3,1,2,3,4,5,6,7,8,26,31};
    int n = 13;

    for(int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }

    cout<<"priting the array"<<endl;

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}

