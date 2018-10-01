#include <unistd.h>

#include <sys/types.h>
#include <stdio.h>

int
main()
{
	pid_t pid;
	char *argv[3];
	extern char **environ;

	if((pid = fork()) < 0 ) {
		perror("fork");
		return 1;
	} if(pid==0) {
		argv[0] = "echo";
		argv[1] = "Hello, from child";
		argv[2] = NULL;
		execlp("echo", "echo", "Hello", NULL);
		_exit(1);
	}
	write(1, "Hello, from parent\n", 19);
	return 0;
}

