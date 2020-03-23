#include <stdio.h>
#include <math.h>

// A utility function to print an array of size size
void printArray(int arr[], int size)
{
   int i;
   for (i = 0; i < size; i++)
      printf("%d ", arr[i]);
   printf("\n");
}

/*Sends all duplicates numbers to the end of the array*/
int RemoveDuplicates(int arr[], int size)
{
   int i, j, k, diff = size;
   for (i = 0; i < diff; i++)
   {
      for (j = i + 1; j < diff; j++)
      {
         if (arr[i] == arr[j])
         {
            for (k = j; k < diff; k++)
            {
               arr[k] = arr[k + 1];
            }
            diff--;
            arr[diff] = arr[i];
         }
      } // for middle
   } // for top
   return diff;
}

int main()
{
   // arr = 1, 2, 1, 4, 4, 3, 5, 2, 1
   // size = 9

   // arr = 1, 2, 4, 3, 5, x, x, x, x
   // size = 5

   int arr[] = {1, 2, 1, 4, 4, 3, 5, 2, 1};
   int size = sizeof(arr) / sizeof(arr[0]);
   printf("Before: ");
   printArray(arr, size);

   int res = RemoveDuplicates(arr, size);
   printf("After:  ");
   printArray(arr, size);
   printf("\nNumber of different numbers: %d\n", res);

   return 0;
}
