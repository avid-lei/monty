#include "monty.h"

/**
 * pop - pop top element
 * @stack: stack_t
 * @line_number: int
 * Return: none
 */

void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = *stack;

	if (!(*stack))
	{
		freeall(stack);
		errormsg(6, NULL, line_number);
	}

	if ((*stack)->next)
	{

		(*stack) = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
	}
	else
	{
		free(temp);
		*stack = NULL;
	}

}

/**
 * swap - swap top element
 * @stack: stack_t
 * @line_number: int
 * Return: none
 */


void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int hold;

	if (!temp || !(temp->next))
	{
		freeall(stack);
		errormsg(7, NULL, line_number);
	}

	hold = temp->n;
	temp->n = temp->next->n;
	temp->next->n = hold;


}

/**
 * nop - do nothing
 * @stack: stack_t
 * @line_number: int
 * Return: none
 */


void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}

/**
 * pchar - print character
 * @stack: stack_t
 * @line_number: int
 * Return: none
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !stack)
	{
		freeall(stack);
		errormsg(14, NULL, line_number);
	}

	if (temp->n < 1 || temp->n > 127)
	{
		freeall(stack);
		errormsg(15, NULL, line_number);
	}

	printf("%c\n", temp->n);
}


/**
 * pstr - print character
 * @stack: stack_t
 * @line_number: int
 * Return: none
 */
void pstr(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = *stack;

	(void)line_number;

	if ((*stack))
	{
		while (temp->next && temp->n != 0)
		{
			if (temp->n > 1 && temp->n < 127)
			{
				printf("%c", temp->n);

			}
			temp = temp->next;

		}
		putchar('\n');
	}
	else
		putchar('\n');
}



