#include <iostream>
using namespace std;

int count = 0 ;

int fibonacci(int n)
{
    count ++ ;
    if(n==1 || n == 2)

        return 1;
    else

        return fibonacci(n-1) + fibonacci(n-2);
}


int main()
{

        cout << fibonacci(50) << endl;
    cout << endl << count ;
}
