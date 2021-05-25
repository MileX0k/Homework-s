#include <iostream>
using namespace std;
#include <random>
#include <math.h>

// Вторая часть ДЗ ==========================================================

double formula(double x)
{
    return sqrt(fabs(x)) + 5 * pow(x, 3);
}

void task2()
{
    const int n = 11;
    double mass[n] = { 0 }, y;

    for (size_t i = 0; i < 11; i++)
    {
        cin >> mass[i];
    }

    for (int i = 0; i < n / 2; i++)
    {
        double tempr = mass[i];
        mass[i] = mass[n - 1 - i];
        mass[n - 1 - i] = tempr;
    }

    for (size_t i = 0; i < 11 ; i++)
    {
        y = formula(mass[i]);
        if (y > 400)
            cout << i << ": " << y << " - Too mach" << endl;
        else cout << i << ": " <<  y << endl;
    }
    cout << endl;
}


// Первая часть ДЗ ==========================================================

void bubbleArray()
{
    const int SIZE = 8;
    int array[SIZE][SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            array[i][j] = rand() % 1000;
        }
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            cout << "  " << array[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;

    for (size_t k = 0; k < (SIZE * SIZE); k++)
    {

        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE - 1; j++)
            {
                if (array[i][j] > array[i][j + 1])
                {
                    int temp = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = temp;
                }
                if (i < SIZE - 1 )
                {
                    if (array[i][j + 1] > array[i + 1][0])
                    {
                        int foo = array[i][j + 1];
                        array[i][j + 1] = array[i + 1][0];
                        array[i + 1][0] = foo;
                    }
                }
            }
        }
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            cout << "  " << array[i][j] << "   ";
        }
        cout << endl;
    }
}
// =======================================================================

int main()
{
    //----TASK 1-------------------

    bubbleArray();

    //----TASK 2-------------------
    
    cout << "Enter your array (11 numbers): " << endl;
    task2();

    return 0;
}