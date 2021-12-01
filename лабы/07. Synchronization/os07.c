#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sched.h>

pthread_mutex_t mx;

void* thread1(void* arg)
{
	for(int i = 0; i < 90; i++) {
		sleep(0.1);
        if (i == 30) 
        {
            pthread_mutex_lock(&mx);
            printf("----------------1\n");
        }
        if (i == 60) 
        {
            pthread_mutex_unlock(&mx);
            printf("----------------1\n");
        }
        printf("child 1:%d\n", i);
	}

    pthread_exit("Child thread");
}

void* thread2(void* arg)
{
	for(int i = 0; i < 90; i++) {
        if (i == 30) 
        {
            pthread_mutex_lock(&mx);
            printf("----------------2\n");
        }
        if (i == 60) 
        {
            pthread_mutex_unlock(&mx);
            printf("----------------2\n");
        }
		sleep(0.1);
        printf("child 2:%d\n", i);
	}

    pthread_exit("Child thread");
}

int main() {

    pthread_mutex_init(&mx, NULL);
    pthread_t a_th1, a_th2;
    void *r_th1, *r_th2;
	pid_t pid = getpid();

    printf("main: pid = %d\n", pid);

    int res1 = pthread_create(&a_th1, NULL, thread1, NULL);
    int res2 = pthread_create(&a_th2, NULL, thread2, NULL);
    void* mem = malloc(1024*1024);

	for(int i = 0; i < 90; i++) {
        if (i == 30) 
        {
            pthread_mutex_lock(&mx);
            printf("----------------main\n");
        }
        if (i == 60) 
        {
            pthread_mutex_unlock(&mx);
            printf("----------------main\n");
        }
        sleep(0.1);
		printf("main:   %d\n", i);
	}
	
    int status1 = pthread_join(a_th1, (void**)&r_th1);
	int status2 = pthread_join(a_th2, (void**)&r_th2);
    pthread_mutex_destroy(&mx);
    exit(0);
}