#include<iostream>
using namespace std;
int main(){
    int arr[0],n,i,max,min;
    cout<<"Enter the size for the array:";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    max = arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    min = arr[0];
    for(int i=0;i<n;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    cout<< "Largest element:"<<max <<endl;
    cout<<"Smallest element:"<<min;
    return 0;
}
