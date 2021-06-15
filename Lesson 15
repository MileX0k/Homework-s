#include <stdio.h>
#include <stdlib.h>

//////////////////////////==TASK 1==//////////////////////////////////////////////////

int hashSum (char* word)
{
	int sum = 0;
	while (*word !=0)
	{
		sum += *word;
		word++;
	}
	return sum;
}

//////////////////////////==TASK 2==//////////////////////////////////////////////////

int calcOptimal(int Nomenal[], int All, int Sum)
{

	int min = 0;
	for (int i = 0; i < All; i++)
	{
		int k = Nomenal[i];
		Sum -= k;
		min++;
		if (k < Sum)
			i--;
	}
	return min;
}


int main()
{
	//////////////////////////==TASK 1==//////////////////////////////////////////////////
	printf("       TASK 1:    \n");
	printf("HiDearTeacher - %d \n", hashSum("HiDearTeacher"));


	//////////////////////////==TASK 2==//////////////////////////////////////////////////

	printf("       TASK 2:    \n");
	int const SUM = 98;
	int const all = 5;
	int nomenal[] = { 50, 10, 5, 2, 1 };
	printf("Minimum number of coins:  %d", calcOptimal(nomenal, all, SUM));
	printf("\n");


	return 0;

}
