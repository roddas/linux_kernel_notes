#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

/* An array of balances in accounts, indexed by account number */
double *account_balances = NULL;

/* Transfers an amount from account FROM to account TO. Return 0 if succeded
 * or 1 if the balance FROM is too small */
int process_transaction(int, int, double);

int main(int argc, char ** argv)
{

	
	return EXIT_SUCCESS;
}

int process_transaction(int from, int to, double amount)
{
	int old_cancel_state;
	
	/* Check the balance in FROM */
	if(account_balances[from] < amount)
		return 1;
	
	/* Begin critical section. */
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);
	/* Move the money */
	account_balances[to] += amount;
	account_balances[from] -= amount;
	/* End critical section */
	pthread_setcancelstate(old_cancel_state, NULL);
	
	return 0;
}
