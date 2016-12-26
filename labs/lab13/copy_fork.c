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
	
	}else{
		x--;
		printf("In parent\n");
	}
	return 0;
}

