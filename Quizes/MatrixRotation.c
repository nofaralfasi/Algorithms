#include <stdio.h>
#define MATRIX_SIZE 4
#define M 20

void FlipMatrix(int mat[MATRIX_SIZE][MATRIX_SIZE], int option)
{
   int i, j, temp;

   switch (option)
   {
   case 1:
      for (i = 0; i < MATRIX_SIZE / 2; i++)
      {
         for (j = i; j < MATRIX_SIZE - i - 1; j++)
         {
            temp = mat[i][j];
            mat[i][j] = mat[MATRIX_SIZE - j - 1][i];
            mat[MATRIX_SIZE - j - 1][i] = mat[MATRIX_SIZE - i - 1][MATRIX_SIZE - j - 1];
            mat[MATRIX_SIZE - i - 1][MATRIX_SIZE - j - 1] = mat[j][MATRIX_SIZE - i - 1];
            mat[j][MATRIX_SIZE - i - 1] = temp;
         }
      }
      break;
   case 2:
      for (i = 0; i < MATRIX_SIZE / 2; i++)
      {
         for (j = i; j < MATRIX_SIZE - i - 1; j++)
         {
            temp = mat[i][j];
            mat[i][j] = mat[j][MATRIX_SIZE - i - 1];
            mat[j][MATRIX_SIZE - i - 1] = mat[MATRIX_SIZE - i - 1][MATRIX_SIZE - j - 1];
            mat[MATRIX_SIZE - i - 1][MATRIX_SIZE - j - 1] = mat[MATRIX_SIZE - j - 1][i];
            mat[MATRIX_SIZE - j - 1][i] = temp;
         }
      }
      break;
   case 3:
      for (i = 0; i < MATRIX_SIZE / 2; i++)
      {
         for (j = 0; j < MATRIX_SIZE; j++)
         {
            temp = mat[i][j];
            mat[i][j] = mat[MATRIX_SIZE - i - 1][j];
            mat[MATRIX_SIZE - i - 1][j] = temp;
         }
      }
      break;
   case 4:
      for (i = 0; i < MATRIX_SIZE; i++)
      {
         for (j = 0; j < MATRIX_SIZE / 2; j++)
         {
            temp = mat[i][j];
            mat[i][j] = mat[i][MATRIX_SIZE - j - 1];
            mat[i][MATRIX_SIZE - j - 1] = temp;
         }
      }
   }
}

void printMat(int mat[MATRIX_SIZE][MATRIX_SIZE])
{
   int i, j;
   for (i = 0; i < MATRIX_SIZE; i++)
   {
      for (j = 0; j < MATRIX_SIZE; j++)
      {
         printf("%d\t", mat[i][j]);
      }
      printf("\n"); /*new line after row elements*/
   }
   printf("\n");
}

int main(void)
{
   int mat1[MATRIX_SIZE][MATRIX_SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

   printf("\nThe matrix before the flip:\n");
   printMat(mat1);

   FlipMatrix(mat1, 2);

   printf("The matrix after the flip:\n");
   printMat(mat1);

   return 0;
}