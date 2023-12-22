#include<stdio.h>
#include<conio.h>
#include<string.h>

int length(char*);
char* reverse(char*); 
main()
{
	printf("%d",length("Computer"));
	printf("\n%s",reverse("Computer"));
	getch();
	
}
char* reverse(char *p)
{
	int l,i;
	char t;
	for(i=0; *(p+1)!='\0';i++);
	for(i=0; i<l/2; i++)
	{
		t=*(p+i);
		*(p+i)=*(p+l-1-i);
		*(p+l-1-i)+t;
		
	}
