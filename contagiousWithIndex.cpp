#include<iostream>
using namespace std;
void enterVal(int arr[], int size);
int maxContArray(int arr[], int size, int& low, int& high);
void printArray(int arr[], int low , int high);

int main()
{
    int n,low=0,end=0;
    cout << "Enter the size of the array: \n";
    cin >> n;
    int arr[n];
    cout << "Enter the values to the array: \n";
    enterVal(arr,n);
    cout << "In the array: \n";
    printArray(arr,0,n-1);
    cout << endl << "The maximum sum of the contagious array is " << maxContArray(arr,n,low,end) << endl;
    cout << "The contagious array is: \n";
    printArray(arr,low,end);
}

void enterVal(int arr[], int size){
    for(int i=0; i < size; i++){
        cin >> arr[i];
    }
}


int maxContArray(int arr[], int size, int& low, int& high){
    int maxval=0,carry;
    for(int i=0; i < size;i++){
        carry=arr[i];
         if(maxval <= carry){
                maxval=carry;
                low=i;
                high=i;
         }
        for(int j=i+1; j < size; j++){
            carry += arr[j];
            if(maxval <= carry){
                maxval=carry;
                low=i;
                high=j;
            }
        }
    }
    return maxval;
}

void printArray(int arr[], int low , int high){
    for(int i=low; i <= high; i++){
        cout << arr[i] << " ";
    }
}