#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[high];
    int i  = low -1 ;

    for(int j = low; j<= high - 1 ; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }

    }
    swap(&arr[i+1], &arr[high]);

    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr,low,pi-1);
        quickSort(arr, pi+1,high);
    }

}

void printArray(int *arr, int size)
{
    for(int i = 0; i <size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int BinarySearch(int *arr, int n, int num)
{
    int low = 0;
    int high = n-1;
    int mid = (low+high) / 2;
    if(n==1)
        return 0;

    while(low<=high)
    {
        mid = (high+low) / 2 ;
        if(arr[mid] < num)
            low = mid+1;
        else if(arr[mid] > num)
            high = mid-1;
        else if(arr[mid] == num)
            return mid;
    }


    return -1;
}


int main()
{
    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0 , n-1);
    cout << "Sorted array:\n";
    printArray(arr,n);

    cout << " Found at index: " << BinarySearch(arr,n,7);
}
