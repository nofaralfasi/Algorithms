#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include <math.h>

/*An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once*/
int CountSemiSimilar(char a[][M], char b[][M], int n)
{
   int i, j, pairs = 0;
   int n1 = 0;
   int n2 = 0;
   char temp;
   int bbreak = 1;

   for (int row = 0; row < n; row++)
   {
      n1 = strlen(a[row]);
      n2 = strlen(b[row]);

      // If both strings are of different length, then they are not anagrams
      if (n1 != n2)
      {
         printf("%s and %s are not SemiSimilar! \n", a[row], b[row]);
      }
      else
      {
         // sorts both strings first
         for (i = 0; i < n1 - 1; i++)
         {
            for (j = i + 1; j < n1; j++)
            {
               if (a[row][i] > a[row][j])
               {
                  temp = a[row][i];
                  a[row][i] = a[row][j];
                  a[row][j] = temp;
               }
               if (b[row][i] > b[row][j])
               {
                  temp = b[row][i];
                  b[row][i] = b[row][j];
                  b[row][j] = temp;
               }
            }
         }

         // Compare both strings character by character

         for (i = 0; i < n1 && bbreak == 1; i++)
         {
            if (a[row][i] != b[row][i])
            {
               printf("%s and %s are not SemiSimilar! \n", a[row], b[row]);
               bbreak = 0;
            }
         }
         bbreak = 1;
         if (i == n1)
         {
            pairs++;
            printf("%s and %s are SemiSimilar! \n", a[row], b[row]);
         }

         // printf("row is: %d. Number of pairs: %d\n", row, pairs);
      }
   }
   return pairs;
}

int main(void)
{
   char na[M][M] = {"abcdrrefg", "geffeg", "ddd", "abcd"};
   char nb[M][M] = {"bercadrfg", "gefegf", "dddd", "abcde"};
   int anagram = CountSemiSimilar(na, nb, 4);
   printf("\nNumber of pairs: %d\n", anagram);
   return 0;
}