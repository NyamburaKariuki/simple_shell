#include "shell.h"

/**
 * print_c - function to print character
 * @c: character to print
 * Return: 1 on success, -1 otherwise
 */
int print_c(char c)
{
	return (write(1, &c, 1));
}
