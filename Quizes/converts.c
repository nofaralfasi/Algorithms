#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fromIntToChar(int num, char* str)
{
   int i, counter, tmp;
   tmp=num;
   counter=1;
   while(tmp/10 != 0)
   {
      counter++;
      tmp/=10;
   }

   if(num<0)
   {
      counter++;
   }
  
  str=(char*)malloc((counter+1)*sizeof(char));
   if (str == NULL) {
      free(str);
      printf("Error allocating memory!\n");
      return;
      }

  str[counter]='\0';
  
  tmp=num;
  for(i=1; i<=counter; i++)
  {
     str[counter-i] = tmp%10;
     tmp/10;
  }

  if(num<0)
  {
     str[0]='-';
  }

}

int main()
{
   int num=7392;
   char* str;

   fromIntToChar(num, str);

	printf("Num as int: %d\n", num);
   printf("Num as string: %s\n", str);

   free(str);
	return 0;
   
   system("pause");
}
