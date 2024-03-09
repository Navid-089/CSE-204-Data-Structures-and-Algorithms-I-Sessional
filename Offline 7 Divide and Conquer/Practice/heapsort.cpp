#include <iostream>
using namespace std;

void heapify(int *arr, int n, int i)
{
    int left_child = 2*i+1;
    int right_child = 2*i+2;
    int smallest = i ;

    if(left_child < n && arr[left_child] > arr[smallest])
        smallest = left_child;

   if(right_child < n && arr[right_child] > arr[smallest])
        smallest = right_child;

    if(smallest!=i)
    {

        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}

void heapsort(int *arr, int n)
{
    for(int i = (n/2) - 1; i>=0; i--)
        heapify(arr,n,i);

    for(int i  = 0 ; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    for(int i = n-1; i>=0 ; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int arr[10]= {10,9,8,7,6,5,3,2,1,4};
    heapsort(arr,10);
    for(int i = 0 ; i<10; i++)
        cout << arr[i] << " ";
}
