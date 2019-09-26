#include "monty.h"

/**
 * add - add 2 numbers
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;

	if (!temp || !(temp->next))
	{
		freeall(stack);
		errormsg(8, NULL, line_number);
	}

	sum = temp->n + temp->next->n;

	(*stack) = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
	(*stack)->n = sum;


}

/**
 * sub - sub 2 numbers
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: void
 */


void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int dif;

	if (!temp || !(temp->next))
	{
		freeall(stack);
		errormsg(9, NULL, line_number);
	}

	dif = temp->next->n - temp->n;

	(*stack) = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
	(*stack)->n = dif;


}


/**
 * mul - mul 2 numbers
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: void
 */


void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int prod;

	if (!temp || !(temp->next))
	{
		freeall(stack);
		errormsg(10, NULL, line_number);
	}

	prod = temp->n * temp->next->n;

	(*stack) = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
	(*stack)->n = prod;


}

/**
 * divi - divi 2 numbers
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: void
 */





void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int quo;

	if (!temp || !(temp->next))
	{
		freeall(stack);
		errormsg(9, NULL, line_number);
	}

	if (temp->n == 0)
	{
		freeall(stack);
		errormsg(11, NULL, line_number);
	}

	quo =  temp->next->n / temp->n;

	(*stack) = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
	(*stack)->n = quo;


}
/**
 * mod - mod 2 numbers
 * @stack: stack_t
 * @line_number: unsigned int
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mod;

	if (!temp || !(temp->next))
	{
		freeall(stack);
		errormsg(12, NULL, line_number);
	}

	if (temp->n == 0)
	{
		freeall(stack);
		errormsg(11, NULL, line_number);
	}

	mod = temp->next->n % temp->n;

	(*stack) = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
	(*stack)->n = mod;


}
