#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_func(void *);

int main(int argc, char ** argv)
{
	pthread_attr_t attr;
	pthread_t thread;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&thread, &attr, &thread_func,NULL);
	pthread_attr_destroy(&attr);
	
	puts("Main function..");
	
	return EXIT_SUCCESS;
}
void *thread_func(void *thread_arg)
{
	printf("Detatched thread\n");
	return NULL;
}
