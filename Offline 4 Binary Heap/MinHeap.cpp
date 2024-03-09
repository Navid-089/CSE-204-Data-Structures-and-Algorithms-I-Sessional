#include <iostream>
#include <cmath>
using namespace std;

class MinHeap
{
    int size;
    int *heapArray;
    int capacity;

    int leftChildIndex(int id) {return 2*id+1;}
    int rightChildIndex(int id) {return 2*id+2;}
    int parentIndex(int id) {return floor((id-1)/2);}

    int leftChild(int id) {return heapArray[leftChildIndex(id)];}
    int rightChild(int id) {return heapArray[rightChildIndex(id)];}
    int parent(int id) {return heapArray[parentIndex(id)];}

    bool hasLeftChild(int id) {return leftChildIndex(id) < size;}
    bool hasRightChild(int id) {return rightChildIndex(id) < size;}
    bool hasParent(int id) {return (parentIndex(id) >= 0);}

    void swap(int num1, int num2)
    {
        int temp = heapArray[num1];
        heapArray[num1] = heapArray[num2];
        heapArray[num2] = temp;
    }

     void mem_inc()
    {
        int* temp = new int[capacity];
        for(int i=0; i<capacity; i++)
            temp[i] = heapArray[i];

        delete [] heapArray;

        capacity = capacity*2 ;

        heapArray = new int[capacity];

        for(int i=0; i<capacity; i++)
            heapArray[i] = temp[i];
        delete [] temp;
    }




public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        heapArray = new int[capacity];
    }

    MinHeap()
    {
        this->capacity = 10;
        size = 0;
        heapArray = new int[capacity];
    }

    ~MinHeap()
    {
        delete [] heapArray;
    }

    int FindMin()
    {
        if(size ==  0)
        {
            cout << "The heap is empty." << endl;
            return -1;
        }
        else
            return heapArray[0];
    }

    int ExtractMin()
    {
        if(size ==  0)
        {
            cout << "The heap is empty." << endl;
            return -1;
        }
        else
        {
            int temp = heapArray[0];
            heapArray[0] = heapArray[size-1];
            size -- ;
            heapifyDown();
            return temp;
        }
    }

    void Insert(int key)
    {
        if(size == capacity)
            mem_inc();
        heapArray[size] = key;
        size ++ ;
        heapifyUp(size-1);
        cout << "INSERTED " << key << endl;
    }

    void heapifyUp(int index)
    {
        int id = index;
        while((hasParent(id)) && (parent(id) > heapArray[id]))
        {
            swap(parentIndex(id),id);
            id = parentIndex(id);
        }
    }

    void heapifyDown()
    {
        int id = 0;
        while(hasLeftChild(id) == true)
        {
            int tmp_index = leftChildIndex(id);
            if(hasRightChild(id) && rightChild(id) < leftChild(id))
                tmp_index = rightChildIndex(id);

            if(heapArray[id] < heapArray[tmp_index])
                break;
            else
                swap(id,tmp_index);

            id = tmp_index;

        }
    }

    void Print()
    {
        cout << "Printing the binary heap ..." << endl;
        cout << "- - - - - - - - - - - - - - - - - - - - - -" << endl;
        int flag = 0;
        int level= 0;

      if(size != 0)
         {
            for(int i=0; i<size;i++)
            {
                cout << "Level " << level<< ": ";
                int j = flag;
                while(j <= 2*flag && j<size)
                {
                    cout << heapArray[j] << " ";
                    j++;

                }
                cout << endl;
                flag = flag*2 +1;
                level++;
                if(flag >= size)
                    break;

            }
         }
         else
            cout << "Level 0:" << endl;

        cout << "- - - - - - - - - - - - - - - - - - - - - -" << endl;

    }

    void DecreaseKey(int prevKey, int newKey)
    {
        int found = -1;
        int i;
        for(i = 0; i<size; i++)
        {
            if(heapArray[i] == prevKey)
            {
                heapArray[i] = newKey;
                found = 1;
                break;
            }

        }

        if(found == 1)
        {
            heapifyUp(i);
            cout << prevKey << " decreased to " << newKey << endl;
        }
        else
        {
            cout << "Error! PrevKey not found." << endl;
        }

    }
};


//int main()
//{
//    MinHeap h1(2);
//
//    h1.Insert(7);
//
//    h1.Insert(10);
//
//
//    h1.Insert(5);
//    h1.Print();
//
//    h1.Insert(12);
//    h1.Insert(15);
//    h1.Print();
//
//    h1.DecreaseKey(15,3);
//    h1.Print();
//
//
//    cout << "FindMin returned " << h1.FindMin() << endl;
//    cout << "ExtractMin returned " << h1.ExtractMin() << endl;
//
//    h1.Print();
//
//}

