#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	pid_t pid1 = fork();
	if(pid1 == 0){
		printf(" I'm process 1. My PID is %d. My parent is main process - %d\n", getpid(), getppid());
		pid_t pid3 = fork();
		if(pid3 == 0){
			printf(" I'm process 3. My PID is %d. My parent is process 1 with PID %d\n", getpid(), getppid());
			exit(0);
		}
		exit(0);
	}

	sleep(1);
	pid_t pid2 = fork();
	if(pid2 == 0){
		printf(" I'm process 2. My PID is %d. My parent is main process - %d\n", getpid(), getppid());
		pid_t pid4 = fork();
		if(pid4 == 0){
			printf(" I'm process 4. My PID is %d. My parent is process 2 with PID %d\n", getpid(), getppid());
			exit(0);
		}
		pid_t pid5 = fork();
		if(pid5 == 0){
			printf(" I'm process 5. My PID is %d. My parent is process 2 with PID %d\n", getpid(), getppid());
			exit(0);
		}
		exit(0);
	}
	
	getchar();
	return 0;
}
