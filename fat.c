#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main()
{
	pid_t pid;
    int pip[2];
    pipe(pip);

	pid = fork();

	if (pid == 0) { /* child process */
		printf("Entrei no filho!\n");
		value += 15;
		printf ("CHILD: value = %d\n",value); /* LINE A */
        write(pip[1], &value, 20);
		return 0;
	}
	else if (pid > 0) { /* parent process */
		wait(NULL);
        read(pip[0], &value, 20);
        value += 5;
		printf ("PARENT: value = %d\n",value); /* LINE A */
		return 0;
	}
}