#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <strings.h>

globe global = {NULL, NULL};

/**
 * main-main function
 * @argc: int
 * @argv: char *[]
 * Return: int
 */


int main(int argc, char *argv[])
{
	if (argc != 2)
		errormsg(1, NULL, 1);

	readfile(argv[1]);

	return (0);
}


/**
 * readfile - open and read file line by file
 * @file: char*
 * Return: none
 */

void readfile(char *file)
{

	char buf[1024];

	unsigned int line_number = 0;
	stack_t *stack = NULL;


	global.file = fopen(file, "r");

	if (!global.file)
		errormsg(2, file, line_number);


	while (1)
	{

		fgets(buf, 1024, global.file);

		if (feof(global.file))
			break;

		if (strcmp(buf, "\n") == 0)
			continue;

		line_number++;

		global.args = strdup(buf);
		global.args = strtok(global.args, "\n");

		parser(buf, line_number, &stack);
		free(global.args);
	}

	freeall(&stack);
}

/**
 * parser - parse with function pointer
 * @str: char *
 * @line_number:unsigned int
 * @stack: stack_t**
 */

void parser(char *str, unsigned int line_number, stack_t **stack)
{

	char *command;
	int i;

	instruction_t op[] = {
		{"push", push},	{"pall", pall},
		{"pint", pint},	{"pop", pop},
		{"swap", swap},	{"add", add},
		{"sub", sub}, {"mul", mul},
		{"div", divi}, {"mod", mod},
		{"nop", nop}, {"pchar", pchar},
		{"pstr", pstr}, {NULL, NULL}

	};
	command = strtok(str, " \n\t");


	for (i = 0; op[i].opcode != NULL; i++)
	{

		if (strcmp(command, op[i].opcode) == 0)
		{

			op[i].f(stack, line_number);
			return;
		}
		if (strncmp(command, "#", 1) == 0)
		{
			nop(stack, line_number);
			return;
		}
	}
	freeall(stack);
	errormsg(13, command, line_number);
}

/**
 * errormsg - prints error message
 * @x: int
 * @str: char*
 * @line_number: unsigned int
 * Return: none
 */

void errormsg(int x, char *str, unsigned int line_number)
{
	if (x == 1)
		fprintf(stderr, "USAGE: monty file\n");
	else if (x == 2)
		fprintf(stderr, "Error: Can't open file %s\n", str);
	else if (x == 3)
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
	else if (x == 4)
		fprintf(stderr, "Error: malloc failed\n");
	else if (x == 5)
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	else if (x == 6)
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	else if (x == 7)
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	else if (x == 8)
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	else if (x == 9)
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	else if (x == 9)
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	else if (x == 10)
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	else if (x == 11)
		fprintf(stderr, "L%u: division by zero\n", line_number);
	else if (x == 12)
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
	else if (x == 13)
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
	else if (x == 14)
		fprintf(stderr, "l%u: can't pchar, stack empty\n", line_number);
	else if (x == 15)
		fprintf(stderr, "l%u: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
}
