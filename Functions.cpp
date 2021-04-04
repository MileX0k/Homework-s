
#include <iostream>

using namespace std;

namespace MyLib
{
	int PoNeNe(float arr[], int size)
	{
		int positive = 0, negative = 0, neutral = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] < 0)
			{
				negative++;
			}
			else
			{
				if (arr[i] == 0)
				{
					neutral++;
				}
				else positive++;
			}
		}
		cout << "Positive results: " << positive << endl;
		cout << "Negative results: " << negative << endl;
		cout << "Neutral results: " << neutral << endl;
		return 0;
	}


	int PrintArray(float arr[], int size)
	{
		cout << "Your array: ";
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		PoNeNe(arr, size);
		return 0;
	}

	float FunctionArray()
	{
		int const size = 10;
		float Numbers[size] = { 10, -10, 53, -90, 123, 187.4, -72.5, 43.1, 0, -666 };
		PrintArray(Numbers, size);
		return 0;

	}

}
