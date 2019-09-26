#include "monty.h"
/**
 * rotl - rotate stack left
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line_number)
{

	stack_t *node = malloc(sizeof(stack_t));
	stack_t *temp = *stack;
	stack_t *hold;

	if (!node)
	{
		freeall(stack);
		errormsg(4, NULL, line_number);
	}

	if (!(*stack))
		return;

	node->n = temp->n;
	node->next = NULL;
	*stack = (*stack)->next;
	free(temp);

	hold = *stack;

	while (hold->next)
	{
		hold = hold->next;
	}

	hold->next = node;
	node->prev = hold;

}

/**
 * rotr - rotate stack left
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: void
 */



void rotr(stack_t **stack, unsigned int line_number)
{

	stack_t *node = malloc(sizeof(stack_t));
	stack_t *temp = *stack;

	if (!node)
	{
		freeall(stack);
		errormsg(4, NULL, line_number);
	}


	if (!(*stack))
		return;

	while (temp->next)
	{
		temp = temp->next;
	}

	node->n = temp->n;
	node->prev = NULL;
	temp->prev->next = NULL;
	free(temp);

	node->next = (*stack);
	(*stack)->prev = node;
	(*stack) = node;


}

