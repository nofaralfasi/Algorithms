
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE1 8
#define SIZE2 10
#define SIZE3 4
#define GRD_RANGE1 10
#define GRD_RANGE2 7
#define SIZE_GRADES 20

int **GradeStat(int *Grades, int size_grades, int grd_range, int *count_grd, int *avg_grd)
{
	int i, j, **statMat, rows, *arr_range, curr_sum = 0;
	rows = (101 / grd_range) + 2;
	arr_range = (int *)malloc(rows * sizeof(int));
	if (arr_range == NULL)
	{
		printf("Not enough memory\n");
		return NULL;
	}

	for (i = 0; i < rows; i++)
	{
		arr_range[i] = (i * grd_range) - 1;
	}

	statMat = (int **)malloc(rows * sizeof(int *));
	if (statMat == NULL)
	{
		printf("Can't allocate statMat\n");
		return NULL;
	}

	for (i = 0; i < rows - 1; i++)
	{
		count_grd[i] = 0;
		curr_sum = 0;
		avg_grd[i] = 0;
		statMat[i] = (int *)calloc(1, sizeof(int));
		if (statMat[i] == NULL)
		{
			printf("Can't allocate statMat[i]\n");
			return NULL;
		}
		for (j = 0; j < size_grades; j++)
		{
			if (Grades[j] > arr_range[i] && Grades[j] <= arr_range[i + 1])
			{
				curr_sum += Grades[j];
				statMat[i][count_grd[i]] = Grades[j];
				count_grd[i] += 1;
				statMat[i] = (int *)realloc(statMat[i], (count_grd[i] + 1) * sizeof(int));
			}
		}
		if (count_grd[i] != 0)
		{
			avg_grd[i] = curr_sum / count_grd[i];
		}
	}
	return statMat;
}

void Test5A(int** arr, int size_arr, int* arr_count, int range_ind, int num)
{
	if (arr == NULL)
	{
		printf("Can't allocate arr (-4)\n");
		return;
	}

	for (int i = 0; i < arr_count[range_ind]; i++)
	{
		if (arr[range_ind][i] == num)
			return;
	}
	printf("Can't find %d in index range %d (-4)\n",num,range_ind);
}

void Test5B(int* arr1, int* arr2, int size_arr)
{
	if (arr1 == NULL)
	{
		printf("Can't allocate arr (-4)\n");
		return;
	}

	for (int i = 0; i < size_arr; i++)
	{
		if (arr1[i] != arr2[i])
		{
			printf("Wrong values in avg/count arrays (-4)\n");
			return;
		}
	}
}

int main() {
	int grades[SIZE_GRADES] = {98,45,77,65,89,90,100,43,54,67,55,88,76,67,33,23,45,76,72,76};
	int avg_grd1[(100 / GRD_RANGE1) + 1];
	int avg_grd2[100 / GRD_RANGE2 + 1];
	int count_grd1[(100 / GRD_RANGE1) + 1];
	int count_grd2[100 / GRD_RANGE2 + 1];
	int** arr1 = GradeStat(grades, SIZE_GRADES, GRD_RANGE1, count_grd1, avg_grd1);
	int** arr2 = GradeStat(grades, SIZE_GRADES, GRD_RANGE2, count_grd2, avg_grd2);

	Test5A(arr1, 100 / GRD_RANGE1 + 1, count_grd1, 8, 88);
	Test5A(arr1, 100 / GRD_RANGE1 + 1, count_grd1, 10, 100);
	Test5A(arr2, 100 / GRD_RANGE2 + 1, count_grd2, 11, 77);
	
	int avg_grd1_test[100 / GRD_RANGE1 + 1] = {0,0,23,33,44,54,66,75,88,94,100};
	int count_grd2_test[100 / GRD_RANGE2 + 1] = {0,0,0,1,1,0,3,2,0,3,4,1,3,0,2};

	Test5B(avg_grd1, avg_grd1_test, 100 / GRD_RANGE1 + 1);
	Test5B(count_grd2, count_grd2_test, 100 / GRD_RANGE2 + 1);

	printf("done");
	return 0;

	system("pause");
}
