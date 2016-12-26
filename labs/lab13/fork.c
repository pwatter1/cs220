#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	int x = 1;
	pid_t pid;
	pid = fork();

	if(pid == 0){
		x++;
		printf("In child\n");
		printf("Return PID  - %d - Parents PID - %d\n", getpid(), getppid());
		printf("x - %x\n", x);
	}else{
		sleep(1);
		x--;
		printf("In parent\n");
		printf("Parents PID - %d - Childs PID  - %d\n", getppid(), getpid());
		printf("x - %x\n", x);
	}
	return 0;
}
