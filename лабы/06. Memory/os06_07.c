#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sched.h>

int main() {
	pid_t pid = getpid();
    printf("OS05_05 PID %d\n", pid);
    sleep(20);

    void* mem = malloc(1024*1024);
    printf("mem(1024) = %p\n", mem);

    

    int* arr = (int*) mem;

	for(int i = 0; i < 256; i++) {
		arr[i] = i;
	}
	
    sleep(20);
	exit(0);
}