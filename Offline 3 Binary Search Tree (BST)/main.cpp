#include <iostream>
#include <fstream>
#include "bst.cpp"
using namespace std;

int main()
{


    FILE *fp;
    ifstream in;
    fp = freopen("output.txt","w",stdout);
    in.open("input.txt");


    int flag = 1;
//    cout << "--- Binary Search Tree ---" << endl;
//    cout << "Press I to insert a value." << endl;
//    cout << "Press F to find if a number exists." << endl;
//    cout << "Press D to delete a number from the BST" << endl;
//    cout << "Press T and its type(In,Pre,Post) to traverse" << endl;
//    cout << "Press X to exit\n" << endl;

    BST <int> b;

    while(!(in.eof()))
    {
        char c;
        int x;
        string str;

        in >> c ;

        if(!(c >= 'A' && c<='Z'))
            break;

        if(c == 'i' || c == 'I')
        {
            in >> x;
            b.insert(x);
            b.print();
        }

        else if(c == 'F' || c == 'f' )
        {
            in >> x;
           if(b.find(x))
            cout << "True" << endl;
           else
            cout << "False" << endl;
        }

        else if(c == 'D' || c == 'd' )
        {
            in >> x;
//            cout << x << endl;
            if(b.Delete(x))
            {
//                cout << "meow" << endl;
                 b.print();
            }

            else
                cout << "Invalid Operation" << endl;
        }

        else if( c == 'T' || c == 't')
        {
            in >> str;
            if(str == "In")
                b.inOrder();
            else if(str == "Pre" )
                b.preOrder();
            else if(str == "Post")
                b.postOrder();

            cout << endl;

        }
    }





    return 0;
}
