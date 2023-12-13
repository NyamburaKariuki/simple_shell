#include "shell.h"
/**
  *show_print - function to print to the standard output
  *@context: message to print
  *Return: Always 0 (Success)
  */
void show_print(const char *context, ...)
{
	va_list args;

	va_start(args, context);
	fprintf(stderr, "./shell: ");
	vfprintf(stderr, context, args);
	va_end(args);
}


