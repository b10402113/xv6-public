#include "types.h"
#include "user.h"
#include "stat.h"


int
main(int argc, char *argv[])
{
	int priority, pid;

	if (argc < 3) {
		printf(2, "Usage: cp pid priority");
		exit();
	}
	pid = atoi(argv[1]);
	priority = atoi(argv[2]);

	printf(1, "pid=%d, priority=%d\n", pid, priority);
	cp(pid, priority);

	exit();
}