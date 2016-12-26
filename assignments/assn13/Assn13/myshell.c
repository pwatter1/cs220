#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	char line[1024];
	int pid, i, count = 0;
	char *args[] = {&line, 0};
	
	while(1)
	{
		printf("Hello!!> ");

		if(!fgets(line, 1023, stdin))	break;
		
		/* if more than two commands, dont execute */
		for(i = 0; i < strlen(line); i++)
		{ 
			if(line[i] == '&') count++;
		}
		if(count > 2){
			count = 0;
			continue;
		}
		
		if(strcmp(line, "exit\n") == 0){
			break;
		} else {
			system(line);
			continue;
		}
		
		for(i = 0; i < strlen(line); i++){
			if(line[i] == '\n') line[i] = '\0';
		}
		
		pid = fork();
		if(pid == 0){ /* child process */
			execvp(line, args);
			fprintf(stderr, "Hello!!: %s\n", strerror(errno));
			exit(errno);
		} else {
			wait(NULL);
		}
	}
	return 0;
}
