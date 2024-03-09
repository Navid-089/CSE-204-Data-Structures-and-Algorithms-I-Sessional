#include <iostream>
using namespace std;

int findmin(int *arr, int size, int left, int right)
{
    if (left == right) {
        return arr[left];
    }

    int mid = (left+right) / 2;
    int min1=0,min2=0;

    if(right> left)
    {
        min1 = findmin(arr,size,left,mid);
        min2 = findmin(arr,size,mid+1,right);
    }

    return min(min1,min2);
}

int main()
{
    int arr[6] = {-11,4,23,6,7,-100};
    cout << findmin(arr,6, 0, 5);
}
