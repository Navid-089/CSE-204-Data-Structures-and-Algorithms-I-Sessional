#include <iostream>
#include <vector>
using namespace std;

// Partition routine using the Dutch national flag algorithm
pair<int, int> partition(vector<int> &nums, int start, int end)
{
    int mid = start;
    int pivot = nums[end];

    while (mid <= end)
    {
        if (nums[mid] < pivot)
        {
            swap(nums[start], nums[mid]);
            ++start, ++mid;
        }
        else if (nums[mid] > pivot)
        {
            swap(nums[mid], nums[end]);
            --end;
        }
        else {
            ++mid;
        }
    }

    // nums[start … mid-1] contains all occurrences of a pivot
    return make_pair(start - 1, mid);
}

// 3–way Quicksort routine
void quicksort(vector<int> &nums, int start, int end)
{
    // base condition for 0 or 1 elements
    if (start >= end) {
        return;
    }

    // rearrange elements across pivot using the Dutch national flag algorithm
    pair<int, int> pivot = partition(nums, start, end);

    // recur on the subarray containing elements that are less than the pivot
    quicksort(nums, start, pivot.first);

    // recur on the subarray containing elements that are more than the pivot
    quicksort(nums, pivot.second, end);
}

int main()
{
    vector<int> nums = { 2, 6, 5, 2, 6, 8, 6, 1, 2, 6 };
    int n = nums.size();

    // sort list
    quicksort(nums, 0, n - 1);

    // print the sorted array
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

