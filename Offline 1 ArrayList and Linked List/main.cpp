#include <iostream>
#include <fstream>
//#include "LinkedList.cpp"
#include "Array.cpp"

using namespace std;



int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("list_output.txt","w",stdout);
    in.open("list_input.txt");

    if(in.eof())
    {
        cout << "Error! Empty file." << endl;
        return -1;
    }



    int X,Y,item;
    in >> X >> Y;
    MyList <int> m(Y);



    for(int i=0; i<X; i++)
    {
        in >> item;
        m.pushBack(item);
    }

    m.print();

    int num;
    in >> num;

    int command, param,ret_val;

    for(int i=0; i<num; i++)
    {
        in >> command >> param ;

        switch(command)
        {
        case 1:

            ret_val = m.size();
            break;
        case 2:

            ret_val= -1;
            m.push(param);
            break;
        case 3:
            ret_val= -1;
            m.pushBack(param);
            break;
        case 4:

            ret_val= -1;
            ret_val = m.erase();
            break;
        case 5:

            ret_val= -1;
            m.setToBegin();
            break;
        case 6:
            ret_val= -1;
            m.setToEnd();
            break;
        case 7:
            ret_val= -1;
            m.prev();
            break;
        case 8:
            ret_val= -1;
            m.next();
            break;
        case 9:
            ret_val= -1;
            ret_val = m.currPos();
            break;
        case 10:
            ret_val= -1;
            m.setToPos(param);
            break;
        case 11:
            ret_val= m.getValue();
            break;
        case 12:
            ret_val = m.find(param);
            break;
        case 13:
            ret_val= -1;
            m.clear();
            break;
        }

        m.print();
        cout << ret_val << endl;

    }
}
