#include "shell.h"
/**
  *show_print - function to print to the standard output
  *@context: message to print
  *Return: Always 0 (Success)
  */
void show_print(const char *context)
{
	write(STDOUT_FILENO, context, strlen(context));
}


