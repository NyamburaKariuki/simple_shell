#include "shell.h"

/**
  *signals - function to andle signals
  *Return: Always 0 (Success)
  */

void signals(void)
{
	signal(SIGINT, sig_int);
}
/**
  *sig_int - function to return to the prompt
  *@sign: integer
  *Return: Always 0 (Success)
  */
void sig_int(int sign)
{
	if (sign == SIGINT)
	{
	show_print("\nCtrl+C is to be pressed. To exit, type 'exit'. ");
	show_display();
	fflush(stdout);
	}
}
