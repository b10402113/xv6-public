#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int i;
  char str[50];

  for(i = 1; i < argc; i++)
    printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");

  printf(1,"uuuuuu%d\n",getyear());
  //============================================
  scanf(0, "%s", &str);
  //char *ss = str;
  sd(str);
  int iter;
  char result[20];
  iter = rec_num();
  
  
  for (int j = 0; j < iter; j++)
  {
	  result[j] = rec(j);
	  printf(1, "****** %c\n", rec(j));
  }
  printf(1, ">>>>num: %d\n", rec_num());
 
  printf(1, "result>>>> %s\n", result);
  /*
  for (int i = 0; str[i] != '\0'; i++)
  {
	  sd(str[i]);
  }*/
/*
  printf(1, "======= %s\n", str);
  sd('o');
  printf(1, "======= %s\n",rec());
  */
  exit();
}
