#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct
{
  char character;
  int count;
} params;

/* Compute successive prime numbers (very inefficiently). Return the
Nth prime number, where N is the value pointed to by *ARG. */
void *compute_prime (void *);

int main (int argc, char **argv)
{

  pthread_t thread_id;
  int which_prime = 5000,prime;
  int tmp = which_prime;

 /* Start the computing thread, up to the 5,000th prime number. */
  pthread_create (&thread_id, NULL, &compute_prime, &tmp);

  /* Make sure the thread has finished. */
  pthread_join (thread_id, (void *)&prime);
  printf("The %dth prime number is %d.\n",which_prime,prime);
  return EXIT_SUCCESS;
}

void * compute_prime (void *parameters)
{
	int candidate = 2;
	int n  = *((int *) parameters);
	
	while(1)
	{
		int factor;
		int is_prime = 1;
		
		for(factor = 2; factor < candidate;factor++)
		{
			if(candidate % factor == 0)
			{
				is_prime = 0;
				break;
			}
		}
		
		if(is_prime){
			if(--n == 0)
			{
				return (void *)candidate;
			}
		}
		candidate++;
	}
	return NULL;
}
