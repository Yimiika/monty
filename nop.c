#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
