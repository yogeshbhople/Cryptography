#include<stdio.h>
#include<conio.h>

char * encrypt(char str[])
{
	char ct[100];
   int i;
   for(i=0;str[i]!='\0';i++)
   {
   	if(str[i]>=97 && str[i]<=122)
      	ct[i]=(char)((int)(str[i]-97+3)%26+97);
      if( str[i]>=65 && str[i]<=90)
      	ct[i]=(char)((int)(str[i]-65+3)%26+65);
   }
   ct[i]='\0';
   printf("%s",ct);
   return(ct);
}


void main()
{
    char pt[100],ct[100];
    printf("Enter the plaintext=");
    scanf("%s",pt);
    ct=encrypt(pt);
    printf("%s",ct);
    getch();

}
