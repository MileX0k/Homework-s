
#include <iostream>
using namespace std;

int main()
{ 
    // Первая часть ДЗ:

    {
        int a, b, sum;
        cout << "Enter your first number = ";
        cin >> a;
        cout << "Enter your second number ";
        cin >> b;
        sum = a + b;
        if (sum >= 10 && sum <= 20)
        {
        cout << "True" << endl;
        }
        else cout << "False" << endl; 
    }
    
    // Вторая часть ДЗ:

    {
        const int a = 14, b = 10;
        if (a == 10 || b == 10 || a + b == 10)
        {
            cout << "True" << endl;
        }
        else cout << "False" << endl;
        
    }
    
    // Третья часть ДЗ:

    {
        int i = 1;
        cout << "Your numbers: ";
        while (i < 50)
        {
            cout << i << " ";
            i += 2;
        } 
        cout << endl;
    }
       
    // Четвертая часть ДЗ: 

    {
        int simple;
        cout << "Enter your number: ";
        cin >> simple;
        int sqrtsimple = simple ^ -2; // Решение случаев с крупными числами (Пример 961 - не простое, т.к. 31 * 31 = 961 и т.д.)
        if (simple > 0)
        {
                if (simple % 2 == 0 && simple != 2)
                {
                    cout << "This number is not simple!" << endl;
                }
                else if (simple % 7 == 0 && simple != 7)
                {
                    cout << "This number is not simple!" << endl;
                }
                else if (simple % 5 == 0 && simple != 5)
                {
                    cout << "This number is not simple!" << endl;
                }
                else if (simple % 3 == 0 && simple != 3)
                {
                    cout << "This number is not simple!" << endl;
                }
                else if (sqrtsimple * sqrtsimple != simple && simple != 1)
                {
                    cout << "This number is not simple!" << endl;
                }
                else
                    cout << "This number is simple!" << endl;

            
        } else cout << "This number is not simple!" << endl;
         
    }
    
    // Пятая часть ДЗ: 

        {
            int year;
            cout << "Enter your year (from 1 to 3000): ";
            cin >> year;
            if (year > 1 && year < 3000)
            {
                if (year % 100 == 0)
                {
                    if (year % 400 == 0)
                    {
                        cout << "True";
                    }
                    else
                    {
                        cout << "False";
                    }
                }
                else if (year % 4 == 0)
                {
                    cout << "True";
                }
                else
                {
                    cout << "Fals";
                }
                cout << endl;

            }
            else
            {
                cout << "Wrong year!";
            }
            
        }
   

    return 0;

}
