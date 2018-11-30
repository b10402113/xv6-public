#include "types.h"
#include "stat.h"
#include "user.h"


#define BUFFER_SIZE 4
int main()
{

 char buffer[BUFFER_SIZE]="    ";
 int in=0,
     out=0;
 int should_run=1;
 char c;
 int i;
 printf(1,">>> buffer only 4 space\n");
 while(should_run)
 {
  
  printf(1,">>> p: producer\n");
  printf(1,">>> c: consumer\n");
  printf(1,">>> e: exit\n");
  scanf(0,"%c",&c);
  switch(c)
  {
  	case 'p':if((in+1)%BUFFER_SIZE==out)
			printf(1,">>> buffer is full !!\n");
	 	else
		{
			printf(1,">>> creat producer:\n");
			printf(1,">>>>>> please input a value to buffer:\n");
			printf(1,">>>>>>... ");
			scanf(0,"%c",&c);
                	buffer[in]=c;
			//printf(1,">>> in: %d\n", in);
			in=(in+1)%BUFFER_SIZE;
		
		}
		break;
  	case 'c':if(in==out)
			printf(1,">>> buffer is empty !!\n");
	 	else
		{
			printf(1,">>> consumer\n");
                	c=buffer[out];
			buffer[out]=' ';
			//printf(1,">>> out:%d  data: %c\n", out,c);
			printf(1,">>> data: %c\n",c);
			out=(out+1)%BUFFER_SIZE;
		
		}
		break;
  	case 'e':should_run=0;
		printf(1,">>> exit\n");
		exit();break;
  //default: printf(1,"unknow\n");
  }
  printf(1,">>>");
  for(i=0;i<in;i++)
	printf(1,"-----");
  printf(1," in\n");
  printf(1,">>> ----------------\n");
  printf(1,">>> | %c | %c | %c | %c |\n",buffer[0],buffer[1],buffer[2],buffer[3]);
  printf(1,">>> ----------------\n");
  printf(1,">>>");
  for(i=0;i<out;i++)
	printf(1,"-----");
  printf(1," out\n\n");
 }
 
 return 0;
}
