#include<iostream>
#include<vector>
using namespace std;

int partitionDeterministic(vector<int>&arr, int low, int high){
    int pivot = arr[high]; //Choosing last element as pivot
    int i = low-1;

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void deterministicQS(vector<int>&arr, int low, int high){
    if(low < high){
        int pivot = partitionDeterministic(arr, low, high);
        deterministicQS(arr, low, pivot-1);
        deterministicQS(arr, pivot+1, high);
    }
}

int partitionRandomized(vector<int>&arr, int low, int high){
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]); //Move random pivot to end
    return partitionDeterministic(arr, low, high); //Reuse deterministic partitioningß
}

void randomizedQS(vector<int>&arr, int low, int high){
    if(low < high){
        int pivot = partitionRandomized(arr, low, high);
        randomizedQS(arr, low, pivot-1);
        randomizedQS(arr, pivot+1, high);
    }
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    //Deterministic pivot selection (last element as pivot)
    vector<int> arrD = arr;
    deterministicQS(arrD, 0, arrD.size()-1);

    cout<<"Sorted array using Deterministic QuickSort: ";
    for(int num : arrD)
        cout<<num<<" ";
    cout<<endl;

    //Randomized pivot selection
    vector<int> arrR = arr;
    randomizedQS(arrR, 0, arrR.size()-1);

    cout<<"Sorted array using Randomized QuickSort: ";
    for(int num : arrR)
        cout<<num<<" ";
    cout<<endl;

    return 0;
}