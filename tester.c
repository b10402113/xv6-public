#define PI 3.14159
#define MAXNUM 8888888.0

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	int k, n, id = 0;
	double x = 0, i, d;

	if (argc < 2)
		n = 1;
	else
		n = atoi(argv[1]);

	if (n < 0 || n > 10)
		n = 2;

	if (argc < 3)
		d = 1.0;
	else
		d = atoi(argv[2]);

	for (k = 0; k < n; k++) {
		id = fork();
		if (id < 0)
			printf(2, "%d failed in fork!\n", getpid());
		else if (id > 0) {
			printf(1, "Parent %d creating child %d\n", getpid(), id);
			wait();
		}
		else {
			for (i = 0; i < MAXNUM; i += d)
				x = x + PI * 141.4;
			break;
		}
	}

	exit();
}