#include "types.h"
#include "stat.h"
#include "user.h"

int
main()
{
	char str[50];
	printf(1, ">>> Write some value, I will save it in kernel space:\n");
	printf(1, ">>>...");
	scanf(0, "%s", &str);
	sd(str);
	exit();

}
