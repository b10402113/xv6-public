#include "types.h"
#include "user.h"
#include "stat.h"


int
main(int argc, char *argv[])
{
	int pid;

	if (argc < 2) {
		printf(2, "Usage: find pid");
		exit();
	}
	pid = atoi(argv[1]);

	find(pid);
	exit();
}