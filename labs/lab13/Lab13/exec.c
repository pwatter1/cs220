#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(){
	char *prog = "./runner";
	char *args[] = {"NULL"};

	if(fork() == 0){
		printf("Child PID = %d, parent PID = %d\n", getpid(), getppid());
		execvp(prog, args);
		fprintf(stderr, "exec: %s\n", strerror(errno));
	}else{
		wait(NULL);
	}
	return 0;
}
