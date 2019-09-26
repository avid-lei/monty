#include "monty.h"

/**
 * sta - stack mode
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: none
 */

void sta(stack_t **stack, unsigned int line_number)
{
	global.mode = 0;

	(void)stack;
	(void)line_number;

}

/**
 * que - que mode
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: none
 */


void que(stack_t **stack, unsigned int line_number)
{

	global.mode = -1;

	(void)stack;
	(void)line_number;


}

/**
 * quepush - push in que mode
 * @stack: stack_t
 * @line_number: unsigned int
 * @token: char *
 * Return: none
 */


void quepush(stack_t **stack, unsigned int line_number, char *token)
{
	int num;

	stack_t *temp = *stack;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		free(new_node);
		freeall(stack);
		errormsg(4, NULL, line_number);
	}


	if (!token || isnum(token) == -1)
	{
		free(new_node);
		freeall(stack);
		errormsg(4, NULL, line_number);
	}

	num = atoi(token);
	new_node->next = NULL;
	new_node->n = num;

	if (!(*stack))
	{
		new_node->prev = NULL;
		(*stack) = new_node;

	}
	else
	{
		while (temp->next)
		{
			temp = temp->next;
		}

		temp->next = new_node;
		new_node->prev = temp;
	}
}

