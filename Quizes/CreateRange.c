
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* CreateRange(int start, int end, int jump, int *sizeRage)
{
	int i, *arr, tmp = 0;
	tmp = ((end - start) / jump) + 1;
	*(sizeRage) = tmp;
	arr = (int *)malloc(tmp * sizeof(int));
	if (arr == NULL)
	{
		printf("Not enough memory\n");
		return NULL;
	}
	for (i = 0; i < tmp; i++)
	{
		arr[i] = (i * jump) + start;
	}
	return arr;
}

int main() {   
   int size;
   int* tempResult = CreateRange(-1, 10, 3, &size);

   printf("Your Output is:\n{ ");
   for (int i = 0; i < size; i++)
	{
      printf("%d  ", tempResult[i]);
	}
   printf("}");

	return 0;
	system("pause");
}