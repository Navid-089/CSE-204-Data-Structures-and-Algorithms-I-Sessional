#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the `k` closest elements to `target` in a sorted integer vector `input`
vector<int> findKClosestElements(vector<int> const &input, int target, int k)
{
    // find the insertion point using the binary search algorithm
    int i = lower_bound(input.begin(), input.end(), target) - input.begin();


    int left = i - 1;
    int right = i;

    // run `k` times
    while (k-- > 0)
    {
        // compare the elements on both sides of the insertion point `i`
        // to get the first `k` closest elements

        if (left < 0 || (right < input.size() &&
                abs(input[left] - target) > abs(input[right] - target))) {
            right++;
        }
        else {
            left--;
        }
    }

    // return `k` closest elements
    return vector<int>(input.begin() + left + 1, input.begin() + right);
}

int main()
{
    vector<int> input = { 10, 12, 15, 17, 18, 20, 25 };
    int target = 16, k = 4;

    vector<int> result = findKClosestElements(input, target, k);
    for (int i: result) {
        cout << i << " ";
    }

    return 0;
}
