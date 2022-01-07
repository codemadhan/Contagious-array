#include<iostream>
using namespace std;
void enter(int arr[], int n);
void print(int arr[], int n);
int maximum(int* arr,int a);
int maxOfContagiousArray(int arr[], int size);
int main(){
    int n;
    int low,high;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    enter(arr,n);
    int value=maxOfContagiousArray(arr,n);
    cout << "In the array: ";
    print(arr,n);
    cout << endl << "The sum of the maximum contagious array is " << value << endl;
   
    return 0;
}


void enter(int arr[], int n){
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
}


void print(int arr[], int n){
    for(int i=0; i < n; i++){
        cout << arr[i] << " ";
    }
}


int maximum(int* arr,int a){
    int max = arr[0];
    for(int i=1; i<a; i++){
        if(arr[i] > max){
            max=arr[i];
           
        }
    }
    return max;
}

int maxOfContagiousArray(int arr[], int size){
    int* ptr = new int[size];
    int max=arr[0];
    int val;
    ptr[0]=0;
    for(int i=1; i < size; i++){
        if(max + arr[i] <= arr[i]){
            max = arr[i];
            
        }
        else{
            max += arr[i];
        }
        ptr[i]=max;
    }
    val = maximum(ptr,size);
    delete[] ptr;
    ptr=nullptr;
    return val;
    

}