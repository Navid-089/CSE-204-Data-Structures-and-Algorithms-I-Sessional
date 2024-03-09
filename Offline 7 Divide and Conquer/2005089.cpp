#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
vector <int> inversions;

//// Function to merge two sorted arrays and count the number of inversions
int Merge(int *arr, int *temp, int left, int mid_pos, int right)
{
    int m_count = 0 ;
    int i = left;                   // dividing it into two sub arrays to compare
    int j = mid_pos;
    int k  = i;

    while((i <= mid_pos-1) && (j <= right))
    {
        if(arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
            m_count = m_count + (mid_pos-i);        // as it's a sorted array, all of the items to the right of the left sub-array should be pushbacked

            for(int it = i ; it<mid_pos ; it++)
            {
                inversions.push_back(arr[it]);
                inversions.push_back(arr[j-1]);
            }
        }
        else
            temp[k++]  = arr[i++];
    }

    while(j <= right)
        temp[k++] = arr[j++];               // include the remaining elements of the right sub-array

    while( i <= mid_pos-1)
        temp[k++] = arr[i++];               // include the remaining elements of the left sub-array

    for(int i = left; i<=right; i++)
        arr[i] = temp[i];                   // have the sorted array

    return m_count;
}

// Function to basically divide and add the counts of the fragments
int MergeSort(int *arr, int *temp, int left, int right)
{
    int count = 0 ;
    int avg_pos = (left+right)/2;

    if(right <= left)
        count +=0;

    if(right - left > 0 )                           // while it's not a single element array
    {
                                      // count = rA+rB+r; r -> taught in the class
        count += MergeSort(arr,temp,left,avg_pos);          // count from the left sub-array
        count += MergeSort(arr,temp,avg_pos+1,right);       // count from the right sub-array  (basically dividing)
        count += Merge(arr,temp,left,avg_pos+1,right);      // count the inversions         (Conquering)
    }


    return count;
}


int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("output.txt","w",stdout);
    in.open("input.txt");

    int num;
    int tmp_num;

    in >> num;
    int arr[num],tmp_array[num];
    for(int i =  0 ; i < num ; i++)
    {
        in >> tmp_num;
        arr[i] = tmp_num;
    }

//
//cout << "size is " << num << endl;
//
//
//    for(int i = 0 ; i< num; i++)
//        cout << arr[i] << " ";
//    cout << endl;
    cout << MergeSort(arr,tmp_array,0,num-1) << endl;

    cout << "The inverted pairs are:" << endl;

    for(int i = 0 ; i<inversions.size(); i=i+2)
        cout << "(" << inversions[i] << "," << inversions[i+1] <<")" << endl;

}
