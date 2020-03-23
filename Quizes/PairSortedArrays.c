
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* PairSortedArrays(char a[], char b[])
{
	int i, j;
	int asize = strlen(a);//the size of str1
	int bsize = strlen(b);//the size of str2
	int totalstring = asize + bsize + 1;

	char* result = (char*)malloc(totalstring * sizeof(char));
	if (result == NULL)
	{
		return NULL;
	}

	for (i = 0, j = 0; i < asize && j < bsize;)
	{
		if (a[i] < b[j])
		{
			result[i + j] = a[i];
			i++;
		}
		else
		{
			result[i + j] = b[j];
			j++;
		}
	}

	while (i + j < totalstring)
	{
		if (i == asize)
		{
			result[i + j] = b[j];
			j++;
		}

		if (j == bsize)
		{
			result[i + j] = a[i];
			i++;
		}
	}
	return result;
}

int main() {
   char* tempString = PairSortedArrays("126", "345");
	printf("The Sorted Array is: %s\n", tempString);

	return 0;
	system("pause");
}
