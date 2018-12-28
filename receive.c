#include "types.h"
#include "stat.h"
#include "user.h"

int
main()
{
	int iter;
	char result[20];
	iter = rec_num();

	for (int j = 0; j < iter; j++)
	{
		result[j] = rec(j);
		//printf(1, "****** %c\n", rec(j));
	}
	//printf(1, ">>>>num: %d\n", rec_num());

	printf(1, ">>> The value saved in kernel is: %s\n", result);
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
