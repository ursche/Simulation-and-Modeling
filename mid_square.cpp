#include <iostream>
#include <math.h>
#include <stdlib.h>
 
using namespace std;
 
int a[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
int middleSquareNumber(int numb, int dig)
{
    int sqn = numb * numb, next_num = 0;
    int trim = (dig / 2);
    sqn = sqn / a[trim];
    for (int i = 0; i < dig; i++)
    {
        next_num += (sqn % (a[trim])) * (a[i]);
        sqn = sqn / 10;
    }
    return next_num;
}
 
int main(int argc, char **argv)
{
    cout << "Enter the #-digit random numbers you want: ";
    int n;
    cin >> n;
    int start = 1, end = 1;
 
    start = a[n - 1];
    end = a[n];
 
    int number = ((rand()) % (end - start)) + start;
    cout << "The random numbers are:\n" << number << ", ";
    for (int i = 1; i < n; i++)
    {
        number = middleSquareNumber(number, n);
        cout << number << ", ";
    }
    cout << "...";
}