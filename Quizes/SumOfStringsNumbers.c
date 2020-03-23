
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* AddNumbers(char* num1, char* num2)
	{
	char* sum;
	int i, j, maxLen, len1 = strlen(num1), len2 = strlen(num2), tmp = 0, count = 0, carry = 0;

	if (len2 > len1)
		maxLen = len2 + 1;
	else
		maxLen = len1 + 1;
	count = maxLen - 1;
	sum = (char*)malloc((maxLen + 1) * sizeof(char));
	i = len1 - 1;
	j = len2 - 1;
	sum[maxLen] = '\0';

	while (count > 0)
	{
		if (i >= 0 && j >= 0)
			tmp = (num1[i] - '0') + (num2[j] - '0') + carry;
		else if (i >= 0)
			tmp = (num1[i] - '0') + carry;
		else
			tmp = (num2[j] - '0') + carry;

		if (tmp > 9)
		{
			carry = 1;
			tmp -= 10;
			sum[count] = tmp + '0';
		}
		else
		{
			carry = 0;
			sum[count] = tmp + '0';
		}
		count--;
		i--;
		j--;
	}
	if (carry > 0)
		sum[0] = carry + '0';
	else
		sum++;

	return sum;
	}

int main() {
	// "65768796453436" + "686756453446" = "66455552906882"
	char* tempString = AddNumbers("65768796453436", "686756453446");
   printf("The Sum is: %s\n", tempString);

	return 0;
	system("pause");
}
