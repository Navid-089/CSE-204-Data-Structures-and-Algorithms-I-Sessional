#include "MinHeap.cpp"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("output.txt","w",stdout);
    in.open("input.txt");

    MinHeap h1(5);

    while(!(in.eof()))
    {
        string str;
        in >> str;
        int num1,num2;

        if(str == "INS" || str == "ins")
        {
            in >> num1;
            h1.Insert(num1);
        }

        else if(str == "PRI" || str == "pri")
        {
            h1.Print();
        }

        else if(str == "DEC" || str == "dec")
        {
            in >> num1 >> num2;
            h1.DecreaseKey(num1,num2);
        }

        else if(str == "FIN" || str == "fin" )
        {
            int num3 = h1.FindMin();
            cout << "FindMin returned " << num3 << endl;
        }
        else if(str == "EXT" || str == "ext")
        {
            int num3 = h1.ExtractMin();
            cout << "ExtractMin returned " << num3 << endl;
        }

    }

}
