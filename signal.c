#include "shell.h"

/**
  *int _isupper - function to 
  *@
  *Return: Always 0 (Success)
  */

void signals(void)
{
	signal(SIGINT, sig_int);
}

void sig_int(int sign)
{
	if (sign == SIGINT)
		{
			show_print("\nCtrl+C is to be pressed. To exit, type 'exit'. ");
			show_display();
			fflush(stdout);
		}
}
