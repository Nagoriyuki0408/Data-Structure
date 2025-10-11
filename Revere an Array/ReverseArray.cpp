#include<iostream>
using namespace std;
int main(){
    int arr[100],tot,i,j,temp;
    cout<<"Enter the size for Array:";
    cin>>tot;
    for(int i=0; i<tot; i++){
        cin>>arr[i];
    }
    cout<<"\nThe Original Array is:\n";
    for(int i=0; i<tot; i++){
        cout<<arr[i]<<" ";
    }
    j = tot -1;
    for(int i=0; i<j; i++, j--){
        temp =arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    cout<<"\n\nThe Reverse of Given Array is:\n";
    for(int i=0; i<tot; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;ReverseArray
}
