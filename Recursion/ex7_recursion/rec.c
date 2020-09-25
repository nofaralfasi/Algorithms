#include "rec.h"

/*helper*/
int numOfDigits(int num)
{
	int res = 0;
	while (num > 0)
	{
		num = num / 10;
		res++;
	}
	return res;
}

//---------------------------1--------------------------
long ReverseNum(unsigned long n)
{
	int base = 1;
	while (n / (base * 10))
	{
		base *= 10;
	}
	if (n <= 9)
		return n;
	else if (n >= 10)
	{
		int rev = (n % 10) * base;
		return ReverseNum(n / 10) + rev;
	}
}
//---------------------------2--------------------------
int isSubsetSum(int a[], int size, int k)
{
	/******** DON'T CHANGE ********/
	fx2(); // do not change!!!
	/******************************/

	if (k == 0)
		return 1;
	if (size == 0 && k != 0)
		return 0;

	return isSubsetSum(a, size - 1, k) || isSubsetSum(a, size - 1, k - a[size - 1]);
}
//---------------------------3--------------------------
int lastN(int num, int n)
{
	/******** DON'T CHANGE ********/
	fx3(); // do not change!!!
	/******************************/

	if (numOfDigits(num) < n)
		return -1;
	else if (n == 0)
		return n;
	else
	{
		return num % 10 + lastN(num / 10, --n) * 10;
	}
}
//---------------------------4--------------------------
void swap(int mat[][N], int row, int col)
{
	int tmp = mat[row][col];
	mat[row][col] = mat[col][row];
	mat[col][row] = tmp;
}
void ChangeFrame(int mat[][N], int rowCol, int size)
{
	/******** DON'T CHANGE ********/
	fx4(); // do not change!!!
	/******************************/
	if (rowCol > size - 1 || size <= 0)
		return;
	swap(mat, rowCol, size - 1);
	ChangeFrame(mat, rowCol, size - 1);
	rowCol += 1;
	ChangeFrame(mat, rowCol, size);
	ChangeFrame(mat, rowCol, size - 1);
}

//---------------------------5--------------------------
int concatFirst(int num, int start)
{
	/******** DON'T CHANGE ********/
	fx5(); // do not change!!!
	/******************************/

	if (num > 0)
	{
		start = concatFirst(num / 10, start * 10);
	}
	return start - num / 10 + num;
}
//---------------------------6--------------------------
int MergeNumbers(int n1, int n2)
{
	/******** DON'T CHANGE ********/
	fx6(); // do not change!!!
	/******************************/

	if (n1 == 0 && n2 == 0)
		return 0;
	if (n1 == 0)
		return (n2 % 10) + MergeNumbers(0, n2 / 10) * 10;
	if (n2 == 0)
		return n1 % 10 + MergeNumbers(n1 / 10, 0) * 10;
	return n1 % 10 + (n2 % 10) * 10 + MergeNumbers(n1 / 10, n2 / 10) * 100;
}
//---------------------------7--------------------------
int Series(int n)
{
	/******** DON'T CHANGE ********/
	fx7(); // do not change!!!
	/******************************/
	if (n < 4)
		return n;
	if (n % 2 == 0)
	{
		return Series(n - 1) + Series(n - 2) + Series(n - 3);
	}
	else
	{
		return Series(n - 1) - Series(n - 3);
	}
}
//---------------------------8--------------------------
void FindCommonDigit(unsigned long n1, unsigned long n2, int arr[], int *sumCommon)
{
	/******** DON'T CHANGE ********/
	fx8(); // do not change!!!
	/******************************/

	if (n1 == 0 || n2 == 0)
	{
		return;
	}
	else if (n1 % 10 == n2 % 10)
	{
		if (*sumCommon != 0 && arr[(*sumCommon) - 1] == n1 % 10)
		{
			return FindCommonDigit(n1 / 10, n2 / 10, arr, sumCommon);
		}
		arr[*sumCommon] = n1 % 10;
		*sumCommon = (*sumCommon) + 1;
		return FindCommonDigit(n1 / 10, n2 / 10, arr, sumCommon);
	}
	else if (n1 % 10 < n2 % 10)
	{
		return FindCommonDigit(n1, n2 / 10, arr, sumCommon);
	}
	else
	{
		return FindCommonDigit(n1 / 10, n2, arr, sumCommon);
	}
}
