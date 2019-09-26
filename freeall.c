#include "monty.h"

/**
 * freeall - free list and global
 * @stack: stack_t
 * Return: void
 */

void freeall(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		(*stack) = (*stack)->next;
		free(temp);
		temp = *stack;

	}



	fclose(global.file);
}
