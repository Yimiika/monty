#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void push(stack_t **stack, unsigned int line_number)
{
    // Check if argument is provided
    if (!stack || !line_number)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Parse the argument
    char *arg = strtok(NULL, " \t\n");
    if (!arg || !isdigit(arg[0]) && arg[0] != '-')
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int num = atoi(arg);

    // Create a new stack node
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Prints all values in the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; // Unused parameter

    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
