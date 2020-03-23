#include <stdio.h>
#include <stdlib.h>

char* convertFromIntToChar(int num)
{
   char* str;
   int i, neg=0, counter=1, tmp=num;

   if(num<0)
   {
      neg = 1;
      counter++;
      num = -1*num;
   }

     while(tmp/10 != 0)
   {
      counter++;
      tmp/=10;
   }

  str=(char*)malloc((counter+1)*sizeof(char));

  str[counter]='\0';  
  tmp=num;
  
  for(i=1; i<=counter; i++)
  {
     str[counter-i] =tmp%10+ '0';
     tmp/=10;
  }

  if(neg)
  {
     str[0] = '-';
  }

   return str;
}

int main()
{
   int num = -7392;
   char* str;

   str = convertFromIntToChar(num);

	printf("Num as int: %d\n", num);
   printf("Num as string: %s\n", str);

   free(str);
	return 0;
   
   system("pause");
}
