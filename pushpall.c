#include "monty.h"

/**
 * push - push command
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: none
 */

void push(stack_t **stack, unsigned int line_number)
{

	/*      if (!stack)*/
	int num;

	stack_t *new_node = malloc(sizeof(stack_t));

	char *token = strtok(global.args, " \t");

	token = strtok(NULL, " \t");

	if (!new_node)
	{
		freeall(stack);
		errormsg(4, NULL, line_number);
	}

	if (!token || isnum(token) == -1)
	{
		free(new_node);
		freeall(stack);
		errormsg(3, NULL, line_number);
	}

	num = atoi(token);

	new_node->prev = NULL;
	new_node->n = num;

	if (!(*stack))
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		new_node->next->prev = new_node;
		(*stack) = new_node;
	}
}

/**
 * pall - pall command
 * @stack: stack_t**
 * @line_number: unsigned int
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;


	if (!temp)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}

/**
 * isnum - check if its all integars
 * @str: char *
 * Return: int
 */


int isnum(char *str)
{

	if (!str)
		return (-1);

	str = strtok(str, "\n");
	while (*str)
	{

		if (isdigit(*str) == 0)
			return (-1);

		str++;
	}

	return (0);
}


/**
 * pint - pint command
 * @stack: stack_t**
 * @line_number: unsigned int
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		freeall(stack);
		errormsg(5, NULL, line_number);
	}

	printf("%d\n", (*stack)->n);

}
