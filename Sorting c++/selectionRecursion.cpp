#include<iostream>
using namespace std;
void selectionSort(int arr[],int i,int n){
    cout<<i<<" "<<n<<endl;
    if(i==n-1){
        return;
    }
    int minIndex = i;
    for(int j = i+1; j<=n; j++){
        if(arr[minIndex] > arr[j]){
            minIndex = j;
        }
    }
    swap(arr[i],arr[minIndex]);
    i = i+1;
    selectionSort(arr,i,n);
}
int main(){

    int arr[] = {3,2,4,5,1};
    int n  = 5;
    int i = 1;
    selectionSort(arr,i,n);

    cout<<"printing the array"<<endl;

    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
}